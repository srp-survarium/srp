__int16 __cdecl sub_489BA0(_DWORD *a1, int a2, int *a3, int a4)
{
  int v4; // edx
  int v5; // ebp
  int v6; // esi
  __int16 result; // ax
  int *v8; // edi
  int v9; // edx
  _WORD **v10; // ecx
  int v11; // ebx
  _BYTE *v12; // edi
  _WORD *v13; // ecx
  unsigned __int8 *v14; // ebx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  bool v20; // zf
  _WORD **i; // [esp+8h] [ebp-38h]
  int v22; // [esp+Ch] [ebp-34h]
  int *v23; // [esp+10h] [ebp-30h]
  __int16 v24; // [esp+14h] [ebp-2Ch]
  int v25; // [esp+1Ch] [ebp-24h]
  int v26; // [esp+20h] [ebp-20h]
  int v27; // [esp+24h] [ebp-1Ch]
  int v28; // [esp+28h] [ebp-18h]
  int v29; // [esp+30h] [ebp-10h]
  int v30; // [esp+34h] [ebp-Ch]
  int v31; // [esp+38h] [ebp-8h]
  int v32; // [esp+3Ch] [ebp-4h]
  int v33; // [esp+44h] [ebp+4h]
  __int16 v34; // [esp+50h] [ebp+10h]

  v4 = a1[73];
  v5 = a1[25];
  v6 = a1[110];
  result = a4;
  v22 = v6;
  v26 = v5;
  v33 = a1[23];
  v29 = v4;
  if ( a4 > 0 )
  {
    v8 = a3;
    v23 = a3;
    v28 = a4;
    do
    {
      memset(*v8, 0, v33);
      v9 = 0;
      v27 = 0;
      if ( v5 > 0 )
      {
        v10 = (_WORD **)(v6 + 68);
        for ( i = (_WORD **)(v6 + 68); ; v10 = i )
        {
          v11 = *(int *)((char *)v8 + a2 - (_DWORD)a3);
          v12 = (_BYTE *)*v8;
          v13 = *v10;
          v14 = (unsigned __int8 *)(v9 + v11);
          if ( *(_BYTE *)(v6 + 84) )
          {
            v12 += v33 - 1;
            v14 += v5 * (v33 - 1);
            v15 = -1;
            v5 = -v5;
            v13 += v33 + 1;
          }
          else
          {
            v15 = 1;
          }
          v30 = *(_DWORD *)(*(_DWORD *)(v22 + 24) + 4 * v9);
          v31 = *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * v9);
          v16 = 0;
          v34 = 0;
          v24 = 0;
          v25 = v33;
          if ( v33 )
          {
            do
            {
              v17 = *v14;
              v14 += v5;
              v18 = *(unsigned __int8 *)(v17 + v29 + (((__int16)v13[v15] + v16 + 8) >> 4));
              v19 = *(unsigned __int8 *)(v18 + v30);
              *v12 += v19;
              v32 = v18 - *(unsigned __int8 *)(v19 + v31);
              *v13 = 3 * v32 + v34;
              v34 = 5 * v32 + v24;
              v16 = 7 * v32;
              v12 += v15;
              v20 = v25-- == 1;
              v24 = v32;
              v13 += v15;
            }
            while ( !v20 );
            v9 = v27;
          }
          v5 = v26;
          result = v34;
          ++i;
          v8 = v23;
          v6 = v22;
          ++v9;
          *v13 = v34;
          v27 = v9;
          if ( v9 >= v26 )
            break;
        }
      }
      ++v8;
      v20 = v28-- == 1;
      *(_BYTE *)(v6 + 84) = *(_BYTE *)(v6 + 84) == 0;
      v23 = v8;
    }
    while ( !v20 );
  }
  return result;
}
