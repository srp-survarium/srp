void __thiscall survarium::victory_item_core::victory_item_core(survarium::victory_item_core *this)
{
  survarium::usable_object::usable_object(this);
  vostok::resources::unmanaged_resource::unmanaged_resource(&this->vostok::resources::unmanaged_resource, 1u);
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_item_core_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_item_core::`vftable'{for `survarium::link_resolver'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::victory_item_core::`vftable';
  this->id = -1;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_transform);
  this->m_is_inserted = 0;
  this->m_spoted_to_team = team_undefined;
  this->m_carrier_id = -1;
  vostok::math::float4x4::identity(&this->m_transform);
}
