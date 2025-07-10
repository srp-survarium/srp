void __usercall survarium::single_position_animation_controller::~single_position_animation_controller(
        survarium::single_position_animation_controller *this@<ecx>,
        int a2@<eax>)
{
  int f; // ecx
  char *v4; // esi
  int v5; // ebp
  char *v6; // eax
  malloc_state *v7; // esi
  char *v8; // eax
  malloc_state *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax

  f = (int)survarium::g_allocator.f_.f_;
  *(_DWORD *)a2 = &survarium::single_position_animation_controller::`vftable';
  v4 = *(char **)(a2 + 96);
  v5 = f;
  if ( v4 )
  {
    survarium::animations_search_service::~animations_search_service((survarium::animations_search_service *)f, v4);
    v6 = v4;
    v7 = *(malloc_state **)(v5 + 20);
    *(_BYTE *)(v5 + 42) = 0;
    vostok_mspace_free(v7, v6);
    f = (int)survarium::g_allocator.f_.f_;
    *(_DWORD *)(a2 + 96) = 0;
  }
  v8 = *(char **)(a2 + 100);
  if ( v8 )
  {
    v9 = *(malloc_state **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v9, v8);
    *(_DWORD *)(a2 + 100) = 0;
  }
  if ( *(_DWORD *)(a2 + 112) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 120) + 24))(
      *(_DWORD *)(a2 + 120),
      *(_DWORD *)(a2 + 112));
  v10 = *(_DWORD *)(a2 + 92);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 92) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 92));
  v11 = *(_DWORD *)(a2 + 88);
  if ( v11 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 88) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 88));
  v12 = *(_DWORD *)(a2 + 44);
  if ( v12 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v12 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 44) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 44));
  }
}
