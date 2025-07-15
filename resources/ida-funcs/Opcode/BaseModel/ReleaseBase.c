void __usercall Opcode::BaseModel::ReleaseBase(Opcode::BaseModel *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  int v3; // ebx
  int v4; // esi
  _BYTE *v5; // ebx

  if ( *(_DWORD *)(a2 + 12) )
  {
    v2 = *(_DWORD *)(a2 + 12);
    v3 = *(_DWORD *)(a2 + 20);
    if ( v2 )
    {
      Opcode::AABBTree::Release((Opcode::AABBTree *)this, v2);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 24))(v3, v2);
      *(_DWORD *)(a2 + 12) = 0;
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  if ( *(_DWORD *)(a2 + 16) )
  {
    v4 = *(_DWORD *)(a2 + 20);
    v5 = __RTCastToVoid(*(void ***)(a2 + 16));
    (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 16))(*(_DWORD *)(a2 + 16), 0);
    (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v4 + 24))(v4, v5);
    *(_DWORD *)(a2 + 16) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
}
