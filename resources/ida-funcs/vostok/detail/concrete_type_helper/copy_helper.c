vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<unsigned char>::copy_helper(
        vostok::detail::concrete_type_helper<unsigned char> *this,
        vostok::mutable_buffer dest_buffer)
{
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<unsigned char>::`vftable';
  return (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<unsigned short>::copy_helper(
        vostok::detail::concrete_type_helper<unsigned short> *this,
        vostok::mutable_buffer dest_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  vostok::detail::abstract_type_helper *v4; // ecx
  _DWORD *v7; // [esp+8h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&dest_buffer);
  v7 = operator new(4u, v3);
  if ( !v7 )
    return 0;
  vostok::detail::abstract_type_helper::abstract_type_helper(v4, v7);
  *v7 = &vostok::detail::concrete_type_helper<unsigned short>::`vftable';
  return (vostok::detail::abstract_type_helper *)v7;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::particle::engine *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::particle::engine *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::particle::engine *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::grass_loading_data *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::grass_loading_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::grass_loading_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::inventory_cooker_data *>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::inventory_cooker_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<survarium::inventory_cooker_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::player_parameters_cooker_data *>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::player_parameters_cooker_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<survarium::player_parameters_cooker_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::particle::world *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::particle::world *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::particle::world *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::physics::world *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::physics::world *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::physics::world *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::base_game_scene *>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::base_game_scene *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<survarium::base_game_scene *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::engine::world *>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::engine::world *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::engine::world *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::player_profile const *>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::player_profile const *> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<survarium::player_profile const *>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  vostok::detail::abstract_type_helper *v4; // ecx
  _DWORD *v7; // [esp+8h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&dest_buffer);
  v7 = operator new(4u, v3);
  if ( !v7 )
    return 0;
  vostok::detail::abstract_type_helper::abstract_type_helper(v4, v7);
  *v7 = &vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::`vftable';
  return (vostok::detail::abstract_type_helper *)v7;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::output_window_configuration> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::player_initial_info>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::player_initial_info> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<survarium::player_initial_info>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::scene_configuration> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::`vftable';
  return (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::configs::binary_config_value> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
  return result;
}


vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::copy_helper(
        vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::`vftable';
  return result;
}
