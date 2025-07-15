bool __thiscall vostok::engine::engine_world::render_has_been_created(vostok::engine::engine_world *this)
{
  return this->m_resources_cooker_destruction_started != 0;
}
