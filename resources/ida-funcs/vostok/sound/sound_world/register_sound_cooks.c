void __usercall vostok::sound::sound_world::register_sound_cooks(
        vostok::sound::sound_world *this@<ecx>,
        vostok::sound::sound_world *a2@<edi>)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v5; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v7; // ecx
  vostok::sound::sound_world *v8; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v9; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v10; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v11; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v12; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v13; // [esp-4h] [ebp-10h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v14; // [esp-4h] [ebp-10h]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v15; // [esp+0h] [ebp-Ch]

  if ( (_S5_10 & 1) == 0 )
  {
    _S5_10 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x102,
      &s_sound_cll_cook,
      (vostok::resources::cook_base::reuse_enum)(a2->m_editor_world_user == 0),
      0xFFFFFFFC,
      0,
      v15);
    s_sound_cll_cook.__vftable = (vostok::sound::sound_collection_cook_vtbl *)&vostok::sound::sound_collection_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_cll_cook__);
    this = v8;
  }
  vostok::resources::resources_manager::register_cook(
    &s_sound_cll_cook,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)this);
  if ( (_S5_10 & 2) == 0 )
  {
    _S5_10 |= 2u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x101,
      &s_composite_sound_cook,
      (vostok::resources::cook_base::reuse_enum)(a2->m_editor_world_user == 0),
      0xFFFFFFFC,
      0,
      v15);
    s_composite_sound_cook.__vftable = (vostok::sound::composite_sound_cook_vtbl *)&vostok::sound::composite_sound_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_composite_sound_cook__);
    v2 = v9;
  }
  vostok::resources::resources_manager::register_cook(&s_composite_sound_cook, v2);
  if ( (_S5_10 & 4) == 0 )
  {
    _S5_10 |= 4u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x100,
      &s_single_sound_cook,
      (vostok::resources::cook_base::reuse_enum)(a2->m_editor_world_user == 0),
      0xFFFFFFFC,
      0,
      v15);
    s_single_sound_cook.__vftable = (vostok::sound::single_sound_cook_vtbl *)&vostok::sound::single_sound_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_single_sound_cook__);
    v3 = v10;
  }
  vostok::resources::resources_manager::register_cook(&s_single_sound_cook, v3);
  if ( (_S5_10 & 8) == 0 )
  {
    _S5_10 |= 8u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x28,
      &s_encoded_sound_with_qualities_cook,
      reuse_true,
      0xFFFFFFFC,
      0,
      v15);
    s_encoded_sound_with_qualities_cook.__vftable = (vostok::sound::encoded_sound_with_qualities_cook_vtbl *)&vostok::sound::encoded_sound_with_qualities_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_encoded_sound_with_qualities_cook__);
    v4 = v11;
  }
  vostok::resources::resources_manager::register_cook(&s_encoded_sound_with_qualities_cook, v4);
  if ( (_S5_10 & 0x10) == 0 )
  {
    _S5_10 |= 0x10u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x29,
      &s_ogg_encoded_sound_interface_cook,
      reuse_true,
      0xFFFFFFFC,
      0,
      v15);
    s_ogg_encoded_sound_interface_cook.__vftable = (vostok::sound::ogg_encoded_sound_interface_cook_vtbl *)&vostok::sound::ogg_encoded_sound_interface_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_ogg_encoded_sound_interface_cook__);
    v5 = v12;
  }
  vostok::resources::resources_manager::register_cook(&s_ogg_encoded_sound_interface_cook, v5);
  if ( (_S5_10 & 0x20) == 0 )
  {
    _S5_10 |= 0x20u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x2A,
      &s_sound_spl_cook,
      (vostok::resources::cook_base::reuse_enum)(a2->m_editor_world_user == 0),
      0xFFFFFFFC,
      0,
      v15);
    s_sound_spl_cook.__vftable = (vostok::sound::sound_spl_cook_vtbl *)&vostok::sound::sound_spl_cook::`vftable';
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_spl_cook__);
    v6 = v13;
  }
  vostok::resources::resources_manager::register_cook(&s_sound_spl_cook, v6);
  if ( (_S5_10 & 0x40) == 0 )
  {
    _S5_10 |= 0x40u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x27,
      &s_sound_scene_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v15);
    s_sound_scene_cook.__vftable = (vostok::sound::sound_scene_cook_vtbl *)&vostok::sound::sound_scene_cook::`vftable';
    s_sound_scene_cook.m_sound_world = a2;
    atexit((int (__cdecl *)())vostok::sound::sound_world::register_sound_cooks_::_2_::_dynamic_atexit_destructor_for__s_sound_scene_cook__);
    v7 = v14;
  }
  vostok::resources::resources_manager::register_cook(&s_sound_scene_cook, v7);
}
