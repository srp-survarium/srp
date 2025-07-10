void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::generalized_action>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::generalized_action **pointer)
{
  vostok::ai::planning::generalized_action *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::generalized_action::~generalized_action(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, (void *)v2);
    *pointer = 0;
  }
}
