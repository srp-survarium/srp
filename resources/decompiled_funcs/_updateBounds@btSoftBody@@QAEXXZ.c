void __usercall btSoftBody::updateBounds(btSoftBody *this@<ecx>, int a2@<eax>)
{
  float *v3; // esi
  float v4; // xmm4_4
  float v5; // xmm1_4
  int v6; // esi
  float v7; // [esp+20h] [ebp-14h]
  __int64 v8; // [esp+24h] [ebp-10h]
  unsigned int v9; // [esp+2Ch] [ebp-8h]

  v3 = *(float **)(a2 + 948);
  if ( v3 )
  {
    v7 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a2 + 204) + 40))(*(_DWORD *)(a2 + 204));
    *(float *)&v8 = *v3 - v7;
    *((float *)&v8 + 1) = v3[1] - v7;
    *(float *)&v9 = v3[2] - v7;
    *(_QWORD *)(a2 + 912) = v8;
    *(_QWORD *)(a2 + 920) = v9;
    v4 = v3[4] + v7;
    *((float *)&v8 + 1) = v3[5] + v7;
    v5 = v3[6];
    v6 = *(_DWORD *)(a2 + 200);
    *(float *)&v8 = v4;
    *(_QWORD *)(a2 + 928) = v8;
    *(_QWORD *)(a2 + 936) = COERCE_UNSIGNED_INT(v5 + v7);
    if ( v6 )
      (*(void (__thiscall **)(_DWORD, int, int, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 692) + 32) + 12))(
        *(_DWORD *)(*(_DWORD *)(a2 + 692) + 32),
        v6,
        a2 + 912,
        a2 + 928,
        *(_DWORD *)(*(_DWORD *)(a2 + 692) + 36));
  }
  else
  {
    *(_QWORD *)(a2 + 928) = 0;
    *(_QWORD *)(a2 + 912) = 0;
    *(_QWORD *)(a2 + 936) = 0;
    *(_QWORD *)(a2 + 920) = 0;
  }
}
