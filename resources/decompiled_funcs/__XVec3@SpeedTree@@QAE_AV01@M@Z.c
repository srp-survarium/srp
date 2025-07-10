_DWORD *__thiscall SpeedTree::Vec3::operator*=(float *this, _DWORD *a2, float a3)
{
  *this = *this * a3;
  this[1] = this[1] * a3;
  this[2] = this[2] * a3;
  *a2 = *(_DWORD *)this;
  a2[1] = *((_DWORD *)this + 1);
  a2[2] = *((_DWORD *)this + 2);
  return a2;
}
