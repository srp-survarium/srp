void __cdecl vostok::ai::retrieve_filename(
        vostok::configs::binary_config_value *filter_value,
        vostok::buffer_vector<vostok::resources::request> *requests)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::configs::binary_config_value *subvalues; // [esp+40h] [ebp-28h]
  const vostok::configs::binary_config_value *it_end; // [esp+44h] [ebp-24h]
  const vostok::configs::binary_config_value *it; // [esp+48h] [ebp-20h]
  vostok::resources::request request; // [esp+4Ch] [ebp-1Ch] BYREF
  const vostok::configs::binary_config_value *value; // [esp+54h] [ebp-14h]
  unsigned int class_id; // [esp+58h] [ebp-10h]
  const vostok::configs::binary_config_value *it_names; // [esp+5Ch] [ebp-Ch]
  const vostok::configs::binary_config_value *values; // [esp+60h] [ebp-8h]
  const vostok::configs::binary_config_value *it_names_end; // [esp+64h] [ebp-4h]

  values = vostok::configs::binary_config_value::operator[](filter_value, "filenames");
  it_names = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)values);
  it_names_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)values);
  while ( it_names != it_names_end )
  {
    value = it_names;
    v2 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it_names, "name");
    request.path = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                   v3,
                                   (int)v2);
    v4 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)value, "type");
    class_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                               v5,
                               (int)v4);
    request.id = class_id;
    vostok::buffer_vector<vostok::resources::request>::push_back(requests, &request);
    ++it_names;
  }
  if ( vostok::configs::binary_config_value::value_exists(filter_value, "filters") )
  {
    subvalues = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          filter_value,
                                                          "filters");
    it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)subvalues);
    it_end = vostok::configs::binary_config_value::end(subvalues);
    while ( it != it_end )
      vostok::ai::retrieve_filename(it++, requests);
  }
}
