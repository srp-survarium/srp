float *__thiscall SpeedTree::Vec3::operator*(float *this, float *a2, float a3)
{
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = a3 * *this;
  v5 = a3 * this[1];
  v6 = a3 * this[2];
  *a2 = v4;
  a2[1] = v5;
  a2[2] = v6;
  return a2;
}


SpeedTree::Vec3 *__thiscall SpeedTree::Vec3::operator-(
        SpeedTree::Vec3 *this,
        SpeedTree::Vec3 *result,
        const SpeedTree::Vec3 *vIn)
{
  SpeedTree::Vec3 *v3; // eax

  v3 = result;
  result->x = this->x - vIn->x;
  result->y = this->y - vIn->y;
  result->z = this->z - vIn->z;
  return v3;
}


float *__thiscall SpeedTree::Vec3::operator+(float *this, float *a2, float *a3)
{
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = *a3 + *this;
  v5 = a3[1] + this[1];
  v6 = a3[2] + this[2];
  *a2 = v4;
  a2[1] = v5;
  a2[2] = v6;
  return a2;
}


bool __thiscall SpeedTree::Vec3::operator<(float *this, float *a2)
{
  if ( *a2 != *this )
    return *a2 > (double)*this;
  if ( a2[1] == this[1] )
    return a2[2] > (double)this[2];
  return a2[1] > (double)this[1];
}


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
