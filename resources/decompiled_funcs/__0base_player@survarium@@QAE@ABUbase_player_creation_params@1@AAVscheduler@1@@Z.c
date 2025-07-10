void __thiscall survarium::base_player::base_player(
        survarium::base_player *this,
        const survarium::base_player_creation_params *params,
        survarium::scheduler *the_scheduler)
{
  survarium::game_camera *v3; // ecx
  bool is_local; // [esp+16h] [ebp-1Ah]
  unsigned __int8 id; // [esp+17h] [ebp-19h]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+20h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *p_m_inventory; // [esp+24h] [ebp-Ch]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // [esp+28h] [ebp-8h]

  v9 = &v7;
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    &params->inventory,
    &v7.m_object);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_scheduler);
  this->survarium::inventory_holder::__vftable = (survarium::base_player_vtbl *)&survarium::inventory_holder::`vftable';
  this->m_scheduler = the_scheduler;
  p_m_inventory = &this->m_inventory;
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    &v7,
    &this->m_inventory.m_object);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v7);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_usable_object_user_data);
  this->survarium::collision_user::__vftable = (survarium::collision_user_vtbl *)&survarium::collision_user::`vftable';
  survarium::usable_object_user_data::usable_object_user_data(&this->m_usable_object_user_data);
  is_local = params->initial_info.profile->is_local;
  id = params->initial_info.id;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->id);
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  this->id = id;
  this->is_local = is_local;
  survarium::hit_receiver::hit_receiver(
    (survarium::hit_receiver *)&this->survarium::hit_initiator,
    &this->survarium::hit_receiver::vostok::collision::game_object::__vftable);
  vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>(
    0,
    (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> **)&this->m_current_active_object);
  vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>(
    0,
    (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> **)&this->m_target_active_object);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_character_head_transform);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_player_death_subscribers.m_first = 0;
  this->m_player_death_subscribers.m_last = 0;
  this->m_recoil_params = params->recoil_params;
  qmemcpy((void *)&this->m_dispersion_params, &params->dispersion_params, sizeof(this->m_dispersion_params));
  qmemcpy((void *)&this->m_breath_holding_params, &params->breath_holding_params, sizeof(this->m_breath_holding_params));
  vostok::intrusive_list<survarium::game_world_object,vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base>,264,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::intrusive_list<survarium::game_world_object,vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base>,264,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>(&this->m_game_world_objects);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&params->damage_model,
    (survarium::inventory **)&this->m_damage_model);
  LODWORD(this->m_movement_speed_factor) = clear_value;
  this->m_force_animation_selection = 0;
  this->m_is_alive = 0;
  this->m_is_replaying_history = 0;
  this->m_has_been_inserted = 0;
}
