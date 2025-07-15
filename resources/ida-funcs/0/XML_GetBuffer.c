int __cdecl XML_GetBuffer(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  unsigned __int8 *dst; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 480);
  if ( v3 == 2 )
  {
    *(_DWORD *)(a1 + 284) = 36;
    return 0;
  }
  if ( v3 == 3 )
  {
    *(_DWORD *)(a1 + 284) = 33;
    return 0;
  }
  if ( a2 > *(_DWORD *)(a1 + 32) - *(_DWORD *)(a1 + 28) )
  {
    v8 = *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 8);
    if ( v8 > 1024 )
      v8 = 1024;
    v9 = v8 + a2 + *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 24);
    if ( v9 > *(_DWORD *)(a1 + 32) - *(_DWORD *)(a1 + 8) )
    {
      v5 = *(_DWORD *)(a1 + 32) - *(_DWORD *)(a1 + 24);
      if ( !v5 )
        v5 = 1024;
      do
        v5 *= 2;
      while ( v5 < v9 );
      dst = (unsigned __int8 *)(*(int (__cdecl **)(int))(a1 + 12))(v5);
      if ( !dst )
      {
        *(_DWORD *)(a1 + 284) = 1;
        return 0;
      }
      *(_DWORD *)(a1 + 32) = &dst[v5];
      if ( *(_DWORD *)(a1 + 24) )
      {
        v4 = *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 8);
        if ( v4 > 1024 )
          v4 = 1024;
        memcpy((int)dst, (const __m128i *)(*(_DWORD *)(a1 + 24) - v4), v4 + *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 24));
        (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 8));
        *(_DWORD *)(a1 + 8) = dst;
        *(_DWORD *)(a1 + 28) = v4 + *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 8);
        *(_DWORD *)(a1 + 24) = v4 + *(_DWORD *)(a1 + 8);
      }
      else
      {
        *(_DWORD *)(a1 + 28) = &dst[*(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 24)];
        *(_DWORD *)(a1 + 8) = dst;
        *(_DWORD *)(a1 + 24) = dst;
      }
    }
    else if ( v8 < *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 8) )
    {
      v7 = *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 8) - v8;
      memmove(
        *(_DWORD *)(a1 + 8),
        (const __m128i *)(v7 + *(_DWORD *)(a1 + 8)),
        v8 + *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 24));
      *(_DWORD *)(a1 + 28) -= v7;
      *(_DWORD *)(a1 + 24) -= v7;
    }
    *(_DWORD *)(a1 + 292) = 0;
    *(_DWORD *)(a1 + 288) = 0;
    *(_DWORD *)(a1 + 296) = 0;
  }
  return *(_DWORD *)(a1 + 28);
}
