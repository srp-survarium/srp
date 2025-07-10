void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::plan_tracker>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::plan_tracker **pointer)
{
  vostok::ai::planning::plan_tracker *v2; // [esp+10h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::plan_tracker::~plan_tracker(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
