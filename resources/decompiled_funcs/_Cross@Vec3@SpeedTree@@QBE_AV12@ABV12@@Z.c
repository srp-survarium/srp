SpeedTree::Vec3 *__thiscall SpeedTree::Vec3::Cross(
        SpeedTree::Vec3 *this,
        SpeedTree::Vec3 *result,
        const SpeedTree::Vec3 *vIn)
{
  float z; // xmm5_4
  float y; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  SpeedTree::Vec3 *v7; // eax
  float x; // xmm1_4
  float v9; // xmm0_4

  z = this->z;
  y = this->y;
  v5 = vIn->z;
  v6 = vIn->y;
  v7 = result;
  x = vIn->x;
  result->x = (float)(y * v5) - (float)(z * v6);
  v9 = (float)(this->x * v6) - (float)(x * y);
  result->y = (float)(x * z) - (float)(this->x * v5);
  result->z = v9;
  return v7;
}
