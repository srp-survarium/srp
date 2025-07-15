int __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::higher(_DWORD *this, int a2)
{
  int v4; // [esp+1Ch] [ebp-4h]

  v4 = SpeedTree::CArray<SpeedTree::SInstanceLod,1>::lower(a2);
  if ( v4 == this[1] + 32 * this[2] )
  {
    if ( this[2] && *(float *)(this[1] + 4) > (double)*(float *)(a2 + 4) )
      return this[1];
  }
  else if ( *(float *)(a2 + 4) > (double)*(float *)(v4 + 4) )
  {
    v4 += 32;
  }
  return v4;
}


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
