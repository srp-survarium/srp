void __usercall survarium::weapon_core::initialize(
        survarium::weapon_core *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  vostok::ai::fsm *m_logic; // esi
  survarium::profile_slot_enum *m_ammunition_slots; // eax
  survarium::inventory_item *m_object; // esi
  survarium::weapon_core *v8; // ecx
  survarium::base_player *m_user; // esi
  unsigned int m_current_time_in_ms; // edi
  bool v11; // cf
  survarium::base_player *v12; // eax
  int v13; // eax
  float v14; // xmm0_4
  survarium::base_player *v15; // eax
  vostok::threading::mutex *v16; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+14h] [ebp-8h] BYREF
  bool is_moving[4]; // [esp+18h] [ebp-4h]

  *(_DWORD *)is_moving = 0;
  this->m_aimed = 0;
  this->m_aim_progress.m_start_transition_time_in_ms = -1;
  this->m_aim_progress.m_current_value = 0.0;
  this->m_aim_progress.m_start_value = 0.0;
  this->m_aim_progress.m_target_value = 0.0;
  this->m_aim_progress.m_transition_time = 0.0;
  m_logic = this->m_logic;
  this->m_is_in_sprint_transition = 0;
  this->m_need_to_auto_reload = 0;
  vostok::ai::fsm::set_initial_state(m_logic, m_logic->m_states.m_first, ignore_current_state);
  m_ammunition_slots = this->m_ammunition_slots;
  *(float *)&v19.m_object = 0.0;
  if ( m_ammunition_slots )
  {
    m_object = this->m_inventory->m_slots.elems[m_ammunition_slots[this->m_selected_ammo_id]].m_object;
    *(_DWORD *)is_moving = 1;
    if ( *(float *)&m_object != 0.0 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
      v19.m_object = (vostok::particle::particle_system_instance_impl *)m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
  }
  else
  {
    *(_DWORD *)is_moving = 2;
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v19,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_ammunition);
  if ( (is_moving[0] & 2) != 0 )
  {
    *(_DWORD *)is_moving &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
  }
  if ( is_moving[0] )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
  if ( this->m_load_ammo_on_next_activate )
  {
    survarium::weapon_core::load_ammo(v8, this);
    this->m_load_ammo_on_next_activate = 0;
  }
  survarium::weapon_core::reset_fire_queue(v8, (int)this);
  ((void (__thiscall *)(survarium::portable_interactive_object_core *, int, int, int))this->m_portable_interactive_object->initialize)(
    this->m_portable_interactive_object,
    a3,
    a4,
    a2);
  m_user = this->m_user;
  m_current_time_in_ms = m_user->m_current_time_in_ms;
  if ( !survarium::player_input::is_moving(&m_user->m_input)
    || (v11 = m_user->damage_model(&m_user->survarium::inventory_holder)->m_object->m_broken_legs_count < 2u,
        is_moving[0] = 1,
        !v11) )
  {
    is_moving[0] = 0;
  }
  v12 = this->m_user;
  if ( v12->m_stamina.m_is_low_stamina )
    *(float *)&v19.m_object = (float)(*(float *)((char *)&loc_110B4 + (_DWORD)v12)
                                    - *(float *)((char *)&v12->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                               + (_DWORD)&locret_110FB
                                               + 1))
                            / *(float *)((char *)&loc_110B4 + (_DWORD)v12);
  else
    *(float *)&v19.m_object = 0.0;
  v13 = (int)v12->damage_model(&v12->survarium::inventory_holder);
  survarium::dispersion_calculator::initialize(
    (survarium::dispersion_calculator *)this->m_is_double_handed,
    (int *)&this->m_dispersion_calculator,
    m_current_time_in_ms,
    (survarium::weapon_user_state_enum)this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size,
    is_moving[0],
    *(_BYTE *)(*(_DWORD *)v13 + 1745),
    this->m_is_double_handed,
    *(float *)&v19.m_object,
    m_current_time_in_ms);
  this->m_recoil_calculator.m_weapon_calculator.m_time_to_start_side_compensation = -1;
  this->m_recoil_calculator.m_weapon_calculator.m_time_to_start_back_compensation = -1;
  this->m_recoil_calculator.m_weapon_calculator.m_time_of_last_shoot = -1;
  this->m_recoil_calculator.m_weapon_calculator.m_random.m_seed = 0;
  this->m_recoil_calculator.m_weapon_calculator.m_vertical_target = 0.0;
  this->m_recoil_calculator.m_weapon_calculator.m_horizontal_target = 0.0;
  this->m_recoil_calculator.m_weapon_calculator.m_back_target = 0.0;
  this->m_recoil_calculator.m_weapon_calculator.m_vertical_value_at_last_shoot = 0.0;
  this->m_recoil_calculator.m_weapon_calculator.m_horizontal_value_at_last_shoot = 0.0;
  v14 = s_bm_current_air_resistance;
  this->m_recoil_calculator.m_weapon_calculator.m_player_recoil_multiplier = s_bm_current_air_resistance;
  this->m_recoil_calculator.m_character_calculator.m_current_time_in_ms = m_current_time_in_ms;
  this->m_recoil_calculator.m_character_calculator.m_current_value = v14;
  this->m_recoil_calculator.m_character_calculator.m_target_value = v14;
  v15 = this->m_user;
  this->m_last_tick_time_in_ms = m_current_time_in_ms;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &v15->m_profile->modifiers.m_modifiers.elems[4],
    &this->m_move_speed_modifier,
    v16);
}


void __usercall survarium::weapon_core::initialize(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  survarium::weapon_core::initialize((survarium::weapon_core *)(a1 - 16), a2, a3, a4);
}
