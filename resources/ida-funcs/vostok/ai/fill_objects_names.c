void __cdecl vostok::ai::fill_objects_names(
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *dictionary,
        vostok::buffer_vector<void const *> *objects)
{
  void *value; // [esp+1Ch] [ebp-Ch] BYREF
  const vostok::configs::binary_config_value *it_end; // [esp+20h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+24h] [ebp-4h]

  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(dictionary);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)dictionary);
  while ( it != it_end )
  {
    value = vostok::ai::clone_string_from_config(it);
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(objects, (const void **)&value);
    ++it;
  }
}
