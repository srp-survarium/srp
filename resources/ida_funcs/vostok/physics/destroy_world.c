void __usercall vostok::physics::destroy_world(vostok::physics::world *w@<esi>)
{
  _BYTE *v1; // edi

  w->destroy(w);
  v1 = __RTCastToVoid((void **)&w->__vftable);
  ((void (__thiscall *)(vostok::physics::world *, _DWORD))w->~vostok::physics::world)(w, 0);
  vostok::memory::g_mt_allocator.call_free(&vostok::memory::g_mt_allocator, v1);
}
