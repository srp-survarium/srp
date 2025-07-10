bool __thiscall SpeedTree::Vec3::operator<(float *this, float *a2)
{
  if ( *a2 != *this )
    return *a2 > (double)*this;
  if ( a2[1] == this[1] )
    return a2[2] > (double)this[2];
  return a2[1] > (double)this[1];
}
