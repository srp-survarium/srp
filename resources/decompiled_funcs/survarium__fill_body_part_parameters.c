void __usercall survarium::fill_body_part_parameters(
        float a1@<xmm0>,
        survarium::body_part_parameters *body_part,
        survarium::damage_model *const model,
        vostok::memory::stack_allocator *allocator,
        vostok::configs::binary_config_value *part_value)
{
  survarium::affects_threshold *new_threshold; // [esp+20h] [ebp-28h]
  survarium::hit_type_parameters *hit_type_params; // [esp+2Ch] [ebp-1Ch]
  vostok::configs::binary_config_value *types_value; // [esp+30h] [ebp-18h]
  vostok::configs::binary_config_value *thresholds_value; // [esp+34h] [ebp-14h]
  vostok::configs::binary_config_value *it_type; // [esp+38h] [ebp-10h]
  const vostok::configs::binary_config_value *it_type_end; // [esp+3Ch] [ebp-Ch]
  vostok::configs::binary_config_value *it_threshold; // [esp+40h] [ebp-8h]
  const vostok::configs::binary_config_value *it_threshold_end; // [esp+44h] [ebp-4h]

  types_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          part_value,
                                                          "hit_types");
  it_type = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)types_value);
  it_type_end = vostok::configs::binary_config_value::end(types_value);
  while ( it_type != it_type_end )
  {
    hit_type_params = survarium::create_hit_type_parameters(a1, model, allocator, it_type);
    survarium::body_part_parameters::add_hit_type(body_part, (survarium::game_camera *)hit_type_params);
    ++it_type;
  }
  thresholds_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                               part_value,
                                                               "thresholds");
  it_threshold = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)thresholds_value);
  it_threshold_end = vostok::configs::binary_config_value::end(thresholds_value);
  while ( it_threshold != it_threshold_end )
  {
    new_threshold = survarium::create_threshold(a1, allocator, it_threshold, model);
    survarium::body_part_parameters::add_threshold(body_part, (survarium::game_camera *)new_threshold);
    ++it_threshold;
  }
}
