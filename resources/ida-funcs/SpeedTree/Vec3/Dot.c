double __thiscall SpeedTree::Vec3::Dot(SpeedTree::Vec3 *this, const struct SpeedTree::Vec3 *a2)
{
  return (float)(this->x * a2->x + this->y * a2->y + this->z * a2->z);
}
