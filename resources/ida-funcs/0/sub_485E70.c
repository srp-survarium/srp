int __cdecl sub_485E70(int *a1)
{
  int *v1; // ecx
  int v2; // ebp
  _DWORD *v3; // esi
  int result; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // edi
  int v7; // ebx
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // edi
  _DWORD *v13; // ecx
  int v14; // edx
  int v15; // ebx
  _DWORD *v16; // ecx
  int v17; // [esp+8h] [ebp-20h]
  int *v18; // [esp+Ch] [ebp-1Ch]
  _DWORD *v19; // [esp+10h] [ebp-18h]
  int v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  _DWORD *v22; // [esp+1Ch] [ebp-Ch]
  _DWORD *v23; // [esp+20h] [ebp-8h]
  char *v24; // [esp+24h] [ebp-4h]

  v1 = a1;
  v2 = 0;
  v3 = (_DWORD *)a1[101];
  v21 = a1[71];
  result = a1[49];
  v23 = v3;
  v17 = 0;
  if ( a1[9] > 0 )
  {
    v5 = (_DWORD *)(result + 12);
    v19 = (_DWORD *)(result + 12);
    v18 = v3 + 2;
    while ( 1 )
    {
      result = *v5 * v5[7] / v1[71];
      v6 = *(_DWORD **)(v3[14] + 4 * v2);
      v7 = *v18;
      v8 = *(_DWORD *)(v3[15] + 4 * v2);
      v22 = v6;
      if ( result * (v21 + 2) > 0 )
      {
        v9 = *(_DWORD **)(v3[15] + 4 * v2);
        v24 = (char *)v6 - v8;
        v20 = result * (v21 + 2);
        do
        {
          v10 = *(_DWORD *)((char *)v9 + v7 - v8);
          *v9 = v10;
          *(_DWORD *)((char *)v9++ + (_DWORD)v24) = v10;
          --v20;
        }
        while ( v20 );
        v6 = v22;
        v2 = v17;
        v1 = a1;
      }
      if ( 2 * result > 0 )
      {
        v11 = (_DWORD *)(v8 + 4 * v21 * result);
        v12 = v7 - v8;
        v13 = (_DWORD *)(v7 + 4 * result * (v21 - 2));
        v14 = v8 - v7;
        v15 = 2 * result;
        do
        {
          *(_DWORD *)((char *)v13 + v14) = *(_DWORD *)((char *)v11 + v12);
          *v11++ = *v13++;
          --v15;
        }
        while ( v15 );
        v6 = v22;
        v2 = v17;
        v1 = a1;
      }
      if ( result > 0 )
      {
        v16 = &v6[-result];
        do
        {
          *v16++ = *v6;
          --result;
        }
        while ( result );
        v1 = a1;
      }
      ++v18;
      v19 += 22;
      v17 = ++v2;
      if ( v2 >= v1[9] )
        break;
      v5 = v19;
      v3 = v23;
    }
  }
  return result;
}
