#ifndef GETITEMS_H
#define GETITEMS_H

#include <string>
#include <vector>
#include <map>

void installSoftware(const std::string& packageName);
std::map<std::string, std::string> createMapping();
std::vector<std::string> searchPackages(const std::string& query, const std::map<std::string, std::string>& mapping);
void handleQuery(const std::vector<std::string>& queries, const std::map<std::string, std::string>& mapping);

#endif // GETITEMS_H
