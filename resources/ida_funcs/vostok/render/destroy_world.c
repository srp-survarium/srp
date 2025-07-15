void __cdecl vostok::render::destroy_world(vostok::render::world **world)
{
  vostok::render::world *v1; // ecx

  vostok::render::world::~world(v1, s_world_0.m_variable);
  s_world_0.m_initialized = 0;
  *world = 0;
}
