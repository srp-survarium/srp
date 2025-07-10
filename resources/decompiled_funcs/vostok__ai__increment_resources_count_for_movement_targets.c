void __cdecl vostok::ai::increment_resources_count_for_movement_targets(
        vostok::configs::binary_config_value *filter_value,
        unsigned int *result)
{
  vostok::configs::binary_config_value *subvalues; // [esp+24h] [ebp-10h]
  const vostok::configs::binary_config_value *it_end; // [esp+28h] [ebp-Ch]
  const vostok::configs::binary_config_value *it; // [esp+2Ch] [ebp-8h]
  vostok::configs::binary_config_value *values; // [esp+30h] [ebp-4h]

  values = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                     filter_value,
                                                     "positions");
  *result += vostok::configs::binary_config_value::size(values);
  if ( vostok::configs::binary_config_value::value_exists(filter_value, "filters") )
  {
    subvalues = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          filter_value,
                                                          "filters");
    it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)subvalues);
    it_end = vostok::configs::binary_config_value::end(subvalues);
    while ( it != it_end )
      vostok::ai::increment_resources_count_for_movement_targets(it++, result);
  }
}
