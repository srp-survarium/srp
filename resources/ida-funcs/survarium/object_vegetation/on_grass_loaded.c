void __thiscall survarium::object_vegetation::on_grass_loaded(
        survarium::object_vegetation *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v4; // ecx

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    &this->m_grass);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v4,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
