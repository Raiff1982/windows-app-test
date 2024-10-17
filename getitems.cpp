#include "pch.h"
#include "getitems.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>

static void installSoftware(const std::string& packageName) {
    std::string command = "winget install " + packageName;
    system(command.c_str());
}

std::map<std::string, std::string> createMapping() {
    std::map<std::string, std::string> mapping;
    mapping["python"] = "Python.Python.3";
    mapping["visual studio code"] = "Microsoft.VisualStudioCode";
    mapping["git"] = "Git.Git";
    mapping["node.js"] = "OpenJS.NodeJS";
    mapping["docker"] = "Docker.DockerDesktop";
    mapping["java"] = "Oracle.JavaRuntimeEnvironment";
    mapping["notepad++"] = "Notepad++.Notepad++";
    return mapping;
}

std::vector<std::string> searchPackages(const std::string& query, const std::map<std::string, std::string>& mapping) {
    std::vector<std::string> matches;
    for (const auto& pair : mapping) {
        if (pair.first.find(query) != std::string::npos) {
            matches.push_back(pair.second);
        }
    }
    return matches;
}

void handleQuery(const std::vector<std::string>& queries, const std::map<std::string, std::string>& mapping) {
    for (const auto& query : queries) {
        auto matches = searchPackages(query, mapping);
        if (!matches.empty()) {
            installSoftware(matches[0]);
            std::cout << "Success: Installed " << matches[0] << std::endl;
        }
        else {
            std::cout << "Error: Package not found" << std::endl;
        }
    }
}
