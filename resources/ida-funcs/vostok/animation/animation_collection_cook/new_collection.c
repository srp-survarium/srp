void __thiscall vostok::animation::animation_collection_cook::new_collection(
        vostok::animation::animation_collection_cook *this,
        const vostok::configs::binary_config_value *collection)
{
  const char **v2; // eax
  vostok::animation::collection_playback_types v3; // ebx
  int v4; // esi
  vostok::configs::binary_config_value *v5; // ecx
  const char *v6; // eax
  void *unmanaged_memory; // esi
  const vostok::configs::binary_config_value *v8; // eax
  unsigned int v9; // [esp+0h] [ebp-14h]
  bool can_repeat_successively; // [esp+Ch] [ebp-8h]
  bool is_cyclic_repeating; // [esp+10h] [ebp-4h]

  v2 = (const char **)vostok::configs::binary_config_value::operator[](collection, "collection_type");
  v3 = vostok::strings::compare(*v2, "random") != 0;
  v4 = 0;
  can_repeat_successively = vostok::configs::binary_config_value::operator[](collection, "is_dont_repeat_previous")->data.pointer != 0;
  is_cyclic_repeating = vostok::configs::binary_config_value::operator[](collection, "is_cyclic_repeat")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)collection, (unsigned int)"animation_items") )
    v4 = 4 * (24 * vostok::configs::binary_config_value::operator[](collection, "animation_items")->count / 24);
  v6 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = vostok::resources::allocate_unmanaged_memory(v4 + 296, v6);
  if ( unmanaged_memory )
  {
    v8 = vostok::configs::binary_config_value::operator[](collection, "animation_items");
    vostok::animation::animation_collection::animation_collection(
      (vostok::animation::animation_collection *)unmanaged_memory,
      (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *)unmanaged_memory
    + 74,
      (vostok::resources::unmanaged_resource *)0x18,
      v3,
      can_repeat_successively,
      is_cyclic_repeating,
      24 * v8->count / 24,
      v9);
  }
}
