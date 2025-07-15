void __thiscall vostok::collision::collision_cook::delete_resource(
        vostok::collision::collision_cook *this,
        vostok::resources::resource_base *resource)
{
  _BYTE *v2; // edi

  if ( resource )
  {
    resource->__vftable[1].log_string(
      resource,
      (vostok::fixed_string<512> *)&vostok::memory::g_resources_unmanaged_allocator);
    v2 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    vostok::memory::g_resources_unmanaged_allocator.call_free(&vostok::memory::g_resources_unmanaged_allocator, v2);
  }
}
