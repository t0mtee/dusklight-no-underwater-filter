#include "mods/service.hpp"
#include "mods/svc/hook.h"
#include "mods/svc/hook.hpp"

// Game includes
#include "d/d_kankyo.h"

DEFINE_MOD();

IMPORT_SERVICE(HookService, svc_hook);

DEFINE_HOOK(dKy_undwater_filter_draw, UnderwaterFilterDraw);

extern "C"
{
    void underwater_filter_draw_replace(ModContext*, void* args, void* retval, void*) { return; }

    MOD_EXPORT ModResult mod_initialize(ModError*)
    {
        ModResult result = mods::hook::replace<UnderwaterFilterDraw>(underwater_filter_draw_replace);
        if (result != MOD_OK)
        {
            return result;
        }

        return MOD_OK;
    }

    MOD_EXPORT ModResult mod_update(ModError*) { return MOD_OK; }

    MOD_EXPORT ModResult mod_shutdown(ModError*) { return MOD_OK; }
}
