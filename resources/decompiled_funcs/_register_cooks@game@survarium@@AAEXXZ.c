void __usercall survarium::game::register_cooks(survarium::game *this@<ecx>, int a2@<eax>)
{
  int v3; // ecx
  char v4; // al
  survarium::project_cooker_simple *v5; // ecx

  if ( (_S11_0 & 1) == 0 )
  {
    _S11_0 |= 1u;
    survarium::animated_model_instance_cook::animated_model_instance_cook((survarium::animated_model_instance_cook *)this);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animated_model_instance_cook__);
  }
  if ( (_S11_0 & 2) == 0 )
  {
    _S11_0 |= 2u;
    survarium::game_material_manager_cook::game_material_manager_cook(&s_material_manager_cook, 0);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_material_manager_cook__);
  }
  if ( (_S11_0 & 4) == 0 )
  {
    v3 = *(_DWORD *)(a2 + 124);
    _S11_0 |= 4u;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3);
    survarium::project_cooker_simple::project_cooker_simple(v5, v4);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_simple_project_cook__);
  }
  if ( (_S11_0 & 8) == 0 )
  {
    _S11_0 |= 8u;
    survarium::animation_analysis_result_cook::animation_analysis_result_cook(&s_animation_analysis_result_cook);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animation_analysis_result_cook__);
  }
  vostok::resources::resources_manager::register_cook(&s_animation_analysis_result_cook);
  if ( (_S11_0 & 0x10) == 0 )
  {
    _S11_0 |= 0x10u;
    survarium::ladder_cook::ladder_cook(&s_ladder_cook);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_ladder_cook__);
  }
  vostok::resources::resources_manager::register_cook(&s_ladder_cook);
  if ( (_S11_0 & 0x20) == 0 )
  {
    _S11_0 |= 0x20u;
    survarium::weapon_user_animations_container_cook::weapon_user_animations_container_cook(&s_animation_container_cook);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_animation_container_cook__);
  }
  vostok::resources::resources_manager::register_cook(&s_animation_container_cook);
  if ( (_S11_0 & 0x40) == 0 )
  {
    _S11_0 |= 0x40u;
    survarium::victory_item_core_cook::victory_item_core_cook(&s_victory_item_cook);
    s_victory_item_cook.__vftable = (survarium::victory_item_cook_vtbl *)&survarium::victory_item_cook::`vftable';
    s_victory_item_cook.m_game_world = (survarium::game_world *)(a2 + 152);
    atexit(survarium::game::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_victory_item_cook__);
  }
}
