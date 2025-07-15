void __thiscall survarium::object_sound::on_sound_resources_ready(
        survarium::object_sound *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *callback)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v4; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v5; // [esp+Ch] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v5,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    (vostok::particle::particle_system_instance_impl *)v5.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sound_emitter);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v4,
    callback,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
