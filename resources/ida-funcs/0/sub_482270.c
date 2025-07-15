int __cdecl sub_482270(_DWORD *a1)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // ebp
  int v11; // eax
  int v12; // edx
  int *v13; // esi
  _DWORD *v15; // [esp+10h] [ebp-2Ch]
  unsigned int v16; // [esp+10h] [ebp-2Ch]
  _DWORD *v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+18h] [ebp-24h]
  int v19; // [esp+1Ch] [ebp-20h]
  _DWORD *v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+24h] [ebp-18h]
  int v22; // [esp+28h] [ebp-14h]
  _DWORD v23[4]; // [esp+2Ch] [ebp-10h]

  v1 = a1;
  v2 = (_DWORD *)a1[102];
  v3 = 0;
  v20 = v2;
  if ( (int)a1[74] > 0 )
  {
    v15 = a1 + 75;
    do
    {
      v4 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, int))(a1[1] + 32))(
             a1,
             v2[*(_DWORD *)(*v15 + 4) + 18],
             *(_DWORD *)(*v15 + 12) * a1[32],
             *(_DWORD *)(*v15 + 12),
             1);
      ++v15;
      v23[v3++] = v4;
    }
    while ( v3 < a1[74] );
  }
  v5 = v2[6];
  v21 = v5;
  if ( v5 >= v2[7] )
  {
LABEL_20:
    if ( ++v1[32] >= v1[72] )
    {
      (*(void (__cdecl **)(_DWORD *))(v1[104] + 12))(v1);
      return 4;
    }
    else
    {
      sub_481FB0(v1);
      return 3;
    }
  }
  else
  {
    while ( 1 )
    {
      v16 = v2[5];
      if ( v16 < v1[79] )
        break;
LABEL_19:
      ++v5;
      v2[5] = 0;
      v21 = v5;
      if ( v5 >= v2[7] )
        goto LABEL_20;
    }
    while ( 1 )
    {
      v6 = 0;
      v7 = 0;
      v19 = 0;
      if ( (int)v1[74] > 0 )
      {
        v17 = v1 + 75;
        do
        {
          v8 = *v17;
          v9 = *(_DWORD *)(*v17 + 56);
          v18 = 0;
          if ( *(int *)(*v17 + 60) > 0 )
          {
            v22 = (v16 * *(_DWORD *)(*v17 + 56)) << 7;
            v10 = (_DWORD *)(v23[v6] + 4 * v5);
            do
            {
              v11 = v22 + *v10;
              v12 = 0;
              if ( v9 > 0 )
              {
                v13 = &v20[v7 + 8];
                do
                {
                  *v13 = v11;
                  v9 = *(_DWORD *)(v8 + 56);
                  ++v12;
                  ++v7;
                  ++v13;
                  v11 += 128;
                }
                while ( v12 < v9 );
              }
              ++v10;
              ++v18;
            }
            while ( v18 < *(_DWORD *)(v8 + 60) );
            v1 = a1;
            v6 = v19;
            v5 = v21;
          }
          ++v17;
          v19 = ++v6;
        }
        while ( v6 < v1[74] );
        v2 = v20;
      }
      if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v1[106] + 4))(v1, v2 + 8) )
        break;
      if ( ++v16 >= v1[79] )
        goto LABEL_19;
    }
    v2[6] = v5;
    v2[5] = v16;
    return 0;
  }
}
