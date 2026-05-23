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

const struct button_mapping* target_get_context_mapping(int context)
{
    // TODO: Implement all mappings
    return button_context_standard;
}
