void __thiscall SpeedTree::Mat4x4::Translate(SpeedTree::Mat4x4 *this, const struct SpeedTree::Vec3 *a2)
{
  SpeedTree::Mat4x4::Translate(this, a2->x, a2->y, a2->z);
}
