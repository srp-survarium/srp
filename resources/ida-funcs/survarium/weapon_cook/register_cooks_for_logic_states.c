void __thiscall survarium::weapon_cook::register_cooks_for_logic_states(survarium::weapon_cook *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v5; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v7; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v8; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v9; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v10; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v11; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v12; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v13; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v14; // ecx
  survarium::weapon_cook *v15; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v16; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v17; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v18; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v19; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v20; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v21; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v22; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v23; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v24; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v25; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v26; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v27; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v28; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v29; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v30; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v31; // [esp-4h] [ebp-10h]
  survarium::weapon_cook *v32; // [esp-4h] [ebp-10h]

  if ( (_S9_3 & 1) == 0 )
  {
    _S9_3 |= 1u;
    survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::weapon_core_state_cook_template<survarium::weapon_core_idle_state>((survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *)this);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_idle_state_cook__);
    this = v15;
  }
  if ( (_S9_3 & 2) == 0 )
  {
    _S9_3 |= 2u;
    vostok::resources::cook_base::cook_base(
      &s_show_state_cook,
      weapon_show_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_show_state_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_show_state_cook, v1);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_show_state_cook__);
    this = v16;
  }
  if ( (_S9_3 & 4) == 0 )
  {
    _S9_3 |= 4u;
    vostok::resources::cook_base::cook_base(
      &s_hide_state_cook,
      weapon_hide_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_hide_state_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_hide_state_cook, v2);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_hide_state_cook__);
    this = v17;
  }
  if ( (_S9_3 & 8) == 0 )
  {
    _S9_3 |= 8u;
    vostok::resources::cook_base::cook_base(
      &s_reload_cook,
      weapon_reload_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_reload_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_reload_cook, v3);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_reload_cook__);
    this = v18;
  }
  if ( (_S9_3 & 0x10) == 0 )
  {
    _S9_3 |= 0x10u;
    vostok::resources::cook_base::cook_base(
      &s_chamber_a_round_cook,
      weapon_chamber_a_round_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_chamber_a_round_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_chamber_a_round_cook, v4);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_chamber_a_round_cook__);
    this = v19;
  }
  if ( (_S9_3 & 0x20) == 0 )
  {
    _S9_3 |= 0x20u;
    vostok::resources::cook_base::cook_base(
      &s_fire_cook,
      weapon_fire_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_fire_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_fire_cook, v5);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_fire_cook__);
    this = v20;
  }
  if ( (_S9_3 & 0x40) == 0 )
  {
    _S9_3 |= 0x40u;
    vostok::resources::cook_base::cook_base(
      &s_shotgun_weapon_reload_state_cook,
      weapon_shotgun_reload_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_shotgun_weapon_reload_state_cook.__vftable = (survarium::shotgun_weapon_reload_state_cook_vtbl *)&survarium::shotgun_weapon_reload_state_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_shotgun_weapon_reload_state_cook, v6);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_weapon_reload_state_cook__);
    this = v21;
  }
  if ( (_S9_3 & 0x80u) == 0 )
  {
    _S9_3 |= 0x80u;
    vostok::resources::cook_base::cook_base(
      &s_shotgun_reload_start_substate_cook,
      weapon_shotgun_reload_start_substate_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_shotgun_reload_start_substate_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_shotgun_reload_start_substate_cook, v7);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_start_substate_cook__);
    this = v22;
  }
  if ( (_S9_3 & 0x100) == 0 )
  {
    _S9_3 |= 0x100u;
    vostok::resources::cook_base::cook_base(
      &s_shotgun_reload_one_round_substate_cook,
      weapon_shotgun_reload_one_substate_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_shotgun_reload_one_round_substate_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_shotgun_reload_one_round_substate_cook, v8);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_one_round_substate_cook__);
    this = v23;
  }
  if ( (_S9_3 & 0x200) == 0 )
  {
    _S9_3 |= 0x200u;
    vostok::resources::cook_base::cook_base(
      &s_shotgun_reload_finish_substate_cook,
      weapon_shotgun_reload_finish_substate_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_shotgun_reload_finish_substate_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_shotgun_reload_finish_substate_cook, v9);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_shotgun_reload_finish_substate_cook__);
    this = v24;
  }
  if ( (_S9_3 & 0x400) == 0 )
  {
    _S9_3 |= 0x400u;
    survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state>((survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_idle_state> *)this);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_weapon_core_idle_state_cook__);
    this = v25;
  }
  if ( (_S9_3 & 0x800) == 0 )
  {
    _S9_3 |= 0x800u;
    vostok::resources::cook_base::cook_base(
      &s_double_barreled_reload_cook,
      double_barreled_weapon_reload_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_double_barreled_reload_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_double_barreled_reload_cook, v10);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_reload_cook__);
    this = v26;
  }
  if ( (_S9_3 & 0x1000) == 0 )
  {
    _S9_3 |= 0x1000u;
    vostok::resources::cook_base::cook_base(
      &s_double_barreled_fire_cook,
      double_barreled_weapon_fire_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_double_barreled_fire_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_double_barreled_fire_cook, v11);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_double_barreled_fire_cook__);
    this = v27;
  }
  if ( (_S9_3 & 0x2000) == 0 )
  {
    _S9_3 |= 0x2000u;
    survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state>((survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_idle_state> *)this);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_weapon_core_idle_state_cook__);
    this = v28;
  }
  if ( (_S9_3 & 0x4000) == 0 )
  {
    _S9_3 |= 0x4000u;
    vostok::resources::cook_base::cook_base(
      &s_pistol_reload_cook,
      pistol_weapon_reload_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_pistol_reload_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_pistol_reload_cook, v12);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_reload_cook__);
    this = v29;
  }
  if ( (_S9_3 & 0x8000) == 0 )
  {
    _S9_3 |= 0x8000u;
    vostok::resources::cook_base::cook_base(
      &s_pistol_fire_cook,
      pistol_weapon_fire_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_pistol_fire_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_pistol_fire_cook, v13);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_pistol_fire_cook__);
    this = v30;
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S9_3) == 0 )
  {
    _S9_3 |= (unsigned int)&_sbh_sizeHeaderList;
    survarium::weapon_core_throw_grenade_state_cook::weapon_core_throw_grenade_state_cook((survarium::weapon_core_throw_grenade_state_cook *)this);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_throw_grenade_state_cook__);
    this = v31;
  }
  if ( ((unsigned int)&loc_20000 & _S9_3) == 0 )
  {
    _S9_3 |= (unsigned int)&loc_20000;
    vostok::resources::cook_base::cook_base(
      &s_weapon_preview_state_cook,
      weapon_preview_state_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_weapon_preview_state_cook.__vftable = (survarium::weapon_preview_state_cook_vtbl *)&survarium::weapon_preview_state_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_weapon_preview_state_cook, v14);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_preview_state_cook__);
    this = v32;
  }
  if ( (((unsigned int)&loc_3FFFF + 1) & _S9_3) == 0 )
  {
    _S9_3 |= (unsigned int)&loc_3FFFF + 1;
    survarium::weapon_core_melee_state_cook::weapon_core_melee_state_cook((survarium::weapon_core_melee_state_cook *)this);
    atexit((int (__cdecl *)())survarium::weapon_cook::register_cooks_for_logic_states_::_2_::_dynamic_atexit_destructor_for__s_weapon_core_melee_state_cook__);
  }
}
