#include "Resource.h"

Resource::Resource(std::string_view name, Type type)
    : name(name), isAvailable(true), resourceType(type) {}

std::string_view Resource::getName() const { return name; }


Type Resource::getType() const { return resourceType; }