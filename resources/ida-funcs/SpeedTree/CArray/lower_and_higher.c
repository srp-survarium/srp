int __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::lower_and_higher(
        _DWORD *this,
        int *a2,
        int *a3,
        int *a4)
{
  int result; // eax

  *a3 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::lower(a2);
  *a4 = *a3;
  result = this[1] + 4 * this[2];
  if ( *a4 == result )
  {
    if ( this[2] )
    {
      result = *a2;
      if ( (unsigned int)*a2 < *(_DWORD *)this[1] )
      {
        result = this[1];
        *a4 = result;
      }
    }
  }
  else
  {
    result = (int)a2;
    if ( *(_DWORD *)*a4 < (unsigned int)*a2 )
    {
      result = *a4 + 4;
      *a4 = result;
    }
  }
  return result;
}
