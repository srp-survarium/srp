int __cdecl XML_Parse(int a1, const __m128i *src, unsigned int count, int a4)
{
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]
  unsigned __int8 *dst; // [esp+8h] [ebp-4h]

  v6 = *(_DWORD *)(a1 + 480);
  if ( v6 )
  {
    if ( v6 == 2 )
    {
      *(_DWORD *)(a1 + 284) = 36;
      return 0;
    }
    if ( v6 == 3 )
    {
      *(_DWORD *)(a1 + 284) = 33;
      return 0;
    }
  }
  else if ( !*(_DWORD *)(a1 + 476) && !(unsigned __int8)sub_640730(a1) )
  {
    *(_DWORD *)(a1 + 284) = 1;
    return 0;
  }
  *(_DWORD *)(a1 + 480) = 1;
  if ( count )
  {
    dst = (unsigned __int8 *)XML_GetBuffer(a1, count);
    if ( dst )
    {
      memcpy((int)dst, src, count);
      return XML_ParseBuffer(a1, count, a4);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 484) = a4;
    if ( !a4 )
      return 1;
    *(_DWORD *)(a1 + 296) = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 284) = (*(int (__cdecl **)(int, _DWORD, _DWORD, int))(a1 + 280))(
                              a1,
                              *(_DWORD *)(a1 + 24),
                              *(_DWORD *)(a1 + 40),
                              a1 + 24);
    if ( *(_DWORD *)(a1 + 284) )
    {
      *(_DWORD *)(a1 + 292) = *(_DWORD *)(a1 + 288);
      *(_DWORD *)(a1 + 280) = XML_GetErrorCode;
      return 0;
    }
    else
    {
      v5 = *(_DWORD *)(a1 + 480);
      if ( v5 >= 0 )
      {
        if ( v5 <= 1 )
        {
          *(_DWORD *)(a1 + 480) = 2;
        }
        else if ( v5 == 3 )
        {
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int))(*(_DWORD *)(a1 + 144) + 52))(
            *(_DWORD *)(a1 + 144),
            *(_DWORD *)(a1 + 296),
            *(_DWORD *)(a1 + 24),
            a1 + 408);
          *(_DWORD *)(a1 + 296) = *(_DWORD *)(a1 + 24);
          return 2;
        }
      }
      return 1;
    }
  }
}
