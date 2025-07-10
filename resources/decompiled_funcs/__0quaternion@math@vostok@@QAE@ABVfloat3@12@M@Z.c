void __userpurge vostok::math::quaternion::quaternion(
        vostok::math::quaternion *this@<esi>,
        const vostok::math::float3 *direction@<edi>,
        float angle)
{
  double v3; // st7
  double v4; // st7
  float sin_cos; // [esp+8h] [ebp-Ch]
  vostok::math::sine_cosine sin_cosa; // [esp+8h] [ebp-Ch]
  float v7; // [esp+10h] [ebp-4h]
  float anglea; // [esp+18h] [ebp+4h]

  anglea = angle * 0.5;
  sin_cos = sinf(anglea);
  this->w = cosf(anglea);
  v3 = sin_cos;
  sin_cosa.sine = direction->x * sin_cos;
  sin_cosa.cosine = direction->y * v3;
  v4 = v3 * direction->z;
  *(vostok::math::sine_cosine *)&this->x = sin_cosa;
  v7 = v4;
  this->z = v7;
}
