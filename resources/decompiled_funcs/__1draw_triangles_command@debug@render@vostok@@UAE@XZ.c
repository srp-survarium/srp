void __thiscall vostok::render::debug::draw_triangles_command::~draw_triangles_command(
        vostok::render::debug::draw_triangles_command *this)
{
  vostok::render::base_scene *m_object; // eax

  this->__vftable = (vostok::render::debug::draw_triangles_command_vtbl *)&vostok::render::debug::draw_triangles_command::`vftable';
  m_object = this->m_scene.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_scene.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_scene.m_object);
  if ( this->m_indices._M_impl._M_start )
    this->m_indices._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_indices._M_impl._M_end_of_storage.m_allocator,
      this->m_indices._M_impl._M_start);
  if ( this->m_vertices._M_impl._M_start )
    this->m_vertices._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_vertices._M_impl._M_end_of_storage.m_allocator,
      this->m_vertices._M_impl._M_start);
}
