int __thiscall SpeedTree::CBasicString<1>::operator=(int this, unsigned __int8 *buf)
{
  unsigned int v2; // eax
  unsigned int count; // [esp+44h] [ebp-4h]

  if ( buf )
  {
    strlen(buf);
    count = v2;
    SpeedTree::CArray<char,1>::reserve(v2 + 1);
    if ( count )
      memmove(*(unsigned __int8 **)(this + 4), buf, count);
    *(_DWORD *)(this + 8) = count;
    *(_BYTE *)(*(_DWORD *)(this + 4) + *(_DWORD *)(this + 8)) = 0;
  }
  else
  {
    SpeedTree::CBasicString<1>::operator=((unsigned __int8 *)&::buf);
  }
  return this;
}
