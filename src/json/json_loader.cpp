//
// Created by Loudbook on 9/29/24.
//


#include "../include/json_loader.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

JsonLoader::JsonLoader(const std::string &filePath) {
    if (std::ifstream file(filePath); !file.is_open()) {
        std::ofstream outFile(filePath);

        json defaultData = json::array();
        outFile << json::array({ "Hey. I'm a MOTD message.", "Loudbook was here.", "What's going on?" });
        outFile.close();

        std::cerr << "File created: " << filePath << " with default values." << std::endl;
    } else {
        json jsonData;
        file >> jsonData;

        if (jsonData.is_array()) {
            for (const auto& item : jsonData) {
                stringList.push_back(item.dump());
            }
        }

        file.close();
    }
}

const std::vector<std::string>& JsonLoader::getStringList() const {
    return stringList;
}
