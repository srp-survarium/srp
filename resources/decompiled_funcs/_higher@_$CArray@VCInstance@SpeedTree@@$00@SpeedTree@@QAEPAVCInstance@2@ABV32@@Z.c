float *__thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::higher(_DWORD *this, float *a2)
{
  float *v4; // [esp+14h] [ebp-4h]

  v4 = (float *)SpeedTree::CArray<SpeedTree::CInstance,1>::lower(this, (int)a2);
  if ( v4 == (float *)(this[1] + 36 * this[2]) )
  {
    if ( this[2] && SpeedTree::CInstance::operator<(a2, this[1]) )
      return (float *)this[1];
  }
  else if ( SpeedTree::CInstance::operator<(v4, (int)a2) )
  {
    v4 += 9;
  }
  return v4;
}
