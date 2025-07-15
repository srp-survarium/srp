unsigned int __cdecl vostok::ai::get_count_of_needed_resources(
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour_resource_type_enum resource_type)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  const vostok::variant<32> **v9; // [esp+44h] [ebp-2Ch]
  vostok::configs::binary_config_value *goals_value; // [esp+48h] [ebp-28h]
  const vostok::configs::binary_config_value *v11; // [esp+4Ch] [ebp-24h]
  vostok::configs::binary_config_value *v12; // [esp+50h] [ebp-20h]
  const vostok::variant<32> **type; // [esp+58h] [ebp-18h]
  vostok::configs::binary_config_value *actions_value; // [esp+60h] [ebp-10h]
  const vostok::configs::binary_config_value *it_end; // [esp+64h] [ebp-Ch]
  vostok::configs::binary_config_value *it; // [esp+68h] [ebp-8h]
  unsigned int result; // [esp+6Ch] [ebp-4h] BYREF

  result = 0;
  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "actions") )
  {
    actions_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              behaviour_value,
                                                              "actions");
    it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)actions_value);
    it_end = vostok::configs::binary_config_value::end(actions_value);
    while ( it != it_end )
    {
      v2 = vostok::configs::binary_config_value::operator[](it, "id");
      type = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
      if ( (resource_type == resource_type_animation && type == (const vostok::variant<32> **)8
         || resource_type == resource_type_animation && type == (const vostok::variant<32> **)11
         || resource_type == resource_type_movement_target && type == (const vostok::variant<32> **)11
         || resource_type == resource_type_sound && type == (const vostok::variant<32> **)9
         || type == (const vostok::variant<32> **)10)
        && vostok::configs::binary_config_value::value_exists(it, "filter_sets") )
      {
        v4 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](it, "filter_sets");
        vostok::ai::get_resources_count_in_filter_sets(v4, resource_type, &result);
      }
      ++it;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "goals") )
  {
    goals_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            behaviour_value,
                                                            "goals");
    v12 = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)goals_value);
    v11 = vostok::configs::binary_config_value::end(goals_value);
    while ( v12 != v11 )
    {
      v5 = vostok::configs::binary_config_value::operator[](v12, "type");
      v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)v5);
      if ( (resource_type == resource_type_animation && v9 == (const vostok::variant<32> **)5
         || resource_type == resource_type_animation && v9 == (const vostok::variant<32> **)8
         || resource_type == resource_type_movement_target && v9 == (const vostok::variant<32> **)8
         || resource_type == resource_type_sound && v9 == (const vostok::variant<32> **)6
         || v9 == (const vostok::variant<32> **)7)
        && vostok::configs::binary_config_value::value_exists(v12, "filter_sets") )
      {
        v7 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](v12, "filter_sets");
        vostok::ai::get_resources_count_in_filter_sets(v7, resource_type, &result);
      }
      ++v12;
    }
  }
  return result;
}
