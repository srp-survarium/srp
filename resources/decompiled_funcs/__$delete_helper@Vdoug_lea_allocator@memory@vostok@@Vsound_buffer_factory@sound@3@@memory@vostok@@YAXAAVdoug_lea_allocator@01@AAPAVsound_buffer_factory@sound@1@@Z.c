void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::sound_buffer_factory>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::sound_buffer_factory **pointer)
{
  vostok::sound::sound_buffer_factory *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::sound::sound_buffer_factory::~sound_buffer_factory(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
