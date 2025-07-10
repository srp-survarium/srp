void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_problem>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_problem **pointer)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+13h] [ebp-1h] BYREF

  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_problem,vostok::memory::detail::call_destructor_predicate>(
    allocator,
    pointer,
    &call_destructor_predicate);
}
