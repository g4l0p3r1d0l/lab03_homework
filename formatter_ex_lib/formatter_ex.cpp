#include "formatter_ex.h"
#include "formatter.h"

std::string format_ex(const std::string& s) {
    return format(s) + " [EXTRA]";
}
