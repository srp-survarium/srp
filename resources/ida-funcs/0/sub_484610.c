int __cdecl sub_484610(int *a1)
{
  _DWORD *v2; // edi
  int v3; // eax
  bool v4; // zf
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int *v8; // ebp
  int i; // edi
  _DWORD *v10; // ebp
  int v11; // eax
  unsigned int v12; // ecx
  int *v13; // edi
  _DWORD *v14; // ebx
  _DWORD *v15; // ebx
  _DWORD *v16; // ebp
  int v17; // edi
  _DWORD *v18; // edi
  _DWORD *v19; // ebp
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int result; // eax
  int v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+10h] [ebp-8h]
  _DWORD *v27; // [esp+14h] [ebp-4h]
  int *v28; // [esp+14h] [ebp-4h]
  int v29; // [esp+14h] [ebp-4h]
  _DWORD *v30; // [esp+1Ch] [ebp+4h]

  v2 = (_DWORD *)a1[106];
  v30 = v2;
  if ( *((_BYTE *)a1 + 201) )
  {
    v3 = a1[92];
    if ( v3 )
    {
      v5 = a1[93];
      if ( v5 < v3 || v5 > a1[98] )
      {
LABEL_11:
        *(_DWORD *)(*a1 + 20) = 17;
        *(_DWORD *)(*a1 + 24) = a1[92];
        *(_DWORD *)(*a1 + 28) = a1[93];
        *(_DWORD *)(*a1 + 32) = a1[94];
        *(_DWORD *)(*a1 + 36) = a1[95];
        (*(void (__cdecl **)(int *))*a1)(a1);
LABEL_12:
        v24 = 0;
        if ( a1[74] > 0 )
        {
          v27 = a1 + 75;
          do
          {
            v7 = *(_DWORD *)(*v27 + 4);
            v8 = (int *)(a1[35] + (v7 << 8));
            if ( a1[92] && *v8 < 0 )
            {
              *(_DWORD *)(*a1 + 20) = 118;
              *(_DWORD *)(*a1 + 24) = v7;
              *(_DWORD *)(*a1 + 28) = 0;
              (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
            }
            for ( i = a1[92]; i <= a1[93]; ++i )
            {
              if ( a1[94] != (v8[i] < 0 ? 0 : v8[i]) )
              {
                *(_DWORD *)(*a1 + 20) = 118;
                *(_DWORD *)(*a1 + 24) = v7;
                *(_DWORD *)(*a1 + 28) = i;
                (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
              }
              v8[i] = a1[95];
            }
            ++v27;
            ++v24;
          }
          while ( v24 < a1[74] );
        }
        if ( a1[94] )
        {
          if ( a1[92] )
            v30[1] = sub_483980;
          else
            v30[1] = sub_4838A0;
        }
        else if ( a1[92] )
        {
          v30[1] = sub_483670;
        }
        else
        {
          v30[1] = sub_483450;
        }
        v25 = 0;
        if ( a1[74] > 0 )
        {
          v10 = v30 + 5;
          v28 = a1 + 75;
          do
          {
            v11 = *v28;
            if ( a1[92] )
            {
              v12 = *(_DWORD *)(v11 + 24);
              v13 = &v30[v12 + 11];
              sub_482F20(v12, (int (__cdecl ***)(_DWORD, _DWORD, _DWORD))a1, 0, v13);
              v30[15] = *v13;
            }
            else if ( !a1[94] )
            {
              sub_482F20(
                *(_DWORD *)(v11 + 20),
                (int (__cdecl ***)(_DWORD, _DWORD, _DWORD))a1,
                1,
                &v30[*(_DWORD *)(v11 + 20) + 11]);
            }
            ++v28;
            *v10++ = 0;
            ++v25;
          }
          while ( v25 < a1[74] );
        }
        v30[4] = 0;
        v14 = v30;
        goto LABEL_108;
      }
      v4 = a1[74] == 1;
    }
    else
    {
      v4 = a1[93] == 0;
    }
    if ( v4 )
    {
      v6 = a1[94];
      if ( (!v6 || v6 - 1 == a1[95]) && a1[95] <= 13 )
        goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( a1[92] || a1[94] || a1[95] || (*((_BYTE *)a1 + 200) || a1[93] < 64) && a1[93] != a1[98] )
  {
    *(_DWORD *)(*a1 + 20) = 125;
    (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
  }
  if ( a1[98] == 63 )
    v2[1] = sub_4841D0;
  else
    v2[1] = sub_483D70;
  v26 = 0;
  if ( a1[74] > 0 )
  {
    v15 = v2 + 5;
    v16 = a1 + 75;
    do
    {
      v17 = *v16;
      sub_482F20(
        *(_DWORD *)(*v16 + 20),
        (int (__cdecl ***)(_DWORD, _DWORD, _DWORD))a1,
        1,
        &v30[*(_DWORD *)(*v16 + 20) + 16]);
      if ( a1[98] )
        sub_482F20(
          *(_DWORD *)(v17 + 24),
          (int (__cdecl ***)(_DWORD, _DWORD, _DWORD))a1,
          0,
          &v30[*(_DWORD *)(v17 + 24) + 20]);
      *v15 = 0;
      ++v16;
      ++v15;
      ++v26;
    }
    while ( v26 < a1[74] );
  }
  v14 = v30;
  v29 = 0;
  if ( a1[81] > 0 )
  {
    v18 = v30 + 44;
    v19 = a1 + 82;
    do
    {
      v20 = a1[*v19 + 75];
      *(v18 - 20) = v30[*(_DWORD *)(v20 + 20) + 16];
      *(v18 - 10) = v30[*(_DWORD *)(v20 + 24) + 20];
      if ( *(_BYTE *)(v20 + 52) )
      {
        v21 = *(_DWORD *)(v20 + 40);
        v22 = *(_DWORD *)(v20 + 36);
        switch ( a1[98] )
        {
          case 0:
            *v18 = 1;
            break;
          case 3:
            if ( v21 <= 0 || v21 > 2 )
              v21 = 2;
            if ( v22 <= 0 || v22 > 2 )
              v22 = 2;
            *v18 = dword_6F6284[2 * v21 + v22] + 1;
            break;
          case 8:
            if ( v21 <= 0 || v21 > 3 )
              v21 = 3;
            if ( v22 <= 0 || v22 > 3 )
              v22 = 3;
            *v18 = dword_6F6124[2 * v21 + v21 + v22] + 1;
            break;
          case 15:
            if ( v21 <= 0 || v21 > 4 )
              v21 = 4;
            if ( v22 <= 0 || v22 > 4 )
              v22 = 4;
            *v18 = dword_6F623C[4 * v21 + v22] + 1;
            break;
          case 24:
            if ( v21 <= 0 || v21 > 5 )
              v21 = 5;
            if ( v22 <= 0 || v22 > 5 )
              v22 = 5;
            *v18 = dword_6F61D0[4 * v21 + v21 + v22] + 1;
            break;
          case 35:
            if ( v21 <= 0 || v21 > 6 )
              v21 = 6;
            if ( v22 <= 0 || v22 > 6 )
              v22 = 6;
            *v18 = dword_6F613C[6 * v21 + v22] + 1;
            break;
          case 48:
            if ( v21 <= 0 || v21 > 7 )
              v21 = 7;
            if ( v22 <= 0 || v22 > 7 )
              v22 = 7;
            *v18 = dword_6F6050[7 * v21 + v22] + 1;
            break;
          default:
            if ( v21 <= 0 || v21 > 8 )
              v21 = 8;
            if ( v22 <= 0 || v22 > 8 )
              v22 = 8;
            *v18 = dword_6F5F4C[8 * v21 + v22] + 1;
            break;
        }
      }
      else
      {
        *v18 = 0;
      }
      ++v19;
      ++v18;
      ++v29;
    }
    while ( v29 < a1[81] );
  }
LABEL_108:
  v14[3] = 0;
  v14[2] = 0;
  *((_BYTE *)v14 + 36) = 0;
  result = a1[63];
  v14[10] = result;
  return result;
}
