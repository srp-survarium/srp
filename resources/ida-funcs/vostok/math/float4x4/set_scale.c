void __usercall vostok::math::float4x4::set_scale(
        vostok::math::float4x4 *this@<esi>,
        const vostok::math::float3 *scale@<edi>)
{
  long double v2; // st7
  long double v3; // st6
  long double v4; // st7
  long double v5; // st6
  long double v6; // st7
  long double v7; // st6
  float x; // [esp+4h] [ebp-8h]
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+4h] [ebp-8h]
  float v11; // [esp+8h] [ebp-4h]
  float v12; // [esp+8h] [ebp-4h]
  float v13; // [esp+8h] [ebp-4h]

  x = this->i.x;
  v2 = scale->x
     / sqrtf((float)((float)(this->i.x * this->i.x) + (float)(this->i.y * this->i.y)) + (float)(this->i.z * this->i.z));
  v11 = v2;
  v3 = v2 * this->i.y;
  this->i.x = x * v11;
  this->i.y = v3;
  this->i.z = v2 * this->i.z;
  v12 = this->j.x;
  v4 = scale->y / sqrtf((float)((float)(v12 * v12) + (float)(this->j.y * this->j.y)) + (float)(this->j.z * this->j.z));
  v9 = v4;
  v5 = v4 * this->j.y;
  this->j.x = v12 * v9;
  this->j.y = v5;
  this->j.z = v4 * this->j.z;
  v13 = this->k.x;
  v6 = scale->z / sqrtf((float)((float)(this->k.y * this->k.y) + (float)(this->k.z * this->k.z)) + (float)(v13 * v13));
  v10 = v6;
  v7 = this->k.y * v6;
  this->k.x = v13 * v10;
  this->k.y = v7;
  this->k.z = v6 * this->k.z;
}
