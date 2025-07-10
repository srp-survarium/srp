void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::receiver_collision>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::receiver_collision **pointer)
{
  vostok::sound::receiver_collision *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::sound::receiver_collision::~receiver_collision(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
