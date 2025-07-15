void __cdecl vostok::ai::fill_characters(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *dictionary,
        vostok::fixed_vector<stlp_std::pair<char *,unsigned int>,32> *objects)
{
  const vostok::configs::binary_config_value *v2; // eax
  vostok::configs::binary_config_value v3; // [esp+18h] [ebp-64h]
  char *v4; // [esp+44h] [ebp-38h]
  vostok::configs::binary_config_value v5; // [esp+4Ch] [ebp-30h] BYREF
  stlp_std::pair<char *,unsigned int> v6; // [esp+68h] [ebp-14h] BYREF
  const vostok::configs::binary_config_value *value; // [esp+70h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+74h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+78h] [ebp-4h]

  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(dictionary);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)dictionary);
  while ( it != it_end )
  {
    value = it;
    v3 = *vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it, "id");
    v2 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)value, "name");
    v4 = vostok::ai::clone_string_from_config(v2);
    v5 = v3;
    v6.first = v4;
    v6.second = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v4,
                                (int)&v5);
    vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(objects, &v6);
    ++it;
  }
}
