void __thiscall vostok::sound::ogg_encoded_sound_interface_cook::delete_resource(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        vostok::resources::resource_base *res)
{
  void *v3; // eax
  _BYTE *inptr; // [esp+14h] [ebp+4h]

  v3 = (void *)*((_DWORD *)&res[4].m_memory_type_data + 1);
  if ( v3 )
  {
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      v3,
      "vostok::sound::ogg_encoded_sound_interface_cook::delete_resource",
      ".\\ogg_encoded_sound_interface_cook.cpp",
      83u);
    *((_DWORD *)&res[4].m_memory_type_data + 1) = 0;
  }
  if ( res )
  {
    inptr = __RTCastToVoid((void **)&res->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      inptr,
      "vostok::sound::ogg_encoded_sound_interface_cook::delete_resource",
      ".\\ogg_encoded_sound_interface_cook.cpp",
      84u);
  }
}
