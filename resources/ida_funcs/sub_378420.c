char __cdecl sub_378420(_DWORD *a1, int *a2)
{
  int v3; // ebp
  int v4; // ebx
  _BYTE *v5; // edi
  _BYTE *v6; // edi
  int v7; // ebp
  int v8; // eax
  _BYTE *v9; // edi
  int v10; // ebp
  int v11; // eax
  int v12; // ecx
  int v14; // [esp+8h] [ebp-14h]
  int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]
  int v19; // [esp+20h] [ebp+4h]

  v3 = a1[106];
  v14 = v3;
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 52) )
      sub_378100((int)a1);
    --*(_DWORD *)(v3 + 52);
  }
  if ( *(_DWORD *)(v3 + 16) != -1 )
  {
    v4 = a1[92];
    v17 = a1[97];
    v18 = *a2;
    v15 = *(_DWORD *)(a1[75] + 24);
    if ( v4 <= a1[93] )
    {
      while ( 1 )
      {
        v5 = (_BYTE *)(3 * v4 + *(_DWORD *)(v3 + 4 * v15 + 120) - 3);
        if ( sub_377FD0(a1, v5) )
          break;
        if ( !sub_377FD0(a1, v5 + 1) )
        {
          while ( 1 )
          {
            ++v4;
            v5 += 3;
            if ( v4 > a1[93] )
              break;
            if ( sub_377FD0(a1, v5 + 1) )
              goto LABEL_13;
          }
          *(_DWORD *)(*a1 + 20) = 117;
          (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
          *(_DWORD *)(v3 + 16) = -1;
          return 1;
        }
LABEL_13:
        v16 = sub_377FD0(a1, (_BYTE *)(v3 + 184));
        v6 = v5 + 2;
        v7 = sub_377FD0(a1, v6);
        if ( v7 )
        {
          if ( sub_377FD0(a1, v6) )
          {
            v7 *= 2;
            v6 = (_BYTE *)(*(_DWORD *)(v14 + 4 * v15 + 120) + (v4 > *((unsigned __int8 *)a1 + v15 + 235) ? 217 : 189));
            if ( sub_377FD0(a1, v6) )
            {
              while ( 1 )
              {
                v7 *= 2;
                if ( v7 == 0x8000 )
                  break;
                if ( !sub_377FD0(a1, ++v6) )
                  goto LABEL_18;
              }
              *(_DWORD *)(*a1 + 20) = 117;
              (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
              *(_DWORD *)(v14 + 16) = -1;
              return 1;
            }
          }
        }
LABEL_18:
        v8 = v7;
        v9 = v6 + 14;
        v10 = v7 >> 1;
        v19 = v8;
        if ( v10 )
        {
          do
          {
            if ( sub_377FD0(a1, v9) )
              v19 |= v10;
            v10 >>= 1;
          }
          while ( v10 );
          v8 = v19;
        }
        v11 = v8 + 1;
        if ( v16 )
          v11 = -v11;
        v12 = *(_DWORD *)(v17 + 4 * v4++);
        *(_WORD *)(v18 + 2 * v12) = v11 << a1[95];
        if ( v4 > a1[93] )
          return 1;
        v3 = v14;
      }
    }
  }
  return 1;
}
