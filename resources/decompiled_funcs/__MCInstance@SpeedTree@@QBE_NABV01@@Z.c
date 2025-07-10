char __thiscall SpeedTree::CInstance::operator<(float *this, int a2)
{
  if ( *(float *)a2 != *this || *(float *)(a2 + 4) != this[1] || *(float *)(a2 + 8) != this[2] )
    return SpeedTree::Vec3::operator<(a2);
  if ( *(float *)(a2 + 12) == this[3] )
    return *((unsigned __int8 *)this + 34) < (int)*(unsigned __int8 *)(a2 + 34);
  return *(float *)(a2 + 12) > (double)this[3];
}
