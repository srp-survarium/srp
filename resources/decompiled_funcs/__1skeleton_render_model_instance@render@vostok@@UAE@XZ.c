void __thiscall vostok::render::skeleton_render_model_instance::~skeleton_render_model_instance(
        vostok::render::skeleton_render_model_instance *this)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int *p_m_flags; // eax
  vostok::render::skeleton_render_model *m_object; // eax
  vostok::math::float4x4 *M_start; // eax
  void *v6; // esi
  vostok::math::float4x4 *v7; // eax
  void *v8; // esi

  this->__vftable = (vostok::render::skeleton_render_model_instance_vtbl *)&vostok::render::skeleton_render_model_instance::`vftable';
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  p_m_flags = &this->m_surface_instances[-1].m_flags;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, p_m_flags);
  m_object = this->m_original.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_original.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_original.m_object);
  M_start = this->m_bones_matrices._M_impl._M_start;
  if ( M_start )
  {
    v6 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, (void *)M_start);
  }
  v7 = this->m_prev_bones_matrices._M_impl._M_start;
  if ( v7 )
  {
    v8 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v8, (void *)v7);
  }
  this->m_collision_object.vostok::render::render_model_instance_impl::__vftable = (vostok::render::render_collision_object<vostok::render::render_model_instance_impl>_vtbl *)&vostok::collision::object::`vftable';
  this->__vftable = (vostok::render::skeleton_render_model_instance_vtbl *)&vostok::render::render_model_instance::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
