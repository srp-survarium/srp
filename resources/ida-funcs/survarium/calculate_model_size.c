unsigned int __cdecl survarium::calculate_model_size(vostok::configs::binary_config_value *model_value)
{
  vostok::configs::binary_config_value *affects_value; // [esp+60h] [ebp-3Ch]
  vostok::configs::binary_config_value *bdbs_value; // [esp+6Ch] [ebp-30h]
  vostok::configs::binary_config_value *types_value; // [esp+70h] [ebp-2Ch]
  vostok::configs::binary_config_value *thresholds_value; // [esp+74h] [ebp-28h]
  vostok::configs::binary_config_value *it_type; // [esp+78h] [ebp-24h]
  const vostok::configs::binary_config_value *it_type_end; // [esp+7Ch] [ebp-20h]
  vostok::configs::binary_config_value *it_threshold; // [esp+84h] [ebp-18h]
  const vostok::configs::binary_config_value *it_threshold_end; // [esp+88h] [ebp-14h]
  unsigned int result; // [esp+8Ch] [ebp-10h]
  unsigned int resulta; // [esp+8Ch] [ebp-10h]
  vostok::configs::binary_config_value *it_model; // [esp+90h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_model_end; // [esp+94h] [ebp-8h]

  result = 184 * vostok::configs::binary_config_value::size(model_value) + 832;
  it_model = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)model_value);
  it_model_end = vostok::configs::binary_config_value::end(model_value);
  while ( it_model != it_model_end )
  {
    types_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            it_model,
                                                            "hit_types");
    resulta = result + 48 * vostok::configs::binary_config_value::size(types_value);
    it_type = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)types_value);
    it_type_end = vostok::configs::binary_config_value::end(types_value);
    while ( it_type != it_type_end )
    {
      bdbs_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                             it_type,
                                                             "bdb_coeff");
      resulta += 8 * vostok::configs::binary_config_value::size(bdbs_value);
      ++it_type;
    }
    thresholds_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 it_model,
                                                                 "thresholds");
    result = resulta + 16 * vostok::configs::binary_config_value::size(thresholds_value);
    it_threshold = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)thresholds_value);
    it_threshold_end = vostok::configs::binary_config_value::end(thresholds_value);
    while ( it_threshold != it_threshold_end )
    {
      affects_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                it_threshold,
                                                                "affects");
      result += 4 * vostok::configs::binary_config_value::size(affects_value);
      ++it_threshold;
    }
    ++it_model;
  }
  return result;
}
