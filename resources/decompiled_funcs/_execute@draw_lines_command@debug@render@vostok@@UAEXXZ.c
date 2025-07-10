void __thiscall vostok::render::debug::draw_lines_command::execute(vostok::render::debug::draw_lines_command *this)
{
  vostok::render::base_scene *m_object; // eax
  vostok::render::scene *v2; // esi

  m_object = this->m_scene.m_object;
  v2 = 0;
  if ( m_object )
  {
    v2 = (vostok::render::scene *)this->m_scene.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::render::scene::draw_lines(&this->m_vertices, v2, (int)&this->m_indices);
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
  }
}
