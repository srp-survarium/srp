double __thiscall SpeedTree::Vec3::DistanceSquared(SpeedTree::Vec3 *this, const struct SpeedTree::Vec3 *vIn)
{
  SpeedTree::Vec3 *v2; // eax
  SpeedTree::Vec3 result; // [esp+10h] [ebp-Ch] BYREF

  v2 = SpeedTree::Vec3::operator-(this, &result, vIn);
  return vostok::math::float3_pod::squared_length(v2);
}
