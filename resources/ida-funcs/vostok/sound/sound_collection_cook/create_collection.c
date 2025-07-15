void __thiscall vostok::sound::sound_collection_cook::create_collection(
        vostok::sound::sound_collection_cook *this,
        const vostok::configs::binary_config_value *collection)
{
  const char **v3; // eax
  vostok::sound::collection_playback_types v4; // esi
  vostok::configs::binary_config_value *v5; // ecx
  unsigned int v6; // ebx
  const char *v7; // eax
  void *unmanaged_memory; // edi
  DWORD TickCount; // eax
  bool can_repeat_successively; // [esp+10h] [ebp-4h]
  unsigned __int16 pointer; // [esp+1Ch] [ebp+8h]

  v3 = (const char **)vostok::configs::binary_config_value::operator[](collection, "type");
  v4 = vostok::strings::compare(*v3, "random") != 0;
  can_repeat_successively = vostok::configs::binary_config_value::operator[](
                              collection,
                              "dont_repeat_sound_successively")->data.pointer != 0;
  pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](collection, "cyclic_repeat_from_sound")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)collection, (unsigned int)"sound_items") )
    v6 = 24 * vostok::configs::binary_config_value::operator[](collection, "sound_items")->count / 24;
  else
    v6 = 0;
  v7 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = vostok::resources::allocate_unmanaged_memory(16 * (v6 + 19), v7);
  if ( unmanaged_memory )
  {
    TickCount = GetTickCount();
    vostok::sound::sound_collection::sound_collection(
      (vostok::sound::sound_collection *)unmanaged_memory,
      v6,
      v4,
      can_repeat_successively,
      pointer,
      (stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,vostok::sound::sound_collection_params> *)unmanaged_memory
    + 19,
      TickCount);
  }
}
