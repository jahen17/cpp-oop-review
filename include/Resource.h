#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <string_view>

/**
 *
 */
class Resource {
public:
    enum class Type { Consumable, Usable};

protected:
    std::string name;
    bool isAvailable;
    Type resourceType;

public:
    Resource (std::string_view name, Type type);
    virtual ~Resource() = default;
    [[ndiscard]] std::string_view getName() const;
    [[nodiscard]] bool isAvailableForUse() const = 0;
    virtual void allocate()=0;
    virtual void release()=0;
    virtual void use () const = 0;
    [[nodiscard]] virtual std::string describeUsage() const = 0;
    [[nodiscard]] Type gestResourceType() const;

};

#endif //RESOURCE_H