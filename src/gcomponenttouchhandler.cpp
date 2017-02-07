#include "gincu/gcomponenttouchhandler.h"
#include "gincu/gcomponentrender.h"
#include "gincu/gcomponenttransform.h"
#include "gincu/gentity.h"
#include "gincu/gentityutil.h"
#include "gincu/gutil.h"
#include "gincu/grenderanchor.h"

namespace gincu {

GComponentTouchHandler::GComponentTouchHandler()
	: super(this)
{
}

GComponentTouchHandler * GComponentTouchHandler::addOnTouch(const GComponentTouchHandler::OnTouched & onTouch)
{
	onTouchedList.add(onTouch);
	
	return this;
}

void GComponentTouchHandler::removeOnTouch(const GComponentTouchHandler::OnTouched & onTouch)
{
	onTouchedList.remove(onTouch);
}

bool GComponentTouchHandler::canHandle(const GPoint & point) const
{
	return doCanHandle(point);
}

void GComponentTouchHandler::handle(const GTouchEvent & touchEvent)
{
	OnTouchedList tempOnTouchedList = onTouchedList;
	tempOnTouchedList(touchEvent);
}


GComponentRendererTouchHandler::GComponentRendererTouchHandler()
{
}

bool GComponentRendererTouchHandler::doCanHandle(const GPoint & point) const
{
	GComponentTransform * transform = getEntity()->getComponentByType<GComponentTransform>();
	if(! transform->isVisible()) {
		return false;
	}

	const GTransform t = computeRenderableTransform(transform);
	const GSize size = getEntity()->getComponentByType<GComponentRender>()->getSize();
	const sf::Transform & sfmlTransform = t.getSfmlTransform();
	auto normalizedRect = sfmlTransform.transformRect({ 0, 0, size.width, size.height });
	
	return isWithin(point.x, normalizedRect.left, normalizedRect.left + normalizedRect.width)
		&& isWithin(point.y, normalizedRect.top, normalizedRect.top + normalizedRect.height)
	;
}


} //namespace gincu