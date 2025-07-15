void __thiscall survarium::pvp_match_core::on_match_ready(survarium::pvp_match_core *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  void (__thiscall ***v5)(_DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // eax
  void (__thiscall **v6)(_DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
  _DWORD *v7; // esi
  int v8; // edi
  _DWORD *v9; // ebx
  int v10; // [esp-1Ch] [ebp-2Ch]
  _DWORD v11[6]; // [esp-18h] [ebp-28h] BYREF
  _DWORD *v12; // [esp+Ch] [ebp-4h]
  _DWORD *v13; // [esp+18h] [ebp+8h]

  v3 = (_DWORD *)a2[66];
  v4 = (_DWORD *)a2[67];
  v13 = v3;
  v12 = v4;
  if ( v3 != v4 )
  {
    while ( 1 )
    {
      v10 = a2[74];
      v5 = (void (__thiscall ***)(_DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v3 + 264);
      v6 = *v5;
      qmemcpy(v11, *(const void **)(*(_DWORD *)(v10 + 364) + 264), sizeof(v11));
      (*v6)(v5, v10, v11[0], v11[1], v11[2], v11[3], v11[4], v11[5]);
      if ( ++v13 == v12 )
        break;
      v3 = v13;
    }
  }
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[74] + 8))(a2[74]);
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)a2[74] + 12))(a2[74], a2[76], a2[78]);
  v7 = (_DWORD *)a2[66];
  v8 = *(_DWORD *)(a2[78] + 51184);
  v9 = (_DWORD *)a2[67];
  while ( v7 != v9 )
  {
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v7 + 52))(*v7, v8);
    ++v7;
  }
}
