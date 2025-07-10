int __thiscall SpeedTree::CBasicFixedString<1024>::operator=(int this, int a2)
{
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 4) )
    memmove((unsigned __int8 *)(this + 8), (unsigned __int8 *)(a2 + 8), *(_DWORD *)(this + 4));
  *(_BYTE *)(this + *(_DWORD *)(this + 4) + 8) = 0;
  return this;
}
