void __userpurge vostok::math::quaternion::quaternion(
        vostok::math::quaternion *this@<ecx>,
        float *a2@<esi>,
        vostok::math::float3 angles)
{
  float y; // [esp+4h] [ebp-18h]
  float y_4; // [esp+8h] [ebp-14h]
  float x; // [esp+Ch] [ebp-10h]
  float x_4; // [esp+10h] [ebp-Ch]
  float z; // [esp+14h] [ebp-8h]
  float z_4; // [esp+18h] [ebp-4h]

  angles.x = angles.x * 0.5;
  angles.y = angles.y * 0.5;
  angles.z = 0.5 * angles.z;
  x = sinf(angles.x);
  x_4 = cosf(angles.x);
  y = sinf(angles.y);
  y_4 = cosf(angles.y);
  z = sinf(angles.z);
  z_4 = cosf(angles.z);
  *a2 = (float)-(float)(z_4 * (float)(y_4 * x)) - (float)(z * (float)(y * x_4));
  a2[1] = (float)(z * (float)(y_4 * x)) - (float)(z_4 * (float)(y * x_4));
  a2[2] = (float)-(float)(z * (float)(x_4 * y_4)) - (float)(z_4 * (float)(y * x));
  a2[3] = (float)(z * (float)(y * x)) - (float)(z_4 * (float)(x_4 * y_4));
}
