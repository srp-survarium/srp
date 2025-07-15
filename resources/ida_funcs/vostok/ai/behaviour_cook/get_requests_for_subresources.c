void __thiscall vostok::ai::behaviour_cook::get_requests_for_subresources(
        vostok::ai::behaviour_cook *this,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::buffer_vector<vostok::resources::request> *requests,
        vostok::ai::behaviour_resource_type_enum resource_type)
{
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // eax
  const vostok::variant<32> **v10; // [esp+48h] [ebp-28h]
  vostok::configs::binary_config_value *goals_value; // [esp+4Ch] [ebp-24h]
  const vostok::configs::binary_config_value *v12; // [esp+50h] [ebp-20h]
  vostok::configs::binary_config_value *v13; // [esp+54h] [ebp-1Ch]
  const vostok::variant<32> **type; // [esp+5Ch] [ebp-14h]
  vostok::configs::binary_config_value *actions_value; // [esp+64h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+68h] [ebp-8h]
  vostok::configs::binary_config_value *it; // [esp+6Ch] [ebp-4h]

  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "actions") )
  {
    actions_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              behaviour_value,
                                                              "actions");
    it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)actions_value);
    it_end = vostok::configs::binary_config_value::end(actions_value);
    while ( it != it_end )
    {
      v4 = vostok::configs::binary_config_value::operator[](it, "id");
      type = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)v4);
      if ( (resource_type == resource_type_animation && type == (const vostok::variant<32> **)8
         || resource_type == resource_type_animation && type == (const vostok::variant<32> **)11
         || resource_type == resource_type_sound && type == (const vostok::variant<32> **)9
         || type == (const vostok::variant<32> **)10)
        && vostok::configs::binary_config_value::value_exists(it, "filter_sets") )
      {
        v6 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](it, "filter_sets");
        vostok::ai::parse_filter_sets(v6, resource_type, requests);
      }
      ++it;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(behaviour_value, "goals") )
  {
    goals_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            behaviour_value,
                                                            "goals");
    v13 = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)goals_value);
    v12 = vostok::configs::binary_config_value::end(goals_value);
    while ( v13 != v12 )
    {
      v7 = vostok::configs::binary_config_value::operator[](v13, "type");
      v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)v7);
      if ( (resource_type == resource_type_animation && v10 == (const vostok::variant<32> **)5
         || resource_type == resource_type_animation && v10 == (const vostok::variant<32> **)8
         || resource_type == resource_type_sound && v10 == (const vostok::variant<32> **)6
         || v10 == (const vostok::variant<32> **)7)
        && vostok::configs::binary_config_value::value_exists(v13, "filter_sets") )
      {
        v9 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](v13, "filter_sets");
        vostok::ai::parse_filter_sets(v9, resource_type, requests);
      }
      ++v13;
    }
  }
}
