void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::proxy_statistic>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::sound_scene_statistic **pointer)
{
  if ( *pointer )
  {
    vostok::memory::doug_lea_allocator::free_impl(allocator, *pointer);
    *pointer = 0;
  }
}
