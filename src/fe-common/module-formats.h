/* $Id$ */

#include "formats.h"

enum {
	XMPPTXT_MODULE_NAME,

	XMPPTXT_FILL_1,

	XMPPTXT_ROSTER_GROUP,
	XMPPTXT_ROSTER_JID,
	XMPPTXT_ROSTER_NAME,
	XMPPTXT_ROSTER_RESOURCE,
	XMPPTXT_ROSTER_RESOURCE_SHOW,
	XMPPTXT_ROSTER_RESOURCE_STATUS,
	XMPPTXT_ROSTER_SUBSCRIPTION,
	XMPPTXT_BEGIN_OF_ROSTER,
	XMPPTXT_END_OF_ROSTER,
	XMPPTXT_NOT_IN_ROSTER,

	XMPPTXT_FILL_2,

	XMPPTXT_SUBSCRIBE,
	XMPPTXT_SUBSCRIBED,
	XMPPTXT_UNSUBSCRIBE,
	XMPPTXT_UNSUBSCRIBED,

	XMPPTXT_FILL_3,

	XMPPTXT_MESSAGE_EVENT,
	XMPPTXT_MESSAGE_NOT_DELIVERED,

	XMPPTXT_FILL_4,

	XMPPTXT_QUERY_AKA,

	XMPPTXT_FILL_5,

	XMPPTXT_CHANNEL_JOINERROR,

	XMPPTXT_FILL_6,

	XMPPTXT_PRESENCE_CHANGE,
	XMPPTXT_PRESENCE_CHANGE_REASON,

	XMPPTXT_FILL_7,

	XMPPTXT_DEFAULT_EVENT,
	XMPPTXT_DEFAULT_ERROR
};

extern FORMAT_REC fecommon_xmpp_formats[];
