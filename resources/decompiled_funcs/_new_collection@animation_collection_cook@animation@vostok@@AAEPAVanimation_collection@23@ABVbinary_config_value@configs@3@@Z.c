void __usercall vostok::animation::animation_collection_cook::new_collection(
        vostok::configs::binary_config_value *collection@<eax>,
        vostok::animation::animation_collection_cook *this)
{
  vostok::animation::collection_playback_types v3; // ebx
  int v4; // esi
  vostok::animation::animation_collection *v5; // esi
  const vostok::configs::binary_config_value *v6; // eax
  unsigned int v7; // [esp+0h] [ebp-14h]
  bool cyclic_repeating_index; // [esp+Ch] [ebp-8h]
  bool can_repeat_successively; // [esp+10h] [ebp-4h]

  v3 = strcmp(
         (const char *)vostok::configs::binary_config_value::operator[](collection, "collection_type")->data.pointer,
         "random") != 0;
  can_repeat_successively = vostok::configs::binary_config_value::operator[](collection, "is_dont_repeat_previous")->data.pointer != 0;
  cyclic_repeating_index = vostok::configs::binary_config_value::operator[](collection, "is_cyclic_repeat")->data.pointer != 0;
  v4 = 0;
  if ( vostok::configs::binary_config_value::value_exists(collection, "animation_items") )
    v4 = 4 * (24 * vostok::configs::binary_config_value::operator[](collection, "animation_items")->count / 24);
  type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  v5 = (vostok::animation::animation_collection *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    &vostok::memory::g_resources_unmanaged_allocator,
                                                    v4 + 288);
  if ( v5 )
  {
    v6 = vostok::configs::binary_config_value::operator[](collection, "animation_items");
    vostok::animation::animation_collection::animation_collection(
      v5,
      v3,
      can_repeat_successively,
      cyclic_repeating_index,
      &v5[1],
      24 * v6->count / 24,
      v7);
  }
}
