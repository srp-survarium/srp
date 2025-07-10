void __thiscall vostok::particle::particle_system_instance_impl::set_template(
        vostok::particle::particle_system_instance_impl *this,
        unsigned int lod_index,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> templ)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_lods[lod_index].m_template,
    &templ);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&templ);
}
