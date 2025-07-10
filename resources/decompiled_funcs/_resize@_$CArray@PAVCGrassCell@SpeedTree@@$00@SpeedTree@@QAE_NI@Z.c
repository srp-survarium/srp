char __thiscall SpeedTree::CArray<SpeedTree::CGrassCell *,1>::resize(_DWORD *this, int a2)
{
  if ( (unsigned __int8)SpeedTree::CArray<void *,1>::reserve(a2) )
  {
    this[2] = a2;
    return 1;
  }
  else
  {
    this[2] = this[3];
    return 0;
  }
}
