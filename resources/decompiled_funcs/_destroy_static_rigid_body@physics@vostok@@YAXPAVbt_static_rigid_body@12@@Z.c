void __usercall vostok::physics::destroy_static_rigid_body(vostok::physics::bt_static_rigid_body *body@<esi>)
{
  vostok::memory::base_allocator *v1; // edi
  _BYTE *v2; // ebx

  v1 = vostok::physics::g_ph_allocator;
  if ( body )
  {
    v2 = __RTCastToVoid((void **)&body->__vftable);
    ((void (__thiscall *)(vostok::physics::bt_static_rigid_body *, _DWORD))body->~vostok::physics::bt_static_rigid_body)(
      body,
      0);
    v1->call_free(v1, v2);
  }
}
