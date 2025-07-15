void __thiscall vostok::sound::composite_sound_cook::create_sound(
        vostok::sound::composite_sound_cook *this,
        const vostok::configs::binary_config_value *composite)
{
  unsigned int v3; // ebp
  int v5; // esi
  const char *v6; // eax
  void *unmanaged_memory; // esi
  DWORD TickCount; // eax
  int v9; // eax
  __int16 pointer; // [esp+14h] [ebp+4h]

  v3 = 0;
  v5 = 0;
  pointer = 0;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)composite,
         (unsigned int)"sound_items") )
  {
    v3 = 24 * vostok::configs::binary_config_value::operator[](composite, "sound_items")->count / 24;
    v5 = 24 * v3;
    if ( vostok::configs::binary_config_value::operator[](composite, "use_master_layer_index")->data.pointer )
      pointer = (__int16)vostok::configs::binary_config_value::operator[](composite, "master_layer_index")->data.pointer;
    else
      pointer = -1;
  }
  v6 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = vostok::resources::allocate_unmanaged_memory(v5 + 288, v6);
  if ( unmanaged_memory )
  {
    TickCount = GetTickCount();
    vostok::sound::composite_sound::composite_sound(
      (vostok::sound::composite_sound *)unmanaged_memory,
      v3,
      (stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,vostok::sound::composite_sound_params> *)unmanaged_memory
    + 12,
      TickCount);
  }
  else
  {
    v9 = 0;
  }
  *(_WORD *)(v9 + 268) = pointer;
}
