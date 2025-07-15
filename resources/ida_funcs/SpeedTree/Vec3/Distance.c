long double __thiscall SpeedTree::Vec3::Distance(SpeedTree::Vec3 *this, const SpeedTree::Vec3 *vIn)
{
  float v2; // xmm2_4
  float v3; // xmm1_4

  v2 = this->z - vIn->z;
  v3 = this->y - vIn->y;
  return sqrtf((float)((float)((float)(this->x - vIn->x) * (float)(this->x - vIn->x)) + (float)(v2 * v2)) + (float)(v3 * v3));
}
