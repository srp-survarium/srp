void __thiscall survarium::rifle_scope::rifle_scope(
        survarium::rifle_scope *this,
        vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *idle_scope,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *aimed_scope,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *change_scope_factor,
        vostok::render::static_model_instance *hide_weapon_on_aim,
        float fov_factor,
        vostok::render::static_model_instance *near_plane_factor,
        vostok::render::static_model_instance *a8)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, idle_scope, fs_iterator_class);
  idle_scope->m_object = (vostok::render::static_model_instance *)&survarium::rifle_scope::`vftable';
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&idle_scope[66],
    aimed_scope);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&idle_scope[67],
    change_scope_factor);
  idle_scope[68].m_object = hide_weapon_on_aim;
  idle_scope[69].m_object = near_plane_factor;
  LOBYTE(idle_scope[71].m_object) = LOBYTE(fov_factor);
  idle_scope[70].m_object = a8;
}
