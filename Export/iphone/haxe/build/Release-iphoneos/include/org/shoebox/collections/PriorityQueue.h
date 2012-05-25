#ifndef INCLUDED_org_shoebox_collections_PriorityQueue
#define INCLUDED_org_shoebox_collections_PriorityQueue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(org,shoebox,collections,PrioQueueIterator)
HX_DECLARE_CLASS3(org,shoebox,collections,PriorityQueue)
namespace org{
namespace shoebox{
namespace collections{


class PriorityQueue_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PriorityQueue_obj OBJ_;
		PriorityQueue_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PriorityQueue_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PriorityQueue_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PriorityQueue"); }

		int length; /* REM */ 
		Dynamic _aContent; /* REM */ 
		bool _bInvalidate; /* REM */ 
		::org::shoebox::collections::PrioQueueIterator _oIterator; /* REM */ 
		virtual Void add( Dynamic value,hx::Null< int >  prio);
		Dynamic add_dyn();

		virtual bool remove( Dynamic value,hx::Null< int >  prio);
		Dynamic remove_dyn();

		virtual bool contains( Dynamic value,int prio);
		Dynamic contains_dyn();

		virtual Void sort( );
		Dynamic sort_dyn();

		virtual ::org::shoebox::collections::PrioQueueIterator iterator( );
		Dynamic iterator_dyn();

		virtual Void setPrioOf( Dynamic value,int prio);
		Dynamic setPrioOf_dyn();

		virtual int getPrioOf( Dynamic value);
		Dynamic getPrioOf_dyn();

		virtual Dynamic getContent( );
		Dynamic getContent_dyn();

		virtual Void _sort( );
		Dynamic _sort_dyn();

		virtual Void _add( Dynamic desc,int prio);
		Dynamic _add_dyn();

		virtual int _getLength( );
		Dynamic _getLength_dyn();

};

} // end namespace org
} // end namespace shoebox
} // end namespace collections

#endif /* INCLUDED_org_shoebox_collections_PriorityQueue */ 
