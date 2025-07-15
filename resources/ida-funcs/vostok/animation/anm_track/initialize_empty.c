void __usercall vostok::animation::anm_track::initialize_empty(vostok::animation::anm_track *this@<ecx>, int a2@<edi>)
{
  vostok::animation::EtCurve *v2; // eax
  int v3; // eax
  vostok::animation::EtCurve *v4; // eax
  int v5; // eax
  vostok::animation::EtCurve *v6; // eax
  int v7; // eax
  vostok::animation::EtCurve *v8; // eax
  int v9; // eax
  vostok::animation::EtCurve *v10; // eax
  int v11; // eax
  vostok::animation::EtCurve *v12; // eax
  int v13; // eax
  int v14; // ebx
  vostok::animation::EtCurve *v15; // eax
  int v16; // eax

  v2 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                       *(vostok::memory::base_allocator **)(a2 + 12),
                                       (const char *const)0xCB);
  if ( v2 )
    vostok::animation::EtCurve::EtCurve(v2, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v3 = 0;
  **(_DWORD **)a2 = v3;
  v4 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                       *(vostok::memory::base_allocator **)(a2 + 12),
                                       (const char *const)0xCC);
  if ( v4 )
    vostok::animation::EtCurve::EtCurve(v4, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v5 = 0;
  *(_DWORD *)(*(_DWORD *)a2 + 4) = v5;
  v6 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                       *(vostok::memory::base_allocator **)(a2 + 12),
                                       (const char *const)0xCD);
  if ( v6 )
    vostok::animation::EtCurve::EtCurve(v6, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v7 = 0;
  *(_DWORD *)(*(_DWORD *)a2 + 8) = v7;
  v8 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                       *(vostok::memory::base_allocator **)(a2 + 12),
                                       (const char *const)0xD1);
  if ( v8 )
    vostok::animation::EtCurve::EtCurve(v8, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v9 = 0;
  *(_DWORD *)(*(_DWORD *)a2 + 12) = v9;
  v10 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                        *(vostok::memory::base_allocator **)(a2 + 12),
                                        (const char *const)0xD2);
  if ( v10 )
    vostok::animation::EtCurve::EtCurve(v10, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v11 = 0;
  *(_DWORD *)(*(_DWORD *)a2 + 16) = v11;
  v12 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                        *(vostok::memory::base_allocator **)(a2 + 12),
                                        (const char *const)0xD3);
  if ( v12 )
    vostok::animation::EtCurve::EtCurve(v12, *(vostok::memory::base_allocator **)(a2 + 12));
  else
    v13 = 0;
  v14 = 9;
  for ( *(_DWORD *)(*(_DWORD *)a2 + 20) = v13; v14 < *(_DWORD *)(a2 + 16); ++v14 )
  {
    v15 = (vostok::animation::EtCurve *)vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>(
                                          *(vostok::memory::base_allocator **)(a2 + 12),
                                          (const char *const)0xDD);
    if ( v15 )
      vostok::animation::EtCurve::EtCurve(v15, *(vostok::memory::base_allocator **)(a2 + 12));
    else
      v16 = 0;
    *(_DWORD *)(*(_DWORD *)a2 + 4 * v14) = v16;
  }
}
