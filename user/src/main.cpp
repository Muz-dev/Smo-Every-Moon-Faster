#include <mallow/config.hpp>
#include <mallow/mallow.hpp>

#include "ActorFactory/actorPatches.h"

#include "Library/Nerve/NerveUtil.h"
#include "Library/LiveActor/LiveActor.h"
#include "Player/PlayerConst.h"
#include "Player/PlayerActorHakoniwa.h"
#include "Library/Player/PlayerUtil.h"

namespace al{
LiveActor* getPlayerActor(const LiveActor*, int);
}


/*
static void setupLogging() {
    using namespace mallow::log::sink;
    // This sink writes to a file on the SD card.
    static FileSink fileSink = FileSink("sd:/mallow.log");
    addLogSink(&fileSink);

    // This sink writes to a network socket on a host computer. Raw logs are sent with no
    auto config = mallow::config::getConfig();
    if (config["logger"]["ip"].is<const char*>()) {
        static NetworkSink networkSink = NetworkSink(
            config["logger"]["ip"],
            config["logger"]["port"] | 3080
        );
        if (networkSink.isSuccessfullyConnected())
            addLogSink(&networkSink);
        else
            mallow::log::logLine("Failed to connect to the network sink");
    } else {
        mallow::log::logLine("The network logger is unconfigured.");
        if (config["logger"].isNull()) {
            mallow::log::logLine("Please configure the logger in config.json");
        } else if (!config["logger"]["ip"].is<const char*>()) {
            mallow::log::logLine("The IP address is missing or invalid.");
        }
    }
}

using mallow::log::logLine;

//Mod code

struct nnMainHook : public mallow::hook::Trampoline<nnMainHook>{
    static void Callback(){
        nn::fs::MountSdCardForDebug("sd");
        mallow::config::loadConfig(true);

        setupLogging();
        logLine("Hello from smo!");
        Orig();
    }
};
*/
float maxwalkspeed{2.0f};
float maxrollspeed{5.0f};
float maxrollboost{4.0f};
float maxrollstart{3.0f};
float maxjumpspeed{20.f};
float maxjumpmovespeed{4.0f};
float maxlongjumpinitmove{2.0f};
float maxlongjumpspeed{3.0f};
float waterdivespeed{3.0f};
float twodmovespeed{1.0f};
float divemovespeed{1.5f};
float runspeedmax{2.0f};
float waterswimupspeed{1.0f};
float swimfallspeed{1.0f};
float waterfloorspeedvar{1.0f};
float swimhighval{1.0f};
float swimlowval{1.0f};
float swimwalkspeed{0.9f};
float swimsurfacespeed{1.2f};
float sprintingvalue{3.0f};
float crouchmovespeedval{0.5};



struct sprintinghook : public exl::hook::impl::ReplaceHook<sprintinghook>{
    static float Callback(){
        return sprintingvalue;
    }
};

struct swimsurface : public exl::hook::impl::ReplaceHook<swimsurface>{
    static float Callback(){
        return swimsurfacespeed;
    }
};

struct swimwalk : public exl::hook::impl::ReplaceHook<swimwalk>{
    static float Callback(){
        return swimwalkspeed;
    }
};

struct swimlow : public exl::hook::impl::ReplaceHook<swimlow>{
    static float Callback(){
        return swimlowval;
    }
};

struct swimhigh : public exl::hook::impl::ReplaceHook<swimhigh>{
    static float Callback(){
        return swimhighval;
    }
};

struct waterfloorspeed : public exl::hook::impl::ReplaceHook<waterfloorspeed>{
    static float Callback(){
        return waterfloorspeedvar;
    }
};

struct waterfall : public exl::hook::impl::ReplaceHook<waterfall>{
    static float Callback(){
        return swimfallspeed;
    }
};


struct waterswimup : public exl::hook::impl::ReplaceHook<waterswimup>{
    static float Callback(){
        return waterswimupspeed;
    }
};


struct waterdivedownspeedhook : public exl::hook::impl::ReplaceHook<waterdivedownspeedhook>{
    static float Callback(){
        return waterdivespeed;
    }
};


struct divepowermax : public exl::hook::impl::ReplaceHook<divepowermax>{
    static float Callback(){
        return divemovespeed;
    }
};

struct twodmovespeedhook : public exl::hook::impl::ReplaceHook<twodmovespeedhook>{
    static float Callback(){
        return twodmovespeed;
    }
};


struct longjumpspeed : public exl::hook::impl::ReplaceHook<longjumpspeed>{
    static float Callback(){
        return maxlongjumpspeed;
    }
};

struct longjumpspeedinit : public exl::hook::impl::ReplaceHook<longjumpspeedinit>{
    static float Callback(){
        return maxlongjumpinitmove;
    }
};

struct jumpspeedmovehook : public exl::hook::impl::ReplaceHook<jumpspeedmovehook>{
    static float Callback(){
        return maxjumpmovespeed;
    }
};


