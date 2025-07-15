void __thiscall survarium::base_player::~base_player(survarium::base_player *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_damage_model);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_game_world_objects.m_last);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_game_world_objects.m_first);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_target_active_object);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_current_active_object);
  survarium::hit_receiver::~hit_receiver(&this->survarium::hit_receiver);
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->id);
  this->survarium::collision_user::__vftable = (survarium::collision_user_vtbl *)&survarium::collision_user::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_usable_object_user_data);
  this->survarium::inventory_holder::__vftable = (survarium::base_player_vtbl *)&survarium::inventory_holder::`vftable';
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&this->m_inventory);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_scheduler);
}
