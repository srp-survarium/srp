int __cdecl sub_489A70(int a1, int a2, _BYTE **a3, int a4)
{
  _DWORD *v4; // edx
  int *v5; // eax
  int v6; // esi
  int result; // eax
  _BYTE **v8; // ebp
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // ecx
  char v14; // dl
  char v15; // bl
  unsigned __int8 *v16; // eax
  bool v17; // zf
  _BYTE **v18; // [esp+4h] [ebp-28h]
  int v19; // [esp+8h] [ebp-24h]
  int v20; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-18h]
  int v22; // [esp+18h] [ebp-14h]
  int v23; // [esp+1Ch] [ebp-10h]
  int v24; // [esp+20h] [ebp-Ch]
  _DWORD *v25; // [esp+24h] [ebp-8h]
  int v26; // [esp+28h] [ebp-4h]
  _BYTE *v27; // [esp+30h] [ebp+4h]
  int v28; // [esp+3Ch] [ebp+10h]

  v4 = *(_DWORD **)(a1 + 440);
  v5 = (int *)v4[6];
  v21 = *v5;
  v6 = v5[1];
  result = v5[2];
  v20 = *(_DWORD *)(a1 + 92);
  v25 = v4;
  v22 = v6;
  v24 = result;
  if ( a4 > 0 )
  {
    v8 = a3;
    v9 = a2 - (_DWORD)a3;
    v18 = a3;
    v19 = a4;
    while ( 1 )
    {
      v10 = *(_BYTE **)((char *)v8 + v9);
      v26 = v4[12];
      v27 = *v8;
      v11 = (v26 << 6) + v4[13];
      v12 = (v26 << 6) + v4[14];
      v23 = (v26 << 6) + v4[15];
      v13 = 0;
      v28 = v20;
      if ( v20 )
      {
        do
        {
          v14 = *(_BYTE *)(*v10 + *(_DWORD *)(v11 + 4 * v13) + v21);
          v15 = *(_BYTE *)(v22 + v10[1] + *(_DWORD *)(v12 + 4 * v13));
          v16 = v10 + 1;
          *v27 = *(_BYTE *)(v24 + v16[1] + *(_DWORD *)(v23 + 4 * v13)) + v15 + v14;
          v10 = v16 + 2;
          v13 = ((_BYTE)v13 + 1) & 0xF;
          v17 = v28-- == 1;
          ++v27;
        }
        while ( !v17 );
        v4 = v25;
        v8 = v18;
      }
      result = ((_BYTE)v26 + 1) & 0xF;
      ++v8;
      v17 = v19-- == 1;
      v4[12] = result;
      v18 = v8;
      if ( v17 )
        break;
      v9 = a2 - (_DWORD)a3;
    }
  }
  return result;
}
