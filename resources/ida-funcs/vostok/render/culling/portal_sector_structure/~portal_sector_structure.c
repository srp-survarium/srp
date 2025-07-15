void __usercall vostok::render::culling::portal_sector_structure::~portal_sector_structure(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // ebx
  _BYTE *v4; // ebp
  _DWORD **v5; // edi
  int v6; // ebx
  _BYTE *v7; // ebp

  v2 = *(_DWORD *)(a2 + 300);
  *(_DWORD *)a2 = &vostok::render::culling::portal_sector_structure::`vftable';
  if ( v2 )
  {
    v3 = **(_DWORD **)(v2 + 16);
    v4 = __RTCastToVoid((void **)v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 68))(v2, 0);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v3 + 24))(v3, v4);
  }
  v5 = *(_DWORD ***)(a2 + 296);
  if ( v5 )
  {
    v6 = *v5[4];
    v7 = __RTCastToVoid(*(void ***)(a2 + 296));
    ((void (__thiscall *)(_DWORD **, _DWORD))(*v5)[17])(v5, 0);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v6 + 24))(v6, v7);
  }
  *(_DWORD *)(a2 + 292) = *(_DWORD *)(a2 + 288);
  if ( *(_DWORD *)(a2 + 284) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 264) + 24))(
      *(_DWORD *)(a2 + 264),
      *(_DWORD *)(a2 + 284));
    *(_DWORD *)(a2 + 284) = 0;
  }
  *(_DWORD *)(a2 + 276) = *(_DWORD *)(a2 + 272);
  if ( *(_DWORD *)(a2 + 268) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 264) + 24))(
      *(_DWORD *)(a2 + 264),
      *(_DWORD *)(a2 + 268));
    *(_DWORD *)(a2 + 268) = 0;
  }
  if ( *(_DWORD *)(a2 + 280) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 264) + 24))(
      *(_DWORD *)(a2 + 264),
      *(_DWORD *)(a2 + 280));
    *(_DWORD *)(a2 + 280) = 0;
  }
  *(_DWORD *)(a2 + 292) = *(_DWORD *)(a2 + 288);
  *(_DWORD *)(a2 + 276) = *(_DWORD *)(a2 + 272);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
