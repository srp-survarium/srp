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
