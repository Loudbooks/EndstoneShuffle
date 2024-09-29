//
// Created by Loudbook on 9/29/24.
//

#pragma once

#include <random>
#include <endstone/plugin/plugin.h>
#include <endstone/event/server/server_list_ping_event.h>
#include <iostream>

#include "json_loader.h"

class StoneShuffle : public endstone::Plugin {
public:
    StoneShuffle() : loader(JsonLoader(std::filesystem::current_path().string() + "/StoneShuffle/config.json")), currentIndex(0), lastShuffled(0) {}

    void onEnable() override {
        getLogger().info(std::filesystem::current_path().string());
        registerEvent(&StoneShuffle::onServerListPingEvent, *this);
    }

    void onServerListPingEvent(endstone::ServerListPingEvent& event) {
        long milliseconds_since_epoch =
                std::chrono::system_clock::now().time_since_epoch() /
                std::chrono::milliseconds(1);

        long refreshIntervalMilliseconds = loader.getRefreshInterval() * 1000;

        if (lastShuffled + refreshIntervalMilliseconds < milliseconds_since_epoch) {
            lastShuffled = milliseconds_since_epoch;

            if (currentIndex >= loader.getStringList().size()) {
                currentIndex = 0;
            } else {
                currentIndex++;
            }
        }

        event.setMotd(loader.getStringList()[currentIndex]);
    }

private:
    JsonLoader loader;

    int currentIndex;
    long lastShuffled;
};
