#ifndef GENTITY_H
#define GENTITY_H

#include "gincu/ecs/gentitypolicy.h"

#include "cpgf/gcallbacklist.h"

#include <memory>
#include <vector>

namespace gincu {

class GComponent;
class GComponentManager;

enum class GEntityEventType
{
	componentAdded,
	componentRemoving
};

class GEntity : public EntityBase
{
public:
	typedef cpgf::GCallback<void (GComponent *, GEntityEventType)> EventCallback;

public:
	void * operator new (const std::size_t size);
	void operator delete(void * p);

	GEntity();
	~GEntity();

	GEntity(const GEntity &) = delete;
	GEntity & operator = (const GEntity &) = delete;

	GEntity * addComponent(GComponent * component);
	void removeComponent(GComponent * component);
	
	void addEventCallback(const EventCallback & callback);
	void removeEventCallback(const EventCallback & callback);
	
	void setComponentManager(GComponentManager * componentManager);
	GComponentManager * getComponentManager() const { return this->componentManager; }

	GComponent * getComponentByTypeId(const GComponentType typeId) const;
	
	template <typename T>
	T * getComponentByType() const {
		return static_cast<T *>(this->getComponentByTypeId(T::getComponentType()));
	}
	
private:
	GComponentManager * componentManager;
	cpgf::GCallbackList<void (GComponent *, GEntityEventType)> eventCallbackList;
};


} //namespace gincu

#endif