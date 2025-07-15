int __cdecl sub_37C7D0(_DWORD *a1)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // ebx
  int *v3; // esi
  int v4; // edi
  int *v5; // eax
  int result; // eax
  int v7; // ecx
  _DWORD *v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // ebp
  char v12; // al
  int i; // edx
  int j; // ecx
  int v15; // esi
  bool v16; // cc
  int v17; // [esp+10h] [ebp-20h]
  int v18; // [esp+14h] [ebp-1Ch]
  int *v19; // [esp+18h] [ebp-18h]
  int v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]
  int v22; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  _DWORD *v24; // [esp+2Ch] [ebp-4h]

  v1 = a1;
  v2 = (_DWORD *)a1[110];
  v3 = v2 + 8;
  v24 = v2;
  v4 = sub_37C6A0(a1, v2 + 8);
  v20 = v4;
  if ( a1[25] == 3 )
  {
    v5 = (int *)(*a1 + 24);
    *v5 = v4;
    v5[1] = *v3;
    v5[2] = v2[9];
    v5[3] = v2[10];
    *(_DWORD *)(*a1 + 20) = 96;
  }
  else
  {
    *(_DWORD *)(*a1 + 20) = 97;
    *(_DWORD *)(*a1 + 24) = v4;
  }
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  result = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, 1, v4, a1[25]);
  v7 = result;
  v23 = result;
  v18 = v4;
  v22 = 0;
  if ( (int)a1[25] <= 0 )
  {
    v2[5] = v4;
    v2[4] = result;
  }
  else
  {
    v8 = (_DWORD *)result;
    v19 = v3;
    do
    {
      v9 = *v19;
      v21 = *v19;
      v17 = 0;
      v10 = v18 / *v19;
      if ( *v19 > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          v12 = sub_37C790(v17, v9 - 1);
          for ( i = v11; i < v20; i += v18 )
          {
            for ( j = 0; j < v10; *(_BYTE *)(v15 + i) = v12 )
            {
              v15 = j + *v8;
              ++j;
            }
          }
          v11 += v10;
          if ( ++v17 >= v21 )
            break;
          v9 = v21;
        }
        v1 = a1;
        v7 = v23;
      }
      ++v19;
      ++v8;
      v16 = v22 + 1 < v1[25];
      v18 = v10;
      ++v22;
    }
    while ( v16 );
    result = (int)v24;
    v24[4] = v7;
    v24[5] = v20;
  }
  return result;
}
