char __cdecl sub_378220(int *a1, int a2)
{
  int v3; // ebx
  int v4; // ebp
  int v5; // edx
  _BYTE *v6; // edi
  int v7; // eax
  _BYTE *v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // eax
  _BYTE *v12; // edi
  int v13; // ebp
  int v14; // eax
  int v16; // [esp+8h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-10h]
  int v18; // [esp+10h] [ebp-Ch]
  int *i; // [esp+14h] [ebp-8h]
  _WORD *v20; // [esp+18h] [ebp-4h]
  int v21; // [esp+20h] [ebp+4h]
  int v22; // [esp+20h] [ebp+4h]

  v3 = a1[106];
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 52) )
      sub_378100((int)a1);
    --*(_DWORD *)(v3 + 52);
  }
  if ( *(_DWORD *)(v3 + 16) != -1 )
  {
    v18 = 0;
    if ( a1[81] > 0 )
    {
      for ( i = a1 + 82; ; ++i )
      {
        v4 = *i;
        v5 = a1[*i + 75];
        v20 = *(_WORD **)(a2 + 4 * v18);
        v6 = (_BYTE *)(*(_DWORD *)(v3 + 4 * *i + 36) + *(_DWORD *)(v3 + 4 * *(_DWORD *)(v5 + 20) + 56));
        v21 = *(_DWORD *)(v5 + 20);
        v16 = *i;
        if ( sub_377FD0(a1, v6) )
        {
          v7 = sub_377FD0(a1, v6 + 1);
          v8 = &v6[v7 + 2];
          v17 = v7;
          v9 = sub_377FD0(a1, v8);
          if ( v9 )
          {
            v8 = (_BYTE *)(*(_DWORD *)(v3 + 4 * v21 + 56) + 20);
            if ( sub_377FD0(a1, v8) )
            {
              while ( 1 )
              {
                v9 *= 2;
                if ( v9 == 0x8000 )
                  break;
                if ( !sub_377FD0(a1, ++v8) )
                  goto LABEL_14;
              }
              *(_DWORD *)(*a1 + 20) = 117;
              (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
              *(_DWORD *)(v3 + 16) = -1;
              return 1;
            }
          }
LABEL_14:
          if ( v9 >= 1 << *((_BYTE *)a1 + v21 + 203) >> 1 )
          {
            v10 = 4 * v17 + 12;
            if ( v9 <= 1 << *((_BYTE *)a1 + v21 + 219) >> 1 )
              v10 = 4 * v17 + 4;
            *(_DWORD *)(v3 + 4 * v16 + 36) = v10;
          }
          else
          {
            *(_DWORD *)(v3 + 4 * v16 + 36) = 0;
          }
          v11 = v9;
          v12 = v8 + 14;
          v13 = v9 >> 1;
          v22 = v11;
          if ( v13 )
          {
            do
            {
              if ( sub_377FD0(a1, v12) )
                v22 |= v13;
              v13 >>= 1;
            }
            while ( v13 );
            v11 = v22;
          }
          v14 = v11 + 1;
          if ( v17 )
            v14 = -v14;
          *(_DWORD *)(v3 + 4 * v16 + 20) += v14;
          v4 = v16;
        }
        else
        {
          *(_DWORD *)(v3 + 4 * v4 + 36) = 0;
        }
        *v20 = *(_WORD *)(v3 + 4 * v4 + 20) << a1[95];
        if ( ++v18 >= a1[81] )
          return 1;
      }
    }
  }
  return 1;
}
