void __cdecl vostok::render::engine::destroy(vostok::render::engine::world **engine_world)
{
  vostok::render::engine::world *v1; // ecx

  vostok::render::engine::world::~world(v1, s_world_1.m_variable);
  s_world_1.m_initialized = 0;
  *engine_world = 0;
}
