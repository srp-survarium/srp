int __cdecl sub_378C40(int a1)
{
  _DWORD *v2; // edi
  int v3; // eax
  bool v4; // zf
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int *v8; // ebp
  int i; // edi
  int v10; // eax
  int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // edi
  int result; // eax
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int *v18; // [esp+14h] [ebp-8h]
  _DWORD *v19; // [esp+18h] [ebp-4h]
  _DWORD *v20; // [esp+20h] [ebp+4h]

  v4 = *(_BYTE *)(a1 + 201) == 0;
  v2 = *(_DWORD **)(a1 + 424);
  v20 = v2;
  if ( !v4 )
  {
    v3 = *(_DWORD *)(a1 + 368);
    if ( v3 )
    {
      v5 = *(_DWORD *)(a1 + 372);
      if ( v5 < v3 || v5 > *(_DWORD *)(a1 + 392) )
      {
LABEL_11:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 368);
        *(_DWORD *)(*(_DWORD *)a1 + 28) = *(_DWORD *)(a1 + 372);
        *(_DWORD *)(*(_DWORD *)a1 + 32) = *(_DWORD *)(a1 + 376);
        *(_DWORD *)(*(_DWORD *)a1 + 36) = *(_DWORD *)(a1 + 380);
        (**(void (__cdecl ***)(int))a1)(a1);
LABEL_12:
        v15 = 0;
        if ( *(int *)(a1 + 296) > 0 )
        {
          v17 = a1 + 300;
          do
          {
            v7 = *(_DWORD *)(*(_DWORD *)v17 + 4);
            v8 = (int *)(*(_DWORD *)(a1 + 140) + (v7 << 8));
            if ( *(_DWORD *)(a1 + 368) && *v8 < 0 )
            {
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 118;
              *(_DWORD *)(*(_DWORD *)a1 + 24) = v7;
              *(_DWORD *)(*(_DWORD *)a1 + 28) = 0;
              (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, -1);
            }
            for ( i = *(_DWORD *)(a1 + 368); i <= *(_DWORD *)(a1 + 372); ++i )
            {
              if ( *(_DWORD *)(a1 + 376) != (v8[i] < 0 ? 0 : v8[i]) )
              {
                *(_DWORD *)(*(_DWORD *)a1 + 20) = 118;
                *(_DWORD *)(*(_DWORD *)a1 + 24) = v7;
                *(_DWORD *)(*(_DWORD *)a1 + 28) = i;
                (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, -1);
              }
              v8[i] = *(_DWORD *)(a1 + 380);
            }
            v17 += 4;
            ++v15;
          }
          while ( v15 < *(_DWORD *)(a1 + 296) );
          v2 = v20;
        }
        if ( *(_DWORD *)(a1 + 376) )
        {
          if ( *(_DWORD *)(a1 + 368) )
            v2[1] = sub_3786B0;
          else
            v2[1] = sub_378640;
        }
        else if ( *(_DWORD *)(a1 + 368) )
        {
          v2[1] = sub_378420;
        }
        else
        {
          v2[1] = sub_378220;
        }
        goto LABEL_37;
      }
      v4 = *(_DWORD *)(a1 + 296) == 1;
    }
    else
    {
      v4 = *(_DWORD *)(a1 + 372) == 0;
    }
    if ( v4 )
    {
      v6 = *(_DWORD *)(a1 + 376);
      if ( (!v6 || v6 - 1 == *(_DWORD *)(a1 + 380)) && *(int *)(a1 + 380) <= 13 )
        goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a1 + 368)
    || *(_DWORD *)(a1 + 376)
    || *(_DWORD *)(a1 + 380)
    || (v10 = *(_DWORD *)(a1 + 372), v10 < 64) && v10 != *(_DWORD *)(a1 + 392) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 125;
    (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, -1);
  }
  v2[1] = sub_378870;
LABEL_37:
  v16 = 0;
  if ( *(int *)(a1 + 296) > 0 )
  {
    v19 = v2 + 9;
    v18 = (int *)(a1 + 300);
    do
    {
      v11 = *v18;
      if ( !*(_BYTE *)(a1 + 201) || !*(_DWORD *)(a1 + 368) && !*(_DWORD *)(a1 + 376) )
      {
        v12 = *(_DWORD *)(v11 + 20);
        if ( v12 >= 0x10 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v12;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        if ( !v20[v12 + 14] )
          v20[v12 + 14] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 64);
        memset(v20[v12 + 14], 0, 0x40u);
        *(v19 - 4) = 0;
        *v19 = 0;
        v2 = v20;
      }
      if ( *(_BYTE *)(a1 + 201) )
      {
        if ( *(_DWORD *)(a1 + 368) )
        {
LABEL_51:
          v13 = *(_DWORD *)(v11 + 24);
          if ( v13 >= 0x10 )
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
            *(_DWORD *)(*(_DWORD *)a1 + 24) = v13;
            (**(void (__cdecl ***)(int))a1)(a1);
          }
          if ( !v20[v13 + 30] )
            v20[v13 + 30] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 256);
          memset(v20[v13 + 30], 0, 0x100u);
          v2 = v20;
        }
      }
      else if ( *(_DWORD *)(a1 + 392) )
      {
        goto LABEL_51;
      }
      ++v18;
      ++v19;
      ++v16;
    }
    while ( v16 < *(_DWORD *)(a1 + 296) );
  }
  result = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = -16;
  v2[13] = *(_DWORD *)(a1 + 252);
  return result;
}
