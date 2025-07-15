void __thiscall btSoftBody::updateBounds(btSoftBody *this, int a2)
{
  float *v2; // ebx
  float v3; // xmm1_4
  int v4; // esi
  float v5; // [esp+Ch] [ebp-14h]
  float v6; // [esp+14h] [ebp-Ch]
  float v7; // [esp+14h] [ebp-Ch]
  float v8; // [esp+18h] [ebp-8h]

  v2 = *(float **)(a2 + 948);
  if ( v2 )
  {
    v5 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a2 + 204) + 40))(*(_DWORD *)(a2 + 204));
    v6 = v2[1] - v5;
    v8 = v2[2] - v5;
    *(float *)(a2 + 912) = *v2 - v5;
    *(float *)(a2 + 916) = v6;
    *(float *)(a2 + 920) = v8;
    *(_DWORD *)(a2 + 924) = 0;
    v7 = v2[5] + v5;
    v3 = v2[6];
    *(float *)(a2 + 928) = v2[4] + v5;
    *(float *)(a2 + 932) = v7;
    *(float *)(a2 + 936) = v3 + v5;
    *(_DWORD *)(a2 + 940) = 0;
    v4 = *(_DWORD *)(a2 + 200);
    if ( v4 )
      (*(void (__thiscall **)(_DWORD, int, int, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 692) + 32) + 12))(
        *(_DWORD *)(*(_DWORD *)(a2 + 692) + 32),
        v4,
        a2 + 912,
        a2 + 928,
        *(_DWORD *)(*(_DWORD *)(a2 + 692) + 36));
  }
  else
  {
    *(_DWORD *)(a2 + 928) = 0;
    *(_DWORD *)(a2 + 932) = 0;
    *(_DWORD *)(a2 + 936) = 0;
    *(_DWORD *)(a2 + 940) = 0;
    *(_DWORD *)(a2 + 912) = 0;
    *(_DWORD *)(a2 + 916) = 0;
    *(_DWORD *)(a2 + 920) = 0;
    *(_DWORD *)(a2 + 924) = 0;
  }
}
