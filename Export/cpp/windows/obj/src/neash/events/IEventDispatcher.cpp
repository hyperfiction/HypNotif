#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
namespace neash{
namespace events{

HX_DEFINE_DYNAMIC_FUNC5(IEventDispatcher_obj,addEventListener,)

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,dispatchEvent,return )

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,hasEventListener,return )

HX_DEFINE_DYNAMIC_FUNC3(IEventDispatcher_obj,removeEventListener,)

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,willTrigger,return )


Class IEventDispatcher_obj::__mClass;

void IEventDispatcher_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.events.IEventDispatcher"), hx::TCanCast< IEventDispatcher_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace neash
} // end namespace events
