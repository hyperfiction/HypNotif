#ifndef INCLUDED_org_shoebox_collections_PrioQueueIterator
#define INCLUDED_org_shoebox_collections_PrioQueueIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(org,shoebox,collections,PrioQueueIterator)
namespace org{
namespace shoebox{
namespace collections{


class PrioQueueIterator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PrioQueueIterator_obj OBJ_;
		PrioQueueIterator_obj();
		Void __construct(Dynamic content);

	public:
		static hx::ObjectPtr< PrioQueueIterator_obj > __new(Dynamic content);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PrioQueueIterator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PrioQueueIterator"); }

		int inc; /* REM */ 
		Dynamic _aContent; /* REM */ 
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual bool hasNext( );
		Dynamic hasNext_dyn();

		virtual Dynamic next( );
		Dynamic next_dyn();

};

} // end namespace org
} // end namespace shoebox
} // end namespace collections

#endif /* INCLUDED_org_shoebox_collections_PrioQueueIterator */ 
