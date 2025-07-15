_BYTE *__cdecl png_do_packswap(int a1, _BYTE *a2)
{
  _BYTE *result; // eax
  unsigned int v3; // [esp+0h] [ebp-Ch]
  _BYTE *v4; // [esp+4h] [ebp-8h]
  _BYTE *i; // [esp+8h] [ebp-4h]

  result = (_BYTE *)a1;
  if ( *(unsigned __int8 *)(a1 + 9) < 8u )
  {
    v3 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
    if ( *(_BYTE *)(a1 + 9) == 1 )
    {
      v4 = &unk_6F3EE8;
    }
    else if ( *(_BYTE *)(a1 + 9) == 2 )
    {
      v4 = &unk_6F3FE8;
    }
    else
    {
      result = (_BYTE *)*(unsigned __int8 *)(a1 + 9);
      if ( result != (_BYTE *)4 )
        return result;
      v4 = &unk_6F40E8;
    }
    for ( i = a2; ; ++i )
    {
      result = i;
      if ( (unsigned int)i >= v3 )
        break;
      *i = v4[(unsigned __int8)*i];
    }
  }
  return result;
}
