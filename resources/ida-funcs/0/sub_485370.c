char __cdecl sub_485370(_DWORD *a1, int *a2)
{
  int v3; // ebp
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // edx
  int v11; // ebp
  __int16 *v12; // ebx
  __int16 v13; // ax
  __int16 v14; // ax
  int v16; // [esp+8h] [ebp-18h]
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h]
  __int16 v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-8h]
  int v21; // [esp+1Ch] [ebp-4h]
  int v22; // [esp+24h] [ebp+4h]

  v3 = a1[106];
  v16 = v3;
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 52) )
      sub_484DC0((int)a1);
    --*(_DWORD *)(v3 + 52);
  }
  if ( *(_DWORD *)(v3 + 16) != -1 )
  {
    v4 = a1[95];
    v21 = *(_DWORD *)(a1[75] + 24);
    v5 = a1[97];
    v20 = 1 << v4;
    v6 = -1 << v4;
    v7 = a1[93];
    v17 = v5;
    v18 = *a2;
    v19 = v6;
    v8 = v7;
    v22 = v7;
    if ( v7 > 0 )
    {
      do
      {
        if ( *(_WORD *)(*a2 + 2 * *(_DWORD *)(v5 + 4 * v8)) )
          break;
        --v8;
      }
      while ( v8 > 0 );
      v22 = v8;
    }
    v9 = a1[92];
    if ( v9 <= v7 )
    {
      while ( 1 )
      {
        v10 = *(_DWORD *)(v3 + 4 * v21 + 120);
        v11 = 3 * v9 + v10 - 3;
        if ( v9 > v8 )
        {
          if ( sub_484C90(a1, (_BYTE *)(3 * v9 + v10 - 3)) )
            break;
        }
        v12 = (__int16 *)(v18 + 2 * *(_DWORD *)(v5 + 4 * v9));
        if ( *v12 )
        {
LABEL_19:
          if ( sub_484C90(a1, (_BYTE *)(v11 + 2)) )
          {
            v13 = *v12;
            if ( *v12 >= 0 )
              v14 = v20 + v13;
            else
              v14 = v19 + v13;
            *v12 = v14;
          }
        }
        else
        {
          while ( !sub_484C90(a1, (_BYTE *)(v11 + 1)) )
          {
            ++v9;
            v11 += 3;
            if ( v9 > a1[93] )
            {
              *(_DWORD *)(*a1 + 20) = 117;
              (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
              *(_DWORD *)(v16 + 16) = -1;
              return 1;
            }
            v12 = (__int16 *)(v18 + 2 * *(_DWORD *)(v17 + 4 * v9));
            if ( *v12 )
              goto LABEL_19;
          }
          if ( sub_484C90(a1, (_BYTE *)(v16 + 184)) )
            *v12 = v19;
          else
            *v12 = v20;
        }
        if ( ++v9 > a1[93] )
          return 1;
        v5 = v17;
        v3 = v16;
        v8 = v22;
      }
    }
  }
  return 1;
}
