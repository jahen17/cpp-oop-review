#include "Resource.h"

/**
 * @brief Constructor for the Resource with the given name and type.
 * @param name Unique name of the resource.
 * @param type Type of the resource (Consumable or Usable).
 */
Resource::Resource(std::string_view name, Type type)
    : name(name), isAvailable(true), resourceType(type) {}

/**
 * @brief Returns the name of the resource.
 *
 * @return A non-owning view of the resource's name.
 */
std::string_view Resource::getName() const { return name; }

/**
 * @brief Retrieves the type of the resource.
 *
 * @return The type of the resource (Consumable or Usable).
 */
Type Resource::getResourceType() const { return resourceType; }