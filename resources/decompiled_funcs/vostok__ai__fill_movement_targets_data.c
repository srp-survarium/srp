void __cdecl vostok::ai::fill_movement_targets_data(
        vostok::configs::binary_config_value *filter_value,
        vostok::ai::behaviour *const new_behaviour,
        unsigned int *current_target_number)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::configs::binary_config_value *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  survarium::game_camera *v12; // ecx
  void *v13; // eax
  vostok::ai::movement_target *v14; // [esp+5Ch] [ebp-40h]
  vostok::configs::binary_config_value *subvalues; // [esp+68h] [ebp-34h]
  const vostok::configs::binary_config_value *it_end; // [esp+6Ch] [ebp-30h]
  const vostok::configs::binary_config_value *it; // [esp+70h] [ebp-2Ch]
  const vostok::math::float3 *velocity; // [esp+74h] [ebp-28h]
  const vostok::ai::animation_item *animation; // [esp+78h] [ebp-24h]
  const char *animation_name; // [esp+7Ch] [ebp-20h]
  const vostok::math::float3 *direction; // [esp+80h] [ebp-1Ch]
  const vostok::math::float3 *position; // [esp+88h] [ebp-14h]
  vostok::configs::binary_config_value *positions_values; // [esp+90h] [ebp-Ch]
  vostok::configs::binary_config_value *it_positions; // [esp+94h] [ebp-8h]
  const vostok::configs::binary_config_value *it_positions_end; // [esp+98h] [ebp-4h]

  positions_values = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                               filter_value,
                                                               "positions");
  it_positions = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)positions_values);
  it_positions_end = vostok::configs::binary_config_value::end(positions_values);
  while ( it_positions != it_positions_end )
  {
    v3 = vostok::configs::binary_config_value::operator[](it_positions, "target_point");
    position = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                               v4,
                                               (int)v3);
    v5 = vostok::configs::binary_config_value::operator[](
           it_positions,
           (char *)&stru_96A440.m_inverted_view.lines[2].elements[2]);
    direction = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                v6,
                                                (int)v5);
    v7 = vostok::configs::binary_config_value::operator[](it_positions, "velocity");
    velocity = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                               v8,
                                               (int)v7);
    v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   it_positions,
                                                   "animation");
    v10 = vostok::configs::binary_config_value::operator[](v9, "name");
    animation_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     v11,
                                     (int)v10);
    animation = vostok::ai::behaviour::find_animation_by_filename(new_behaviour, animation_name);
    survarium::weapon_user_dead_state::finalize(v12);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)current_target_number);
    v14 = (vostok::ai::movement_target *)operator new(0x60u, v13);
    if ( v14 )
      vostok::ai::movement_target::movement_target(v14, position, direction, velocity, animation);
    ++*current_target_number;
    ++it_positions;
  }
  if ( vostok::configs::binary_config_value::value_exists(filter_value, "filters") )
  {
    subvalues = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          filter_value,
                                                          "filters");
    it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)subvalues);
    it_end = vostok::configs::binary_config_value::end(subvalues);
    while ( it != it_end )
      vostok::ai::fill_movement_targets_data(it++, new_behaviour, current_target_number);
  }
}
