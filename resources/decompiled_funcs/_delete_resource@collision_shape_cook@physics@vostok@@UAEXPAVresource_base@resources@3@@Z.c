void __thiscall vostok::physics::collision_shape_cook::delete_resource(
        vostok::physics::collision_shape_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::base_allocator *v2; // edi
  _BYTE *v3; // ebx

  v2 = vostok::physics::g_ph_allocator;
  if ( resource )
  {
    v3 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    v2->call_free(v2, v3);
  }
}
