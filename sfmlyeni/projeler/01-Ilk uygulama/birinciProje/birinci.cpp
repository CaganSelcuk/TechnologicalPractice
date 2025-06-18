#include <iostream>
#include <optional>

std::optional<int> getAge(bool known) {
    if (known)
        return 30;
    else
        return std::nullopt;
}

int main() {
    auto age = getAge(false);
    if (age)
        std::cout << "???????: " << *age << std::endl;
    else
        std::cout << "??????? ??????????" << std::endl;

    std::cin.get();
    return 0;
}
