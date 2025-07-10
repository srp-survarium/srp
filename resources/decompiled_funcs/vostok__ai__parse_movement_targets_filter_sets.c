void __cdecl vostok::ai::parse_movement_targets_filter_sets(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *filters,
        vostok::ai::behaviour *const new_behaviour,
        unsigned int *current_target_number)
{
  char *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  char *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  char *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  unsigned int v10; // [esp-4h] [ebp-88h]
  vostok::configs::binary_config_value *params; // [esp+44h] [ebp-40h]
  vostok::configs::binary_config_value *it_param; // [esp+48h] [ebp-3Ch]
  const vostok::configs::binary_config_value *it_param_end; // [esp+4Ch] [ebp-38h]
  vostok::fixed_string<20> param_filter; // [esp+50h] [ebp-34h] BYREF
  unsigned int i; // [esp+70h] [ebp-14h]
  unsigned int max_params_count; // [esp+74h] [ebp-10h]
  const vostok::configs::binary_config_value *filters_value; // [esp+78h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_filters; // [esp+7Ch] [ebp-8h]
  const vostok::configs::binary_config_value *it_filters_end; // [esp+80h] [ebp-4h]

  it_filters = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(filters);
  it_filters_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)filters);
  while ( it_filters != it_filters_end )
  {
    filters_value = it_filters;
    max_params_count = 4;
    for ( i = 0; i < 4; ++i )
    {
      vostok::fixed_string<20>::fixed_string<20>(&param_filter);
      v10 = i;
      v3 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                     (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)i,
                     (int)&param_filter);
      vostok::sprintf(v3, 0x14u, "parameter%u_filter", v10);
      v5 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                     v4,
                     (int)&param_filter);
      if ( vostok::configs::binary_config_value::value_exists((vostok::configs::binary_config_value *)filters_value, v5) )
      {
        v7 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                       v6,
                       (int)&param_filter);
        params = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                           (vostok::configs::binary_config_value *)filters_value,
                                                           v7);
        it_param = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)params);
        it_param_end = vostok::configs::binary_config_value::end(params);
        while ( it_param != it_param_end )
        {
          v8 = vostok::configs::binary_config_value::operator[](it_param, "type");
          if ( stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)v8) == (const vostok::variant<32> **)5 )
            vostok::ai::fill_movement_targets_data(it_param, new_behaviour, current_target_number);
          ++it_param;
        }
      }
    }
    ++it_filters;
  }
}
