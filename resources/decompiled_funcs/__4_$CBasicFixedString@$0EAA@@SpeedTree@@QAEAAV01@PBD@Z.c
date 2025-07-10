int __thiscall SpeedTree::CBasicFixedString<1024>::operator=(int this, unsigned __int8 *buf)
{
  unsigned int v2; // eax
  unsigned int count; // [esp+4h] [ebp-4h]

  if ( buf )
  {
    strlen(buf);
    count = v2;
    if ( v2 )
      memmove((unsigned __int8 *)(this + 8), buf, v2);
    *(_DWORD *)(this + 4) = count;
    *(_BYTE *)(this + *(_DWORD *)(this + 4) + 8) = 0;
  }
  else
  {
    *(_DWORD *)(this + 4) = 0;
    *(_BYTE *)(this + 8) = 0;
  }
  return this;
}
