vostok::render::skeleton_render_model *__thiscall vostok::render::skeleton_render_model::`scalar deleting destructor'(
        vostok::render::skeleton_render_model *this,
        char a2)
{
  vostok::math::float4x4 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  M_start = this->m_inverted_bones_matrices_in_bind_pose._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_start);
  }
  vostok::render::render_model::~render_model(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
