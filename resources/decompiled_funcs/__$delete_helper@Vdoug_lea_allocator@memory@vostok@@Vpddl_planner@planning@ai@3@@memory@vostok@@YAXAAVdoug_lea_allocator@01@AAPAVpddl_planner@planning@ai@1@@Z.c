void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_planner>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_planner **pointer)
{
  vostok::ai::planning::pddl_planner *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::pddl_planner::~pddl_planner(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
