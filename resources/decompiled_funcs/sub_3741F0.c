int __usercall sub_3741F0@<eax>(_DWORD *a1@<esi>)
{
  int v1; // eax
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  int result; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  bool v8; // cc
  _DWORD *v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ebp
  int v13; // edx
  int v14; // ebx
  unsigned int v15; // eax
  int v16; // edx
  int v17; // edi
  int v18; // [esp+8h] [ebp-8h]
  _DWORD *v19; // [esp+Ch] [ebp-4h]

  v1 = a1[74];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[75];
    a1[79] = v2[7];
    a1[80] = v2[8];
    v3 = v2[3];
    v2[17] = v2[9];
    result = v2[8] / v3;
    v5 = v2[8] % v3;
    v2[14] = 1;
    v2[15] = 1;
    v2[16] = 1;
    v2[18] = 1;
    if ( !v5 )
      v5 = v3;
    v2[19] = v5;
    a1[81] = 1;
    a1[82] = 0;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      *(_DWORD *)(*a1 + 20) = 27;
      *(_DWORD *)(*a1 + 24) = a1[74];
      *(_DWORD *)(*a1 + 28) = 4;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    v6 = jdiv_round_up(a1[7], a1[96] * a1[68]);
    v7 = a1[8];
    a1[79] = v6;
    result = jdiv_round_up(v7, a1[96] * a1[69]);
    v8 = a1[74] <= 0;
    a1[80] = result;
    a1[81] = 0;
    v18 = 0;
    if ( !v8 )
    {
      v19 = a1 + 75;
      do
      {
        v9 = (_DWORD *)*v19;
        v10 = *(_DWORD *)(*v19 + 8);
        v11 = *(_DWORD *)(*v19 + 28);
        v12 = *(_DWORD *)(*v19 + 12);
        v9[17] = v10 * *(_DWORD *)(*v19 + 36);
        v13 = v11 % v10;
        v14 = v10 * v12;
        v9[14] = v10;
        v9[15] = v12;
        v9[16] = v10 * v12;
        if ( !(v11 % v10) )
          v13 = v10;
        v15 = v9[8];
        v9[18] = v13;
        v16 = v15 % v12;
        if ( !(v15 % v12) )
          v16 = v12;
        v9[19] = v16;
        v17 = v10 * v12;
        if ( v14 + a1[81] > 10 )
        {
          *(_DWORD *)(*a1 + 20) = 14;
          (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        }
        if ( v14 > 0 )
        {
          do
          {
            --v17;
            a1[a1[81]++ + 82] = v18;
          }
          while ( v17 > 0 );
        }
        ++v19;
        result = ++v18;
      }
      while ( v18 < a1[74] );
    }
  }
  return result;
}
