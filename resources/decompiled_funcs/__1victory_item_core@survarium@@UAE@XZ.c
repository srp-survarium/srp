void __thiscall survarium::victory_item_core::~victory_item_core(survarium::victory_item_core *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax

  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_item_core_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::link_resolver'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::victory_item_core::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
    this->m_collision_geometries,
    v1);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  survarium::usable_object::~usable_object(this);
}
