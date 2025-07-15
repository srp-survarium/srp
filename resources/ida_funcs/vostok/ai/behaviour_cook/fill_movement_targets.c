void __thiscall vostok::ai::behaviour_cook::fill_movement_targets(
        vostok::ai::behaviour_cook *this,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour *const new_behaviour)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // eax
  vostok::configs::binary_config_value *goals_value; // [esp+4Ch] [ebp-28h]
  const vostok::configs::binary_config_value *v10; // [esp+50h] [ebp-24h]
  vostok::configs::binary_config_value *v11; // [esp+54h] [ebp-20h]
  vostok::configs::binary_config_value *actions_value; // [esp+64h] [ebp-10h]
  const vostok::configs::binary_config_value *it_end; // [esp+68h] [ebp-Ch]
  vostok::configs::binary_config_value *it; // [esp+6Ch] [ebp-8h]
  unsigned int current_target_number; // [esp+70h] [ebp-4h] BYREF

  current_target_number = 0;
  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "actions") )
  {
    actions_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              behaviour_value,
                                                              "actions");
    it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)actions_value);
    it_end = vostok::configs::binary_config_value::end(actions_value);
    while ( it != it_end )
    {
      v3 = vostok::configs::binary_config_value::operator[](it, "id");
      if ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3) == (const vostok::variant<32> **)11
        && vostok::configs::binary_config_value::value_exists(it, "filter_sets") )
      {
        v5 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](it, "filter_sets");
        vostok::ai::parse_movement_targets_filter_sets(v5, new_behaviour, &current_target_number);
      }
      ++it;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "goals") )
  {
    goals_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            behaviour_value,
                                                            "goals");
    v11 = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)goals_value);
    v10 = vostok::configs::binary_config_value::end(goals_value);
    while ( v11 != v10 )
    {
      v6 = vostok::configs::binary_config_value::operator[](v11, "type");
      if ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)v6) == (const vostok::variant<32> **)8
        && vostok::configs::binary_config_value::value_exists(v11, "filter_sets") )
      {
        v8 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](v11, "filter_sets");
        vostok::ai::parse_movement_targets_filter_sets(v8, new_behaviour, &current_target_number);
      }
      ++v11;
    }
  }
}
