void __thiscall SpeedTree::Vec3::Normalize(SpeedTree::Vec3 *this)
{
  float v1; // [esp+8h] [ebp-14h]
  float v2; // [esp+Ch] [ebp-10h]
  float v4; // [esp+14h] [ebp-8h]

  v4 = vostok::math::float3_pod::squared_length(this);
  v2 = sqrt(v4);
  if ( v2 > 0.0000001192092895507812 )
  {
    v1 = 1.0 / v2;
    SpeedTree::Vec3::Scale(this, v1);
  }
}
