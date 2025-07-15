void __cdecl vostok::ai::retrieve_filename_from_position_data(
        vostok::configs::binary_config_value *filter_value,
        vostok::buffer_vector<vostok::resources::request> *requests)
{
  vostok::configs::binary_config_value *v2; // eax
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  vostok::configs::binary_config_value *subvalues; // [esp+40h] [ebp-28h]
  const vostok::configs::binary_config_value *it_end; // [esp+44h] [ebp-24h]
  const vostok::configs::binary_config_value *it; // [esp+48h] [ebp-20h]
  vostok::resources::request request; // [esp+4Ch] [ebp-1Ch] BYREF
  const vostok::configs::binary_config_value *value; // [esp+54h] [ebp-14h]
  unsigned int class_id; // [esp+58h] [ebp-10h]
  const vostok::configs::binary_config_value *positions_values; // [esp+5Ch] [ebp-Ch]
  const vostok::configs::binary_config_value *it_positions; // [esp+60h] [ebp-8h]
  const vostok::configs::binary_config_value *it_positions_end; // [esp+64h] [ebp-4h]

  positions_values = vostok::configs::binary_config_value::operator[](filter_value, "positions");
  it_positions = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)positions_values);
  it_positions_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)positions_values);
  while ( it_positions != it_positions_end )
  {
    value = it_positions;
    v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   (vostok::configs::binary_config_value *)it_positions,
                                                   "animation");
    v3 = vostok::configs::binary_config_value::operator[](v2, "name");
    request.path = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                   v4,
                                   (int)v3);
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   (vostok::configs::binary_config_value *)value,
                                                   "animation");
    v6 = vostok::configs::binary_config_value::operator[](v5, "type");
    class_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                               v7,
                               (int)v6);
    request.id = class_id;
    vostok::buffer_vector<vostok::resources::request>::push_back(requests, &request);
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
      vostok::ai::retrieve_filename_from_position_data(it++, requests);
  }
}
