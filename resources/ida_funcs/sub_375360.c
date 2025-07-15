int __cdecl sub_375360(_DWORD *a1, int a2)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // edi
  int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // ebx
  int v7; // ecx
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  _DWORD *v14; // ebp
  unsigned int v15; // eax
  int v17; // [esp+10h] [ebp-34h]
  unsigned int v18; // [esp+14h] [ebp-30h]
  int v19; // [esp+18h] [ebp-2Ch]
  _DWORD *v20; // [esp+1Ch] [ebp-28h]
  _DWORD *v21; // [esp+20h] [ebp-24h]
  int v22; // [esp+24h] [ebp-20h]
  int v23; // [esp+28h] [ebp-1Ch]
  int i; // [esp+2Ch] [ebp-18h]
  int v25; // [esp+30h] [ebp-14h]
  unsigned int v26; // [esp+34h] [ebp-10h]
  unsigned int v27; // [esp+38h] [ebp-Ch]
  void (__cdecl *v28)(_DWORD *, _DWORD *, _DWORD, int, int); // [esp+3Ch] [ebp-8h]
  int v29; // [esp+40h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[102];
  v27 = a1[72] - 1;
  v4 = v3[6];
  v5 = a1[79] - 1;
  v20 = v3;
  v26 = v5;
  v17 = v4;
  if ( v4 >= v3[7] )
  {
LABEL_27:
    v15 = ++v2[32];
    ++v2[34];
    if ( v15 >= v2[72] )
    {
      (*(void (__cdecl **)(_DWORD *))(v2[104] + 12))(v2);
      return 4;
    }
    else
    {
      sub_3752F0(v2);
      return 3;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = v3[5];
      v18 = v6;
      if ( v6 <= v5 )
        break;
LABEL_26:
      ++v4;
      v3[5] = 0;
      v17 = v4;
      if ( v4 >= v3[7] )
        goto LABEL_27;
    }
    while ( 1 )
    {
      if ( v2[98] )
        memset(v3[8], 0, v2[81] << 7);
      if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v2[106] + 4))(v2, v3 + 8) )
        break;
      v7 = 0;
      v19 = 0;
      v25 = 0;
      if ( (int)v2[74] > 0 )
      {
        v21 = v2 + 75;
        do
        {
          v8 = (_DWORD *)*v21;
          if ( *(_BYTE *)(*v21 + 52) )
          {
            v9 = 4 * v8[1];
            v28 = *(void (__cdecl **)(_DWORD *, _DWORD *, _DWORD, int, int))(v2[107] + v9 + 4);
            if ( v6 >= v26 )
              v10 = v8[18];
            else
              v10 = v8[14];
            v11 = v18 * v8[17];
            v22 = v10;
            v12 = *(_DWORD *)(v9 + a2) + 4 * v17 * v8[10];
            v13 = 0;
            v29 = v11;
            for ( i = 0; v13 < v8[15]; i = v13 )
            {
              if ( (v2[32] < v27 || v13 + v17 < v8[19]) && v22 > 0 )
              {
                v14 = &v20[v7 + 8];
                v23 = v22;
                do
                {
                  v28(a1, v8, *v14, v12, v11);
                  v11 += v8[9];
                  ++v14;
                  --v23;
                }
                while ( v23 );
                v13 = i;
                v11 = v29;
                v7 = v19;
                v2 = a1;
              }
              v7 += v8[14];
              ++v13;
              v19 = v7;
              v12 += 4 * v8[10];
            }
            v3 = v20;
          }
          else
          {
            v7 += v8[16];
            v19 = v7;
          }
          ++v21;
          v6 = v18;
          ++v25;
        }
        while ( v25 < v2[74] );
        v5 = v26;
      }
      v18 = ++v6;
      if ( v6 > v5 )
      {
        v4 = v17;
        goto LABEL_26;
      }
    }
    v3[6] = v17;
    v3[5] = v6;
    return 0;
  }
}
