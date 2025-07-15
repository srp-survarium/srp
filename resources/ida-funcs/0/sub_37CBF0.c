unsigned __int8 *__cdecl sub_37CBF0(int a1, int a2, _BYTE **a3, int a4)
{
  int *v4; // eax
  int v5; // edx
  int v6; // esi
  int v7; // edi
  unsigned __int8 *result; // eax
  _BYTE **v9; // ecx
  int v10; // ebx
  _BYTE *v11; // edx
  char v12; // bl
  char v13; // cl
  unsigned __int8 *v14; // eax
  bool v15; // zf
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  _BYTE **v19; // [esp+1Ch] [ebp+4h]

  v4 = *(int **)(*(_DWORD *)(a1 + 440) + 24);
  v5 = v4[1];
  v6 = *(_DWORD *)(a1 + 92);
  v7 = *v4;
  v17 = v4[2];
  result = (unsigned __int8 *)a4;
  v16 = v5;
  v18 = v6;
  if ( a4 > 0 )
  {
    v9 = a3;
    v10 = a2 - (_DWORD)a3;
    v19 = a3;
    do
    {
      result = *(_BYTE **)((char *)v9 + v10);
      v11 = *v9;
      if ( v6 )
      {
        do
        {
          v12 = *(_BYTE *)(result[1] + v16);
          v13 = *(_BYTE *)(*result + v7);
          v14 = result + 1;
          *v11 = *(_BYTE *)(v14[1] + v17) + v12 + v13;
          result = v14 + 2;
          ++v11;
          --v6;
        }
        while ( v6 );
        v6 = v18;
        v9 = v19;
        v10 = a2 - (_DWORD)a3;
      }
      ++v9;
      v15 = a4-- == 1;
      v19 = v9;
    }
    while ( !v15 );
  }
  return result;
}
