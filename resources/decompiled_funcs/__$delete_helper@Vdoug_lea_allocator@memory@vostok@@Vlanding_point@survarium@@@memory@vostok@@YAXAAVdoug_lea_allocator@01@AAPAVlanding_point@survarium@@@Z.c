void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::landing_point>(
        vostok::memory::doug_lea_allocator *allocator,
        survarium::landing_point **pointer)
{
  survarium::landing_point *v2; // [esp+Ch] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    survarium::landing_point::`scalar deleting destructor'(*pointer, 0);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
