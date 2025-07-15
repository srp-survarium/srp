_DWORD *__cdecl sub_37BFC0(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *result; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // esi
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned __int8 *v11; // esi
  int v12; // eax
  int v13; // edx
  _WORD *v14; // edi
  bool v15; // zf
  _DWORD *v16; // [esp+4h] [ebp-14h]
  int v17; // [esp+8h] [ebp-10h]
  int v18; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+28h] [ebp+10h]

  result = (_DWORD *)a1;
  v5 = *(_DWORD *)(a1 + 92);
  v18 = *(_DWORD *)(*(_DWORD *)(a1 + 440) + 24);
  v19 = v5;
  if ( a4 > 0 )
  {
    result = a3;
    v6 = a2 - (_DWORD)a3;
    v16 = a3;
    v17 = a4;
    do
    {
      v7 = *(unsigned __int8 **)((char *)result + v6);
      v8 = (_BYTE *)*result;
      v20 = v5;
      if ( v5 )
      {
        do
        {
          v9 = *v7;
          v10 = v7[1];
          v11 = v7 + 1;
          v12 = v9 >> 3;
          v13 = v11[1] >> 3;
          v14 = (_WORD *)(*(_DWORD *)(v18 + 4 * v12) + 2 * (v13 + 32 * (v10 >> 2)));
          v7 = v11 + 2;
          if ( !*v14 )
            sub_37BE80(a1, v12, v13);
          *v8++ = *(_BYTE *)v14 - 1;
          --v20;
        }
        while ( v20 );
        v5 = v19;
        result = v16;
        v6 = a2 - (_DWORD)a3;
      }
      ++result;
      v15 = v17-- == 1;
      v16 = result;
    }
    while ( !v15 );
  }
  return result;
}
