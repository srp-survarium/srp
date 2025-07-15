void __usercall vostok::render::skeleton_render_model_instance::~skeleton_render_model_instance(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *a3@<edi>)
{
  vostok::math::float4x4 *m_begin; // ecx
  vostok::memory::doug_lea_allocator *v5; // [esp-4h] [ebp-8h]

  v5 = vostok::render::g_allocator;
  this->__vftable = (vostok::render::skeleton_render_model_instance_vtbl *)&vostok::render::skeleton_render_model_instance::`vftable';
  vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,vostok::render::render_surface_instance>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_surface_instances,
    a2,
    a3,
    (const char *)this,
    v5);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_update_bones_subscribers.vostok::threading::mutex);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_original);
  this->m_shadow_bones_matrices.m_end = this->m_shadow_bones_matrices.m_begin;
  this->m_bones_matrices.m_end = this->m_bones_matrices.m_begin;
  m_begin = this->m_prev_bones_matrices.m_begin;
  this->m_prev_bones_matrices.m_end = m_begin;
  vostok::render::render_model_instance_impl::~render_model_instance_impl(
    (vostok::render::render_model_instance_impl *)m_begin,
    &this->vostok::render::render_model_instance_impl);
}
