void __usercall vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::dec(
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // eax

  if ( *a2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(*a2 + 4), 0xFFFFFFFF) )
  {
    v2 = *a2;
    if ( v2 )
      (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(v2 + 8) + 24))(
        *(_DWORD *)(v2 + 8),
        v2,
        "vostok::physics::loose_ptr_data::destroy",
        "c:\\survarium.deploy\\sources\\vostok/loose_ptr_data_inline.h",
        20);
  }
}
