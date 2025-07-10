void __thiscall survarium::ladder::~ladder(survarium::ladder *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::game_camera *v2; // ecx
  survarium::ladder::ladder_occluder **p_m_occluder; // [esp-4h] [ebp-18h]

  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::ladder_vtbl *)&survarium::ladder::`vftable';
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::ladder::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::ladder::`vftable'{for `survarium::link_resolver'};
  p_m_occluder = &this->m_occluder;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::oracle>(
    v1,
    (vostok::ai::planning::oracle **)p_m_occluder);
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_main_animation);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::usable_object::~usable_object(&this->survarium::usable_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
