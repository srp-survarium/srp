void __thiscall survarium::game_world::register_cooks(survarium::game_world *this, survarium::game_world *game_world)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v5; // ecx
  survarium::damage_zone_cook *v6; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v7; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v8; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v9; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v10; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v11; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v12; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v13; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v14; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v15; // ecx
  survarium::game_world *v16; // [esp-4h] [ebp-14h]
  survarium::game_world *v17; // [esp-4h] [ebp-14h]
  survarium::game_world *v18; // [esp-4h] [ebp-14h]
  survarium::game_world *v19; // [esp-4h] [ebp-14h]
  survarium::game *m_game; // [esp-4h] [ebp-14h]
  survarium::game_world *v21; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v22; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v23; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v24; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v25; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v26; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v27; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v28; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v29; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v30; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v31; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v32; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v33; // [esp-4h] [ebp-14h]
  survarium::damage_zone_cook *v34; // [esp-4h] [ebp-14h]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v35; // [esp+0h] [ebp-10h]

  if ( (_S9_4 & 1) == 0 )
  {
    _S9_4 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x4A,
      &s_booby_trap_set_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_booby_trap_set_cook.__vftable = (survarium::booby_trap_set_cook_vtbl *)&survarium::booby_trap_set_core_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_booby_trap_set_cook, v2);
    s_booby_trap_set_cook.__vftable = (survarium::booby_trap_set_cook_vtbl *)&survarium::booby_trap_set_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_booby_trap_set_cook__);
    this = v16;
  }
  if ( (_S9_4 & 2) == 0 )
  {
    _S9_4 |= 2u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x4B,
      &s_booby_trap_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_booby_trap_cook.__vftable = (survarium::booby_trap_cook_vtbl *)&survarium::booby_trap_core_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_booby_trap_cook, v3);
    s_booby_trap_cook.__vftable = (survarium::booby_trap_cook_vtbl *)&survarium::booby_trap_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_booby_trap_cook__);
    this = v17;
  }
  if ( (_S9_4 & 4) == 0 )
  {
    _S9_4 |= 4u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x4C,
      &s_grenade_set_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_grenade_set_cook.__vftable = (survarium::grenade_set_cook_vtbl *)&survarium::grenade_set_core_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_grenade_set_cook, v4);
    s_grenade_set_cook.__vftable = (survarium::grenade_set_cook_vtbl *)&survarium::grenade_set_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_grenade_set_cook__);
    this = v18;
  }
  if ( (_S9_4 & 8) == 0 )
  {
    _S9_4 |= 8u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x4D,
      &s_grenade_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_grenade_cook.__vftable = (survarium::grenade_cook_vtbl *)&survarium::grenade_core_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_grenade_cook, v5);
    s_grenade_cook.__vftable = (survarium::grenade_cook_vtbl *)&survarium::grenade_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_grenade_cook__);
    this = v19;
  }
  if ( (_S9_4 & 0x10) == 0 )
  {
    m_game = game_world->m_game;
    _S9_4 |= 0x10u;
    survarium::weapon_cook::weapon_cook((survarium::weapon_cook *)this, m_game);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_weapon_cook__);
    this = v21;
  }
  survarium::weapon_cook::register_cooks_for_logic_states((survarium::weapon_cook *)this);
  if ( (_S9_4 & 0x20) == 0 )
  {
    _S9_4 |= 0x20u;
    survarium::damage_zone_cook::damage_zone_cook(v6, game_world);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_damage_zone_cook__);
    v6 = v22;
  }
  if ( (_S9_4 & 0x40) == 0 )
  {
    _S9_4 |= 0x40u;
    survarium::effect_zone_cook::effect_zone_cook((survarium::effect_zone_cook *)v6, game_world);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_effect_zone_cook__);
    v6 = v23;
  }
  if ( (_S9_4 & 0x80u) == 0 )
  {
    _S9_4 |= 0x80u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x4E,
      &s_rifle_scope_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_rifle_scope_cook.__vftable = (survarium::rifle_scope_cook_vtbl *)&survarium::rifle_scope_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_rifle_scope_cook, v7);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_rifle_scope_cook__);
    v6 = v24;
  }
  if ( (_S9_4 & 0x100) == 0 )
  {
    _S9_4 |= 0x100u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x79,
      &s_empty_hands_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_empty_hands_cook.__vftable = (survarium::empty_hands_cook_vtbl *)&survarium::empty_hands_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_empty_hands_cook, v8);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_empty_hands_cook__);
    v6 = v25;
  }
  if ( (_S9_4 & 0x200) == 0 )
  {
    _S9_4 |= 0x200u;
    survarium::generic_anomaly_cook::generic_anomaly_cook((survarium::generic_anomaly_cook *)v6, game_world);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_generic_anomaly_cook__);
    v6 = v26;
  }
  if ( (_S9_4 & 0x400) == 0 )
  {
    _S9_4 |= 0x400u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x73,
      &s_artefact_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_artefact_cook.__vftable = (survarium::artefact_cook_vtbl *)&survarium::artefact_core_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_artefact_cook, v9);
    s_artefact_cook.__vftable = (survarium::artefact_cook_vtbl *)&survarium::artefact_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_artefact_cook__);
    v6 = v27;
  }
  if ( (_S9_4 & 0x800) == 0 )
  {
    _S9_4 |= 0x800u;
    survarium::game_effect_emitter_cook::game_effect_emitter_cook((survarium::game_effect_emitter_cook *)v6);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_game_effect_emitter_cook__);
    v6 = v28;
  }
  if ( (_S9_4 & 0x1000) == 0 )
  {
    _S9_4 |= 0x1000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x6B,
      &s_composite_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_composite_game_effect_emitter_cook.__vftable = (survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>_vtbl *)&survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_composite_game_effect_emitter_cook, v10);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_composite_game_effect_emitter_cook__);
    v6 = v29;
  }
  if ( (_S9_4 & 0x2000) == 0 )
  {
    _S9_4 |= 0x2000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x6C,
      &s_random_permutation_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_random_permutation_game_effect_emitter_cook.__vftable = (survarium::composite_game_effect_emitter_cook<survarium::random_permutation_game_effect_emitter>_vtbl *)&survarium::composite_game_effect_emitter_cook<survarium::random_permutation_game_effect_emitter>::`vftable';
    vostok::resources::resources_manager::register_cook(&s_random_permutation_game_effect_emitter_cook, v11);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_random_permutation_game_effect_emitter_cook__);
    v6 = v30;
  }
  if ( (_S9_4 & 0x4000) == 0 )
  {
    _S9_4 |= 0x4000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x6D,
      &s_post_process_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_post_process_game_effect_emitter_cook.__vftable = (survarium::post_process_game_effect_emitter_cook_vtbl *)&survarium::post_process_game_effect_emitter_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_post_process_game_effect_emitter_cook, v12);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_post_process_game_effect_emitter_cook__);
    v6 = v31;
  }
  if ( (_S9_4 & 0x8000) == 0 )
  {
    _S9_4 |= 0x8000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x6E,
      &s_hud_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_hud_game_effect_emitter_cook.__vftable = (survarium::hud_game_effect_emitter_cook_vtbl *)&survarium::hud_game_effect_emitter_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_hud_game_effect_emitter_cook, v13);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_hud_game_effect_emitter_cook__);
    v6 = v32;
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S9_4) == 0 )
  {
    _S9_4 |= (unsigned int)&_sbh_sizeHeaderList;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x6F,
      &s_particle_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_particle_game_effect_emitter_cook.__vftable = (survarium::particle_game_effect_emitter_cook_vtbl *)&survarium::particle_game_effect_emitter_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_particle_game_effect_emitter_cook, v14);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_particle_game_effect_emitter_cook__);
    v6 = v33;
  }
  if ( ((unsigned int)&loc_20000 & _S9_4) == 0 )
  {
    _S9_4 |= (unsigned int)&loc_20000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x70,
      &s_sound_game_effect_emitter_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v35);
    s_sound_game_effect_emitter_cook.__vftable = (survarium::sound_game_effect_emitter_cook_vtbl *)&survarium::sound_game_effect_emitter_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_sound_game_effect_emitter_cook, v15);
    atexit((int (__cdecl *)())survarium::game_world::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_game_effect_emitter_cook__);
    v6 = v34;
  }
  if ( (_S6_4 & 1) == 0 )
  {
    _S6_4 |= 1u;
    vostok::collision::animated_object_cook::animated_object_cook(
      (vostok::collision::animated_object_cook *)v6,
      survarium::g_allocator);
    atexit((int (__cdecl *)())vostok::collision::initialize_animated_object_cook_::_2_::_dynamic_atexit_destructor_for__s_animated_object_cook__);
  }
}
