void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal_specificator>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::goal_specificator **pointer)
{
  vostok::ai::planning::goal_specificator *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::goal_specificator::~goal_specificator(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
