char __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::push_back(int this, const void *a2)
{
  char v4; // [esp+6Bh] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      qmemcpy((void *)(32 * (*(_DWORD *)(this + 8))++ + *(_DWORD *)(this + 4)), a2, 0x20u);
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<SpeedTree::SInstanceLod,1>::reserve(2 * *(_DWORD *)(this + 12) + 1);
    }
    qmemcpy((void *)(32 * (*(_DWORD *)(this + 8))++ + *(_DWORD *)(this + 4)), a2, 0x20u);
  }
  return v4;
}
