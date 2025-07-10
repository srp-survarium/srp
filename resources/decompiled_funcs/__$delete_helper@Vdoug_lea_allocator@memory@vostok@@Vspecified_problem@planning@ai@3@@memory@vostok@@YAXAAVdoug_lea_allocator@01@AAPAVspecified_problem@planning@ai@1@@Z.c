void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::specified_problem>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::specified_problem **pointer)
{
  vostok::ai::planning::specified_problem *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::specified_problem::~specified_problem(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
