void __thiscall survarium::object_skeleton_visual::on_model_loaded(
        survarium::object_skeleton_visual *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  vostok::resources::queries_result *m_object; // esi
  vostok::resources::resource_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_model; // ebx
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // esi
  int v8; // edi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  const char *v12; // [esp+0h] [ebp-18h]
  const char *v13; // [esp+4h] [ebp-14h]
  unsigned int v14; // [esp+8h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp+14h] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v16,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::resources::queries_result *)v16.m_object;
  data = 0;
  if ( v16.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
  }
  p_m_model = &this->m_model;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)p_m_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v6,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
  v7 = survarium::g_allocator;
  v8 = p_m_model->m_object->m_skeleton.m_object->m_bones_count
     - (signed int)(p_m_model->m_object->m_skeleton.m_object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                  - (unsigned int)&p_m_model->m_object->m_skeleton.m_object[1])
     / 28;
  v9 = type_info::raw_name(&vostok::math::float4x4 `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v7, v8 << 6, v9, v12, v13, v14);
  this->m_animation_bone_matrices = (vostok::math::float4x4 *)v11;
  p_m_model->m_object->m_render_model.m_object->get_bind_pose(
    p_m_model->m_object->m_render_model.m_object,
    (vostok::math::float4x4 *)v11,
    v8);
}
