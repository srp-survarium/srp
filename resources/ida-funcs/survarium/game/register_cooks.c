void __thiscall survarium::game::register_cooks(survarium::game *this, int a2)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  int *v3; // ecx
  int v4; // eax
  char v5; // al
  survarium::project_cooker_simple *v6; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v7; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v8; // ecx
  survarium::victory_item_cook *v9; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v10; // ecx
  survarium::game *v11; // [esp-4h] [ebp-14h]
  survarium::game *v12; // [esp-4h] [ebp-14h]
  survarium::game *v13; // [esp-4h] [ebp-14h]
  survarium::game *v14; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v15; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v16; // [esp-4h] [ebp-14h]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v17; // [esp+0h] [ebp-10h]

  if ( (_S15_0 & 1) == 0 )
  {
    _S15_0 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x60,
      &s_animated_model_instance_cook,
      reuse_false,
      0xFFFFFFFC,
      0,
      v17);
    s_animated_model_instance_cook.__vftable = (survarium::animated_model_instance_cook_vtbl *)&survarium::animated_model_instance_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animated_model_instance_cook__);
    this = v11;
  }
  if ( (_S15_0 & 2) == 0 )
  {
    _S15_0 |= 2u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x52,
      &s_material_manager_cook,
      reuse_true,
      0xFFFFFFFD,
      0,
      v17);
    s_material_manager_cook.__vftable = (survarium::game_material_manager_cook_vtbl *)&survarium::game_material_manager_cook::`vftable';
    s_material_manager_cook.m_server_usage = 0;
    vostok::resources::resources_manager::register_cook(&s_material_manager_cook, v2);
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_material_manager_cook__);
    this = v12;
  }
  if ( (_S15_0 & 4) == 0 )
  {
    v3 = *(int **)(a2 + 148);
    v4 = *v3;
    _S15_0 |= 4u;
    v5 = (*(int (__thiscall **)(int *))(v4 + 12))(v3);
    survarium::project_cooker_simple::project_cooker_simple(v6, v5);
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_simple_project_cook__);
    this = v13;
  }
  if ( (_S15_0 & 8) == 0 )
  {
    _S15_0 |= 8u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x74,
      &s_animation_analysis_result_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v17);
    s_animation_analysis_result_cook.__vftable = (survarium::animation_analysis_result_cook_vtbl *)&survarium::animation_analysis_result_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animation_analysis_result_cook__);
    this = v14;
  }
  vostok::resources::resources_manager::register_cook(
    &s_animation_analysis_result_cook,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)this);
  if ( (_S15_0 & 0x10) == 0 )
  {
    _S15_0 |= 0x10u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x75,
      &s_ladder_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v17);
    s_ladder_cook.__vftable = (survarium::ladder_cook_vtbl *)&survarium::ladder_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_ladder_cook__);
    v7 = v15;
  }
  vostok::resources::resources_manager::register_cook(&s_ladder_cook, v7);
  if ( (_S15_0 & 0x20) == 0 )
  {
    _S15_0 |= 0x20u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x77,
      &s_animation_container_cook,
      reuse_true,
      0xFFFFFFFD,
      0,
      v17);
    s_animation_container_cook.__vftable = (survarium::weapon_user_animations_container_cook_vtbl *)&survarium::weapon_user_animations_container_cook::`vftable';
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animation_container_cook__);
    v8 = v16;
  }
  vostok::resources::resources_manager::register_cook(&s_animation_container_cook, v8);
  if ( (_S15_0 & 0x40) == 0 )
  {
    _S15_0 |= 0x40u;
    survarium::victory_item_cook::victory_item_cook(v9, (survarium::game_world *)(a2 + 192));
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_victory_item_cook__);
  }
  if ( (_S15_0 & 0x80u) == 0 )
  {
    _S15_0 |= 0x80u;
    vostok::resources::cook_base::cook_base(
      &s_victory_items_container_cook,
      victory_item_container_class,
      0xFFFFFFFD,
      reuse_false,
      0,
      0xFFFFFFFD);
    s_victory_items_container_cook.__vftable = (survarium::victory_items_container_cook_vtbl *)&survarium::victory_items_container_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_victory_items_container_cook, v10);
    atexit((int (__cdecl *)())survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_victory_items_container_cook__);
  }
}
