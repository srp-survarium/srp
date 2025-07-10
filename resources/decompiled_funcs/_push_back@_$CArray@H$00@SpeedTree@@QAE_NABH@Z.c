char __thiscall SpeedTree::CArray<int,1>::push_back(int this, _DWORD *a2)
{
  char v4; // [esp+47h] [ebp-1h]

  v4 = 1;
  if ( *(_BYTE *)(this + 16) )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 12) )
      return 0;
    else
      *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  else
  {
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) )
    {
      if ( *(_DWORD *)(this + 12) < 8u )
        *(_DWORD *)(this + 12) = 8;
      SpeedTree::CArray<int,1>::reserve(2 * *(_DWORD *)(this + 12) + 1);
    }
    *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * (*(_DWORD *)(this + 8))++) = *a2;
  }
  return v4;
}
