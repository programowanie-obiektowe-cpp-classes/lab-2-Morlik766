#pragma once
#include "Resource.hpp"
#include <memory>

class ResourceManager
{
public:
    ResourceManager() : resource(std::make_unique< Resource >()) {}
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    double get() const { return resource->get(); }

private:
    std::unique_ptr< Resource > resource;
};