struct jumpspeedhook : public exl::hook::impl::ReplaceHook<jumpspeedhook>{
    static float Callback(){
        return maxjumpspeed;
    }
};

struct rollstarthook : public exl::hook::impl::ReplaceHook<rollstarthook>{
    static float Callback(){
        return maxrollstart;
    }
};

struct rollboosthook : public exl::hook::impl::ReplaceHook<rollboosthook>{
    static float Callback(){
        return maxrollboost;
    }
};

struct rollspeedhook : public exl::hook::impl::ReplaceHook<rollspeedhook>{
    static float Callback(){
        return maxrollspeed;
    }
};

struct walkspeedhook : public exl::hook::impl::ReplaceHook<walkspeedhook>{
    static float Callback(){
        return maxwalkspeed;
    }
};

struct runspeedhook : public exl::hook::impl::ReplaceHook<runspeedhook>{
    static float Callback(){
        return runspeedmax;
    }
};

struct crouchmovehook : public exl::hook::impl::ReplaceHook<crouchmovehook>{
    static float Callback(){
        return crouchmovespeedval;
    }
};


struct getmoonhook : public mallow::hook::Trampoline<getmoonhook>{
  static void Callback(al::LiveActor* thisPtr){
        if (al::isFirstStep(thisPtr)) {
            maxwalkspeed += 1.5f;
            maxrollspeed += 1.5f;
            maxrollboost += 1.5f;
            maxrollstart += 1.5f;
            maxjumpmovespeed += 1.5f;
            maxjumpspeed += 1.5f;
            maxlongjumpinitmove += 1.5f;
            maxlongjumpspeed += 1.5f;
            twodmovespeed += 1.0f;
            divemovespeed += 3.0f;
            waterdivespeed += 3.0f;
            waterswimupspeed += 3.0f;
            swimfallspeed += 3.0f;
            waterfloorspeedvar += 3.0f;
            swimhighval += 3.0f;
            swimlowval += 3.0f;
            swimwalkspeed += 3.0f;
            swimsurfacespeed += 3.0f;
            crouchmovespeedval += 3.0f;
        }
        Orig(thisPtr);
  }
};



extern "C" void userMain() {
    exl::hook::Initialize();
    crouchmovehook::InstallAtSymbol("_ZNK11PlayerConst17getSquatWalkSpeedEv");
    sprintinghook::InstallAtSymbol("_ZNK11PlayerConst22getDashFastBorderSpeedEv");
    swimsurface::InstallAtSymbol("_ZNK11PlayerConst23getSwimSurfaceSpeedMaxHEv");
    swimwalk::InstallAtSymbol("_ZNK11PlayerConst19getSwimWalkMaxSpeedEv");
    swimlow::InstallAtSymbol("_ZNK11PlayerConst19getSwimLowSpeedMaxHEv");
    swimhigh::InstallAtSymbol("_ZNK11PlayerConst20getSwimHighSpeedMaxHEv");
    waterfloorspeed::InstallAtSymbol("_ZNK11PlayerConst21getSwimFloorSpeedMaxHEv");
    waterfall::InstallAtSymbol("_ZNK11PlayerConst19getSwimFallSpeedMaxEv");
    waterswimup::InstallAtSymbol("_ZNK11PlayerConst19getSwimRiseSpeedMaxEv");
    runspeedhook::InstallAtSymbol("_ZNK11PlayerConst29getRunSpeedMaxContinuousThrowEv");
    divepowermax::InstallAtSymbol("_ZNK11PlayerConst19getDiveTramplePowerEv");
    twodmovespeedhook::InstallAtSymbol("_ZNK11PlayerConst19getNormalMaxSpeed2DEv");
    waterdivedownspeedhook::InstallAtSymbol("_ZNK11PlayerConst21getSwimDiveStartSpeedEv");
    longjumpspeed::InstallAtSymbol("_ZNK11PlayerConst16getLongJumpSpeedEv");
    longjumpspeedinit::InstallAtSymbol("_ZNK11PlayerConst20getLongJumpInitSpeedEv");
    jumpspeedmovehook::InstallAtSymbol("_ZNK11PlayerConst19getJumpMoveSpeedMaxEv");
    jumpspeedhook::InstallAtSymbol("_ZNK11PlayerConst19getJumpBaseSpeedMaxEv");
    rollstarthook::InstallAtSymbol("_ZNK11PlayerConst25getSlopeRollingSpeedStartEv");
    rollboosthook::InstallAtSymbol("_ZNK11PlayerConst25getSlopeRollingSpeedBoostEv");
    rollspeedhook::InstallAtSymbol("_ZNK11PlayerConst23getSlopeRollingMaxSpeedEv");
    getmoonhook::InstallAtSymbol("_ZN5Shine6exeGotEv");
    walkspeedhook::InstallAtSymbol("_ZNK11PlayerConst17getNormalMaxSpeedEv");
    nnMainHook::InstallAtSymbol("nnMain");
    ca::actorPatches();
};