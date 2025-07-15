int __cdecl sub_485FB0(int *a1)
{
  int *v1; // ebx
  int result; // eax
  int v3; // esi
  int v4; // edi
  _DWORD *v5; // ebp
  int v6; // ecx
  _DWORD *v7; // edi
  _DWORD *v8; // ebx
  _DWORD *v9; // edx
  _DWORD *v10; // esi
  int v11; // ecx
  int v12; // [esp+10h] [ebp-10h]
  _DWORD *v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]
  int v15; // [esp+1Ch] [ebp-4h]

  v1 = a1;
  result = a1[71];
  v3 = 0;
  v4 = a1[101];
  v14 = v4;
  v15 = result;
  v12 = 0;
  if ( a1[9] > 0 )
  {
    v5 = (_DWORD *)(a1[49] + 12);
    v13 = v5;
    while ( 1 )
    {
      result = *v5 * v5[7] / v1[71];
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 4 * v3);
      v7 = *(_DWORD **)(*(_DWORD *)(v4 + 60) + 4 * v3);
      if ( result > 0 )
      {
        v8 = &v7[result * (v15 + 2)];
        v9 = &v7[-result];
        v10 = &v7[result * (v15 + 1)];
        v11 = v6 - (_DWORD)v7;
        do
        {
          *(_DWORD *)((char *)v9 + v11) = *(_DWORD *)((char *)v10 + v11);
          *v9 = *v10;
          *(_DWORD *)((char *)v8 + v11) = *(_DWORD *)((char *)v7 + v11);
          *v8 = *v7;
          ++v10;
          ++v9;
          ++v7;
          ++v8;
          --result;
        }
        while ( result );
        v3 = v12;
        v1 = a1;
        v5 = v13;
      }
      ++v3;
      v5 += 22;
      v12 = v3;
      v13 = v5;
      if ( v3 >= v1[9] )
        break;
      v4 = v14;
    }
  }
  return result;
}
