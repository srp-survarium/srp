void __thiscall survarium::weapon_cook::register_cooks_for_logic_states(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this)
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    survarium::weapon_core_inactive_state_cook::weapon_core_inactive_state_cook(&s_weapon_core_inactive_state_cook);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_inactive_state_cook__);
  }
  if ( (_S6_1 & 2) == 0 )
  {
    _S6_1 |= 2u;
    survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::weapon_core_state_cook_template<survarium::weapon_core_idle_state>(this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_idle_state_cook__);
  }
  if ( (_S6_1 & 4) == 0 )
  {
    _S6_1 |= 4u;
    survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>::weapon_core_state_cook_template<survarium::weapon_core_aimed_state>((survarium::weapon_core_state_cook_template<survarium::weapon_core_aimed_state> *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_aimed_state_cook__);
  }
  if ( (_S6_1 & 8) == 0 )
  {
    _S6_1 |= 8u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_show_state_cook__);
  }
  if ( (_S6_1 & 0x10) == 0 )
  {
    _S6_1 |= 0x10u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_hide_state_cook__);
  }
  if ( (_S6_1 & 0x20) == 0 )
  {
    _S6_1 |= 0x20u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_reload_cook__);
  }
  if ( (_S6_1 & 0x40) == 0 )
  {
    _S6_1 |= 0x40u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_chamber_a_round_cook__);
  }
  if ( (_S6_1 & 0x80u) == 0 )
  {
    _S6_1 |= 0x80u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_chamber_a_round_aimed_cook__);
  }
  if ( (_S6_1 & 0x100) == 0 )
  {
    _S6_1 |= 0x100u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_fire_cook__);
  }
  if ( (_S6_1 & 0x200) == 0 )
  {
    _S6_1 |= 0x200u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_aimed_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_aimed_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_aimed_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_aimed_fire_cook__);
  }
  if ( (_S6_1 & 0x400) == 0 )
  {
    _S6_1 |= 0x400u;
    survarium::shotgun_weapon_reload_state_cook::shotgun_weapon_reload_state_cook((survarium::shotgun_weapon_reload_state_cook *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_weapon_reload_state_cook__);
  }
  if ( (_S6_1 & 0x800) == 0 )
  {
    _S6_1 |= 0x800u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_start_substate_cook__);
  }
  if ( (_S6_1 & 0x1000) == 0 )
  {
    _S6_1 |= 0x1000u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_one_round_substate_cook__);
  }
  if ( (_S6_1 & 0x2000) == 0 )
  {
    _S6_1 |= 0x2000u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_finish_substate_cook__);
  }
  if ( (_S6_1 & 0x4000) == 0 )
  {
    _S6_1 |= 0x4000u;
    survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>((survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state> *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_weapon_core_idle_state_cook__);
  }
  if ( (_S6_1 & 0x8000) == 0 )
  {
    _S6_1 |= 0x8000u;
    survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>((survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_weapon_core_aimed_idle_state_cook__);
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&_sbh_sizeHeaderList;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_show_state_cook__);
  }
  if ( ((unsigned int)&loc_20000 & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_20000;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_hide_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_hide_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_hide_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_hide_state_cook__);
  }
  if ( (_S6_1 & 0x40000) == 0 )
  {
    _S6_1 |= 0x40000u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_reload_cook__);
  }
  if ( (_S6_1 & 0x80000) == 0 )
  {
    _S6_1 |= 0x80000u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_fire_cook__);
  }
  if ( (((unsigned int)&loc_FFFFF + 1) & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_FFFFF + 1;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_aimed_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_aimed_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_aimed_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_aimed_fire_cook__);
  }
  if ( (((unsigned int)&loc_1FFFFE + 2) & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_1FFFFE + 2;
    survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>((survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_weapon_core_idle_state_cook__);
  }
  if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
    survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_aimed_idle_state>::weapon_core_state_cook_template<survarium::pistol_weapon_core_aimed_idle_state>((survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_aimed_idle_state> *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_weapon_core_aimed_idle_state_cook__);
  }
  if ( ((unsigned int)&unk_800000 & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&unk_800000;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_show_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_show_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_show_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_show_state_cook__);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&vostok::memory::s_CRT_arena[5574200];
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_hide_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_hide_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_hide_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_hide_state_cook__);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&vostok::memory::s_CRT_arena[22351416];
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_reload_cook__);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_fire_cook__);
  }
  if ( (_S6_1 & 0x8000000) == 0 )
  {
    _S6_1 |= 0x8000000u;
    survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_aimed_fire_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_aimed_fire_state>>((survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_aimed_fire_state> > *)this);
    atexit(survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_aimed_fire_cook__);
  }
}
