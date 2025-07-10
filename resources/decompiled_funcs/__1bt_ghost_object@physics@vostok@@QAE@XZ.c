void __usercall vostok::physics::bt_ghost_object::~bt_ghost_object(
        vostok::physics::bt_ghost_object *this@<ecx>,
        int a2@<esi>)
{
  void **v2; // eax
  vostok::memory::base_allocator *v3; // edi
  _BYTE *v4; // ebp
  int v5; // eax
  void *v6; // eax

  *(_DWORD *)a2 = &vostok::physics::bt_ghost_object::`vftable';
  v2 = *(void ***)(a2 + 16);
  v3 = vostok::physics::g_ph_allocator;
  if ( v2 )
  {
    v4 = __RTCastToVoid(v2);
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 4))(*(_DWORD *)(a2 + 16), 0);
    v3->call_free(v3, v4);
    *(_DWORD *)(a2 + 16) = 0;
  }
  v5 = *(_DWORD *)(a2 + 12);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 12) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 12));
  if ( --*(_DWORD *)(*(_DWORD *)(a2 + 4) + 4) )
  {
    **(_DWORD **)(a2 + 4) = 0;
  }
  else
  {
    v6 = *(void **)(a2 + 4);
    if ( v6 )
    {
      pt3free(v6);
      *(_DWORD *)(a2 + 4) = 0;
    }
  }
}
