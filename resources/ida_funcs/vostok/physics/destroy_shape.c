void __usercall vostok::physics::destroy_shape(vostok::physics::bt_collision_shape *shape@<esi>)
{
  vostok::memory::base_allocator *v1; // edi
  _BYTE *v2; // ebx

  v1 = vostok::physics::g_ph_allocator;
  if ( shape )
  {
    v2 = __RTCastToVoid((void **)&shape->__vftable);
    ((void (__thiscall *)(vostok::physics::bt_collision_shape *, _DWORD))shape->~vostok::resources::resource_base)(
      shape,
      0);
    v1->call_free(v1, v2);
  }
}
