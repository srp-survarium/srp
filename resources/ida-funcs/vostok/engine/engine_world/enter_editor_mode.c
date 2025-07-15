void __thiscall vostok::engine::engine_world::enter_editor_mode(vostok::engine::engine_world *this)
{
  if ( this->m_render_world )
    ((void (__thiscall *)(vostok::render::world *, int))this->m_render_world->m_logic_channel.m_owner_allocator[1].__vftable)(
      this->m_render_world,
      1);
}


void __thiscall vostok::engine::engine_world::enter_editor_mode(char *this)
{
  vostok::engine::engine_world::enter_editor_mode((vostok::engine::engine_world *)(this - 4));
}
