int __cdecl sub_489600(_DWORD *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // ecx
  int result; // eax
  int v5; // ebp
  _BYTE *v6; // edi
  int v7; // ebp
  int v8; // ebx
  int v9; // ecx
  int i; // esi
  int v11; // eax
  _BYTE *v12; // ecx
  int v13; // [esp+8h] [ebp-14h]
  int v14; // [esp+Ch] [ebp-10h]
  int *v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  v1 = a1[110];
  v17 = v1;
  if ( a1[19] == 1 )
  {
    v13 = 510;
    *(_BYTE *)(v1 + 28) = 1;
  }
  else
  {
    v13 = 0;
    *(_BYTE *)(v1 + 28) = 0;
  }
  v2 = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, 1, v13 + 256, a1[25]);
  v3 = 0;
  *(_DWORD *)(v1 + 24) = v2;
  result = *(_DWORD *)(v1 + 20);
  v14 = 0;
  if ( (int)a1[25] > 0 )
  {
    v15 = (int *)(v1 + 32);
    while ( 1 )
    {
      v5 = *v15;
      v16 = result / *v15;
      if ( v13 )
        *(_DWORD *)(*(_DWORD *)(v1 + 24) + 4 * v3) += 255;
      v6 = *(_BYTE **)(*(_DWORD *)(v1 + 24) + 4 * v3);
      v7 = v5 - 1;
      v8 = 0;
      v9 = sub_489470(0, v7);
      for ( i = 0; i <= 255; ++i )
      {
        for ( ; i > v9; v9 = sub_489470(v8, v7) )
          ++v8;
        v6[i] = v8 * v16;
      }
      if ( v13 )
      {
        v11 = 1;
        v12 = v6 - 1;
        do
        {
          *v12 = *v6;
          v6[v11++ + 255] = v6[255];
          --v12;
        }
        while ( v11 <= 255 );
      }
      ++v15;
      result = ++v14;
      if ( v14 >= a1[25] )
        break;
      result = v16;
      v1 = v17;
      v3 = v14;
    }
  }
  return result;
}
