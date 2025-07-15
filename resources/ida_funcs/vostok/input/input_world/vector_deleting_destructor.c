vostok::input::input_world *__thiscall vostok::input::input_world::`vector deleting destructor'(
        vostok::input::input_world *this,
        char a2)
{
  void **M_start; // eax
  void *m_arena; // esi

  this->__vftable = (vostok::input::input_world_vtbl *)&vostok::input::input_world::`vftable';
  vostok::input::input_world::destroy_devices(this);
  M_start = this->m_handlers._M_impl._M_start;
  if ( M_start )
  {
    m_arena = vostok::input::g_allocator->m_arena;
    vostok::input::g_allocator->m_out_of_memory = 0;
    vostok_mspace_free(m_arena, M_start);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
