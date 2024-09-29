//
// Created by Loudbook on 9/29/24.
//

#pragma once
#include <string>
#include <vector>

class JsonLoader {
    std::vector<std::string> stringList;

public:
    explicit JsonLoader(const std::string& filePath);
    [[nodiscard]] const std::vector<std::string>& getStringList() const;
};
