vostok::render::ui::draw_vertices_command *__thiscall vostok::render::ui::draw_vertices_command::`scalar deleting destructor'(
        vostok::render::ui::draw_vertices_command *this,
        char a2)
{
  vostok::render::base_scene_view *m_object; // eax

  m_object = this->m_scene_view.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_scene_view.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_scene_view.m_object);
  if ( this->m_vertices._M_impl._M_start )
    this->m_vertices._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_vertices._M_impl._M_end_of_storage.m_allocator,
      this->m_vertices._M_impl._M_start);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
