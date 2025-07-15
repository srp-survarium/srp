void __usercall survarium::simple_animation_controller::~simple_animation_controller(
        survarium::simple_animation_controller *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  int v4; // eax

  *(_DWORD *)a2 = &survarium::simple_animation_controller::`vftable';
  v3 = *(_DWORD *)(a2 + 16);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  v4 = *(_DWORD *)(a2 + 8);
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 8) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 8));
  }
}
