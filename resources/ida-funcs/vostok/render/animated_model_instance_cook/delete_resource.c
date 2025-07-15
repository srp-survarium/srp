void __thiscall vostok::render::animated_model_instance_cook::delete_resource(
        vostok::render::animated_model_instance_cook *this,
        vostok::resources::resource_base *resource)
{
  _BYTE *v2; // edi

  if ( resource )
  {
    v2 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    vostok::memory::g_resources_unmanaged_allocator.call_free(&vostok::memory::g_resources_unmanaged_allocator, v2);
  }
}
