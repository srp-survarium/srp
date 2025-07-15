vostok::sound::sound_world *__cdecl vostok::sound::create_world(
        vostok::sound::engine *engine,
        vostok::memory::base_allocator *logic_allocator,
        vostok::memory::base_allocator *editor_allocator)
{
  if ( &s_world_3 )
    vostok::sound::sound_world::sound_world(
      (vostok::sound::sound_world *)&s_world_3,
      engine,
      logic_allocator,
      editor_allocator);
  _InterlockedExchange(&s_world_3.m_initialized, 1);
  return s_world_3.m_variable;
}
