//
// Created by Loudbook on 9/29/24.
//


#include "../include/json_loader.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

using json = nlohmann::json;

JsonLoader::JsonLoader(const std::string &filePath) {
    if (std::ifstream file(filePath); !file.is_open()) {
        std::filesystem::path dir = std::filesystem::path(filePath).parent_path();
        if (!std::filesystem::exists(dir)) {

            std::filesystem::create_directories(dir);
            std::cerr << "Created directories: " << dir << std::endl;
        }

        std::ofstream outFile(filePath);

        if (!outFile.is_open()) {
            std::cerr << "Error opening file: " << filePath << std::endl;
            std::cerr << "Reason: " << std::strerror(errno) << std::endl;
            std::filesystem::create_directories(dir);
            return;
        }

        json jsonObject;
        jsonObject["refreshInterval"] = 10;
        jsonObject["messages"] = json::array({ "Hey. I'm a MOTD message.", "Loudbook was here.", "What's going on?" });

        outFile << jsonObject.dump(4) << std::endl;
        outFile.close();

        std::cerr << "File created: " << filePath << " with default values." << std::endl;
    } else {
        json jsonData;
        file >> jsonData;

        refreshInterval = jsonData["refreshInterval"];

        for (const auto& message : jsonData["messages"]) {
            stringList.push_back(message);
        }

        file.close();
    }
}

const std::vector<std::string>& JsonLoader::getStringList() const {
    return stringList;
}

int JsonLoader::getRefreshInterval() const {
    return refreshInterval;
}