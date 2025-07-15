void __thiscall survarium::weapon_core::weapon_core(survarium::weapon_core *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::ai::fsm *v4; // eax
  vostok::ai::fsm *v5; // [esp+0h] [ebp-2Ch]
  void *_Where; // [esp+14h] [ebp-18h]
  vostok::ai::fsm *v8; // [esp+28h] [ebp-4h]

  survarium::inventory_item::inventory_item(&this->survarium::inventory_item, inventory_active_item);
  this->__vftable = (survarium::weapon_core_vtbl *)&survarium::weapon_core::`vftable';
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_fire_bullet_transform);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_transform);
  survarium::hand_to_weapon_ik_processor::hand_to_weapon_ik_processor(&this->m_hand_ik_processor);
  survarium::legs_ik_processor::legs_ik_processor(&this->m_legs_ik_processor);
  survarium::weapon_user_animations_selector::weapon_user_animations_selector(&this->m_user_animations_selector);
  survarium::recoil_calculator::recoil_calculator(&this->m_recoil_calculator);
  survarium::dispersion_calculator::dispersion_calculator(&this->m_dispersion_calculator);
  survarium::breath_vibration_calculator::breath_vibration_calculator(&this->m_breath_vibration_calculator);
  survarium::weapon_recoil_params::weapon_recoil_params(&this->m_recoil_params);
  survarium::weapon_dispersion_params::weapon_dispersion_params(&this->m_dispersion_params);
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition,
    0);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->m_skeleton.m_object);
  this->m_initiator_holder = 0;
  this->m_receiver_holder = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x14u);
  v8 = (vostok::ai::fsm *)operator new(0x14u, _Where);
  if ( v8 )
  {
    vostok::ai::fsm::fsm(v8);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  this->m_logic = v5;
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_logic_states);
  this->m_bullet_manager = 0;
  this->m_user = 0;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&this->m_random);
  this->m_weapon_fire_queue_types = 0;
  this->m_normal_random.m_seed = 1;
  this->m_bullet_damage = *(float *)&FLOAT_0_0;
  this->m_bullet_pierce = *(float *)&FLOAT_0_0;
  this->m_target = weapon_target_idle;
  this->m_old_actions_mask = 0;
  this->m_magazine_capacity = 0;
  this->m_ammo_in_magazine = 0;
  this->m_bullets_in_queue = 0;
  this->m_fire_queue_type = 0;
  this->m_ammo_slot = max_slots_count;
  this->m_weapon_id = 0;
  this->m_weapon_fire_queue_types_count = 0;
  this->m_is_shown = 0;
  this->m_aimed = 0;
  this->m_ready_for_fire = 0;
  this->m_is_double_handed = 1;
  this->m_is_in_sprint_transition = 0;
  this->m_is_firing = 0;
  this->m_is_there_chamber_a_round_state = 0;
  this->m_is_round_chambered = 0;
  this->m_chamber_a_round_on_reload = 0;
  this->m_load_ammo_on_next_activate = 1;
  this->m_aiming_state_transition = 0;
  this->m_is_idle = 0;
  this->m_deserializing = 0;
  this->m_is_toggling = 0;
}
