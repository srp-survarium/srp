void __usercall vostok::physics::destroy_animated_rigid_body(
        vostok::physics::bt_animated_rigid_body *body@<esi>,
        vostok::memory::base_allocator *allocator)
{
  _BYTE *v2; // edi

  if ( body )
  {
    v2 = __RTCastToVoid((void **)&body->__vftable);
    ((void (__thiscall *)(vostok::physics::bt_animated_rigid_body *, _DWORD))body->~vostok::physics::bt_animated_rigid_body)(
      body,
      0);
    allocator->call_free(allocator, v2);
  }
}
