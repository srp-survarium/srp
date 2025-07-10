void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_domain>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_domain **pointer)
{
  vostok::ai::planning::pddl_domain *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::pddl_domain::~pddl_domain(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, (void *)v2);
    *pointer = 0;
  }
}
