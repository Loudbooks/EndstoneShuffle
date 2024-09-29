//
// Created by Loudbook on 9/29/24.
//

#pragma once

#include <random>
#include <endstone/plugin/plugin.h>
#include <endstone/event/server/server_list_ping_event.h>

#include "json_loader.h"

class EndstoneShuffle : public endstone::Plugin {
public:
    EndstoneShuffle() : loader(JsonLoader("./EndstoneShuffle/messages.json")), gen(rd()) {}

    void onLoad() override {
        registerEvent(&EndstoneShuffle::onServerListPingEvent, *this);
    }

    void onServerListPingEvent(endstone::ServerListPingEvent& event) {
        event.setMotd(getRandomString(loader.getStringList()));
    }

    std::string getRandomString(const std::vector<std::string>& strings) {
        std::uniform_int_distribution<> distr(0, strings.size() - 1);

        return strings[distr(gen)];
    }

private:
    JsonLoader loader;
    std::random_device rd;
    std::mt19937 gen;
};
