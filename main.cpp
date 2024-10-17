#include "pch.h"
#include "getitems.h"
#include <vector>
#include <string>

int main() {
    std::vector<std::string> queries = { "python", "visual studio code", "node.js" };
    auto mapping = createMapping();
    handleQuery(queries, mapping);
    return 0;
}
//