#include "action.h"

static const struct button_mapping button_context_standard[] =
{
    { ACTION_STD_PREV,           BUTTON_PREV,                        BUTTON_NONE },
    { ACTION_STD_PREVREPEAT,     BUTTON_PREV|BUTTON_REPEAT,          BUTTON_NONE },
    { ACTION_STD_NEXT,           BUTTON_NEXT,                        BUTTON_NONE },
    { ACTION_STD_NEXTREPEAT,     BUTTON_NEXT|BUTTON_REPEAT,          BUTTON_NONE },
    { ACTION_STD_OK,             BUTTON_PLAY|BUTTON_REL,             BUTTON_PLAY },
    { ACTION_STD_CONTEXT,        BUTTON_PLAY|BUTTON_REPEAT,          BUTTON_PLAY },
    { ACTION_STD_CANCEL,         BUTTON_POWER|BUTTON_REL,            BUTTON_POWER },
    { ACTION_STD_KEYLOCK,        BUTTON_POWER|BUTTON_REPEAT,         BUTTON_POWER },

    LAST_ITEM_IN_LIST,
};

static const struct button_mapping button_context_wps[] =
{
    { ACTION_WPS_MENU,           BUTTON_POWER|BUTTON_REL,            BUTTON_POWER },
    { ACTION_WPS_PLAY,           BUTTON_PLAY|BUTTON_REL,             BUTTON_PLAY },
    { ACTION_WPS_STOP,           BUTTON_PLAY|BUTTON_REPEAT,          BUTTON_NONE },
    { ACTION_WPS_VOLUP,          BUTTON_SCROLL_FWD,                  BUTTON_NONE },
    { ACTION_WPS_VOLDOWN,        BUTTON_SCROLL_BACK,                 BUTTON_NONE },
    { ACTION_WPS_SKIPNEXT,       BUTTON_NEXT|BUTTON_REL,             BUTTON_NEXT },
    { ACTION_WPS_SKIPPREV,       BUTTON_PREV|BUTTON_REL,             BUTTON_PREV },
    { ACTION_WPS_SEEKFWD,        BUTTON_NEXT|BUTTON_REPEAT,          BUTTON_NONE },
    { ACTION_WPS_STOPSEEK,       BUTTON_NEXT|BUTTON_REL,             BUTTON_NEXT|BUTTON_REPEAT },
    { ACTION_WPS_SEEKBACK,       BUTTON_PREV|BUTTON_REPEAT,          BUTTON_NONE },
    { ACTION_WPS_STOPSEEK,       BUTTON_PREV|BUTTON_REL,             BUTTON_PREV|BUTTON_REPEAT },

    LAST_ITEM_IN_LIST,
};

const struct button_mapping* target_get_context_mapping(int context)
{
    switch (context & ~CONTEXT_LOCKED)
    {
        case CONTEXT_STD:                       { return button_context_standard; }
        case CONTEXT_WPS:                       { return button_context_wps; }
        default:                                { return button_context_standard; }
    }
}
