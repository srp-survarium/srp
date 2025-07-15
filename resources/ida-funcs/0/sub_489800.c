_BYTE *__cdecl sub_489800(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // ebx
  int v5; // esi
  _BYTE *result; // eax
  int v7; // edi
  _DWORD *v8; // edx
  int v9; // ebp
  unsigned __int8 *v10; // ecx
  char v11; // dl
  int i; // eax
  char v13; // bl
  bool v14; // zf
  _DWORD *v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-4h]
  _BYTE *v18; // [esp+20h] [ebp+4h]
  int v19; // [esp+2Ch] [ebp+10h]

  v4 = a1[23];
  v5 = a1[25];
  result = (_BYTE *)a4;
  v7 = *(_DWORD *)(a1[110] + 24);
  v17 = v4;
  if ( a4 > 0 )
  {
    v8 = a3;
    v9 = a2 - (_DWORD)a3;
    v15 = a3;
    v16 = a4;
    do
    {
      result = (_BYTE *)*v8;
      v10 = *(unsigned __int8 **)((char *)v8 + v9);
      v18 = (_BYTE *)*v8;
      v19 = v4;
      if ( v4 )
      {
        do
        {
          v11 = 0;
          for ( i = 0; i < v5; ++v10 )
          {
            v13 = *(_BYTE *)(*v10 + *(_DWORD *)(v7 + 4 * i++));
            v11 += v13;
          }
          *v18 = v11;
          result = v18 + 1;
          v14 = v19-- == 1;
          ++v18;
        }
        while ( !v14 );
        v9 = a2 - (_DWORD)a3;
        v8 = v15;
        v4 = v17;
      }
      ++v8;
      v14 = v16-- == 1;
      v15 = v8;
    }
    while ( !v14 );
  }
  return result;
}
