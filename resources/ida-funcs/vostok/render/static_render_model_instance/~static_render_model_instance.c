void __thiscall vostok::render::static_render_model_instance::~static_render_model_instance(
        vostok::render::static_render_model_instance *this)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int *p_m_flags; // eax
  vostok::render::static_render_model *m_object; // eax

  this->__vftable = (vostok::render::static_render_model_instance_vtbl *)&vostok::render::static_render_model_instance::`vftable';
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::culling::possible_sectors_holder,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
    &this->m_sectors_holder);
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  p_m_flags = &this->m_surface_instances[-1].m_flags;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, p_m_flags);
  m_object = this->m_original.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_original.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_original.m_object);
  this->m_collision_object.vostok::render::render_model_instance_impl::__vftable = (vostok::render::render_collision_object<vostok::render::render_model_instance_impl>_vtbl *)&vostok::collision::object::`vftable';
  this->__vftable = (vostok::render::static_render_model_instance_vtbl *)&vostok::render::render_model_instance::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
