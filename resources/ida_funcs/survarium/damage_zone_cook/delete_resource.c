void __thiscall survarium::damage_zone_cook::delete_resource(
        survarium::damage_zone_cook *this,
        vostok::resources::resource_base *resource)
{
  int f; // ebx
  _BYTE *v3; // edi
  void *v4; // esi

  f = (int)survarium::g_allocator.f_.f_;
  if ( resource )
  {
    v3 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    if ( v3 )
    {
      v4 = *(void **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v4, v3);
    }
  }
}
