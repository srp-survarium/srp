bool __userpurge vostok::math::quaternion::get_axis_and_angle@<al>(
        vostok::math::quaternion *this@<esi>,
        vostok::math::float3 *axis@<edi>,
        float *angle)
{
  long double v4; // st7
  float v5; // xmm1_4
  double v6; // st7
  bool result; // al
  const vostok::math::float4x4 *v8; // ecx
  float _Y; // [esp+0h] [ebp-20h]
  float x; // [esp+10h] [ebp-10h]
  __int64 v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+1Ch] [ebp-4h]
  float s; // [esp+24h] [ebp+4h]

  x = this->x;
  v4 = sqrtf((float)((float)(x * x) + (float)(this->y * this->y)) + (float)(this->z * this->z));
  s = v4;
  if ( v4 <= 0.0000001 )
  {
    v8 = clear_value;
    *(_QWORD *)&axis->x = 0;
    *angle = 0.0;
    LODWORD(axis->z) = v8;
    return 0;
  }
  else
  {
    *(float *)&v11 = x * (float)(*(float *)&clear_value / s);
    *((float *)&v11 + 1) = (float)(*(float *)&clear_value / s) * this->y;
    v12 = this->z * (float)(*(float *)&clear_value / s);
    v5 = v12;
    *(_QWORD *)&axis->x = v11;
    axis->z = v5;
    _Y = v4;
    v6 = atan2f(_Y, this->w);
    result = 1;
    *angle = v6 + v6;
  }
  return result;
}
