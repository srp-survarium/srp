void __usercall survarium::game::hide_player_name(survarium::game *this@<ecx>, int a2@<esi>)
{
  int v2; // edi
  int v3; // ecx

  if ( *(_BYTE *)(a2 + 15156) )
  {
    v2 = *(_DWORD *)(a2 + 348);
    if ( *(_BYTE *)(a2 + 15152) )
    {
      v3 = *(_DWORD *)(a2 + 15144);
      *(_BYTE *)(a2 + 15152) = 0;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 152))(v3, 0);
      *(_BYTE *)(*(_DWORD *)(a2 + 15148) + 4) = 1;
    }
    Scaleform::RefCountNTSImpl::Release(*(Scaleform::RefCountNTSImpl **)(a2 + 15144));
    *(_DWORD *)(a2 + 15144) = 0;
    *(_DWORD *)(a2 + 15148) = 0;
    *(_BYTE *)(v2 + 4) = 1;
  }
  *(_BYTE *)(a2 + 15156) = 0;
}
