void __thiscall survarium::ladder::ladder(
        survarium::ladder *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *main_animation,
        const vostok::math::plane *p)
{
  survarium::game_camera *v3; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::usable_object::usable_object(&this->survarium::usable_object);
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::ladder_vtbl *)&survarium::ladder::`vftable';
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::ladder::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::ladder::`vftable'{for `survarium::link_resolver'};
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->m_landing_points.m_size);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_landing_points.m_first = 0;
  this->m_landing_points.m_last = 0;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &this->m_main_animation,
    main_animation);
  this->m_plane = *p;
  this->m_occluder = 0;
}
