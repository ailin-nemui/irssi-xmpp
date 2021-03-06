#include "module.h"
#include <irssi/src/core/levels.h>
#include "module-formats.h"
#include <irssi/src/fe-common/core/printtext.h>
#include <irssi/src/core/settings.h>
#include <irssi/src/core/signals.h>
#include <irssi/src/fe-common/core/window-items.h>
#include <irssi/src/fe-common/core/fe-messages.h>
#include <irssi/src/fe-common/core/fe-queries.h>
#include <irssi/src/fe-common/core/module-formats.h>
#include <irssi/src/fe-common/core/fe-messages.h>
#include <irssi/src/fe-common/irc/module-formats.h>

#include "xmpp-servers.h"
#include "rosters-tools.h"
#include "xep/muc.h"

static void
sig_message_carbons_sent(SERVER_REC *server, const char *msg, const char *nick,
                         const char *target, gpointer gpointer_type)
{
	void *item;
	char *freemsg = NULL;
	int level, type;

	g_return_if_fail(server != NULL);
	g_return_if_fail(msg != NULL);
	g_return_if_fail(nick != NULL);
	g_return_if_fail(target != NULL);

	type = GPOINTER_TO_INT(gpointer_type);
	level = MSGLEVEL_NO_ACT | MSGLEVEL_NOHILIGHT
	    | (type == SEND_TARGET_CHANNEL ? MSGLEVEL_PUBLIC : MSGLEVEL_MSGS);
	item = type == SEND_TARGET_CHANNEL ?
	    (void *)get_muc((XMPP_SERVER_REC *)server, target) :
	    query_find(server, target);

	if (settings_get_bool("emphasis"))
		msg = freemsg = expand_emphasis(item, msg);

	if (type == SEND_TARGET_CHANNEL) {
		char *nickmode = channel_get_nickmode(item, nick);
		printformat_module(CORE_MODULE_NAME, server, target,
		    level, TXT_OWN_MSG_CHANNEL, nick, target, msg, nickmode);
	} else if(item) { // If no query, why do we want to see carbons?
		printformat_module(CORE_MODULE_NAME, server, target,
		    level, TXT_OWN_MSG_PRIVATE_QUERY, target, msg, nick);
	}

	g_free_not_null(freemsg);
}

void
fe_carbons_init(void)
{
	signal_add("message xmpp carbons sent", sig_message_carbons_sent);
}

void
fe_carbons_deinit(void)
{
	signal_remove("message xmpp carbons sent", sig_message_carbons_sent);
}
