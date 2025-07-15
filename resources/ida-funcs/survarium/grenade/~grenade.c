void __thiscall survarium::grenade::~grenade(survarium::grenade *this)
{
  this->survarium::grenade_core::survarium::tickable_object::__vftable = (survarium::grenade_vtbl *)&survarium::grenade::`vftable'{for `survarium::tickable_object'};
  this->survarium::grenade_core::survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::grenade::`vftable'{for `survarium::serializable_object'};
  this->survarium::grenade_core::vostok::collision::game_object::__vftable = (vostok::collision::game_object_vtbl *)&survarium::grenade::`vftable'{for `vostok::collision::game_object'};
  this->survarium::grenade_core::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::grenade::`vftable'{for `vostok::resources::unmanaged_resource'};
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_collide_callback);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_explosion);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_explosion);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  survarium::grenade_core::~grenade_core(this);
}
