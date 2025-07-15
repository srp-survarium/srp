unsigned __int8 *__cdecl sub_489960(_DWORD *a1, int a2, int *a3, int a4)
{
  _DWORD *v4; // esi
  unsigned __int8 *result; // eax
  int *v6; // ebx
  int v7; // ebp
  int v8; // edx
  int v9; // ebp
  _BYTE *v10; // ecx
  int v11; // edi
  int v12; // ebp
  int v13; // esi
  int v14; // edx
  bool v15; // zf
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+8h] [ebp-20h]
  _DWORD *v18; // [esp+Ch] [ebp-1Ch]
  int *v19; // [esp+10h] [ebp-18h]
  int v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  int v22; // [esp+20h] [ebp-8h]
  char v23; // [esp+24h] [ebp-4h]
  int v24; // [esp+2Ch] [ebp+4h]
  _DWORD *v25; // [esp+38h] [ebp+10h]

  v4 = (_DWORD *)a1[110];
  result = (unsigned __int8 *)a4;
  v18 = v4;
  v16 = a1[25];
  v24 = a1[23];
  if ( a4 > 0 )
  {
    v6 = a3;
    v19 = a3;
    v20 = a4;
    do
    {
      memset(*v6, 0, v24);
      v7 = v4[12];
      v8 = 0;
      v23 = v7;
      v17 = 0;
      if ( v16 > 0 )
      {
        v9 = v7 << 6;
        v21 = v9;
        v25 = v4 + 13;
        while ( 1 )
        {
          v10 = (_BYTE *)*v6;
          v22 = *(_DWORD *)(v4[6] + 4 * v8);
          v11 = v9 + *v25;
          v12 = v24;
          result = (unsigned __int8 *)(v8 + *(int *)((char *)v6 + a2 - (_DWORD)a3));
          v13 = 0;
          if ( v24 )
          {
            do
            {
              v14 = *result;
              result += v16;
              *v10++ += *(_BYTE *)(v14 + *(_DWORD *)(v11 + 4 * v13) + v22);
              v13 = ((_BYTE)v13 + 1) & 0xF;
              --v12;
            }
            while ( v12 );
            v8 = v17;
            v6 = v19;
          }
          ++v25;
          v4 = v18;
          v17 = ++v8;
          if ( v8 >= v16 )
            break;
          v9 = v21;
        }
        LOBYTE(v7) = v23;
      }
      ++v6;
      v15 = v20-- == 1;
      v4[12] = ((_BYTE)v7 + 1) & 0xF;
      v19 = v6;
    }
    while ( !v15 );
  }
  return result;
}
