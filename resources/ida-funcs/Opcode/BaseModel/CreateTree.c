bool __userpurge Opcode::BaseModel::CreateTree@<al>(
        Opcode::BaseModel *this@<ecx>,
        _DWORD *a2@<esi>,
        bool no_leaf,
        bool quantized)
{
  void **v4; // eax
  int v5; // edi
  _BYTE *v6; // ebp
  int v7; // eax
  int v8; // ecx
  int (__stdcall *v9)(int); // edx
  _DWORD *v10; // eax
  int v11; // ecx
  _DWORD *v13; // eax
  int v14; // ecx
  int (__stdcall *v15)(int); // edx
  _DWORD *v16; // eax
  int v17; // ecx
  _DWORD *v18; // eax
  int v19; // ecx

  if ( a2[4] )
  {
    v4 = (void **)a2[4];
    v5 = a2[5];
    if ( v4 )
    {
      v6 = __RTCastToVoid(v4);
      (**(void (__thiscall ***)(_DWORD, _DWORD))a2[4])(a2[4], 0);
      (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 24))(v5, v6);
      a2[4] = 0;
    }
    a2[4] = 0;
  }
  if ( no_leaf )
    a2[2] |= 2u;
  else
    a2[2] &= ~2u;
  if ( quantized )
    a2[2] |= 1u;
  else
    a2[2] &= ~1u;
  v7 = a2[2];
  v8 = a2[5];
  if ( (v7 & 2) != 0 )
  {
    v9 = *(int (__stdcall **)(int))(*(_DWORD *)v8 + 16);
    if ( (v7 & 1) != 0 )
    {
      v10 = (_DWORD *)v9(40);
      if ( v10 )
      {
        v11 = a2[5];
        v10[1] = 0;
        v10[3] = 0;
        v10[2] = v11;
        *v10 = &Opcode::AABBQuantizedNoLeafTree::`vftable';
        a2[4] = v10;
        return v10 != 0;
      }
    }
    else
    {
      v13 = (_DWORD *)v9(16);
      if ( v13 )
      {
        v14 = a2[5];
        v13[1] = 0;
        v13[3] = 0;
        v13[2] = v14;
        *v13 = &Opcode::AABBNoLeafTree::`vftable';
        a2[4] = v13;
        return v13 != 0;
      }
    }
  }
  else
  {
    v15 = *(int (__stdcall **)(int))(*(_DWORD *)v8 + 16);
    if ( (v7 & 1) != 0 )
    {
      v16 = (_DWORD *)v15(40);
      if ( v16 )
      {
        v17 = a2[5];
        v16[1] = 0;
        v16[3] = 0;
        v16[2] = v17;
        *v16 = &Opcode::AABBQuantizedTree::`vftable';
        a2[4] = v16;
        return v16 != 0;
      }
    }
    else
    {
      v18 = (_DWORD *)v15(16);
      if ( v18 )
      {
        v19 = a2[5];
        v18[1] = 0;
        v18[3] = 0;
        v18[2] = v19;
        *v18 = &Opcode::AABBCollisionTree::`vftable';
        a2[4] = v18;
        return v18 != 0;
      }
    }
  }
  a2[4] = 0;
  return 0;
}
