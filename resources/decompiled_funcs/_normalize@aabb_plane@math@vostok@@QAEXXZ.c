void __thiscall vostok::math::aabb_plane::normalize(vostok::math::aabb_plane *this)
{
  long double v2; // st7
  float x; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  int v6; // eax
  float v7; // [esp+8h] [ebp-10h]

  v2 = 1.0
     / sqrtf(
         (float)((float)(this->plane.normal.z * this->plane.normal.z)
               + (float)(this->plane.normal.x * this->plane.normal.x))
       + (float)(this->plane.normal.y * this->plane.normal.y));
  x = this->plane.normal.x;
  v7 = v2;
  v4 = v7 * this->plane.normal.y;
  v5 = this->plane.normal.z * v7;
  this->plane.d = v2 * this->plane.d;
  v6 = (COERCE_INT(x * v7) >= 0) | ~(LODWORD(v4) >> 30) & 2 | ~(LODWORD(v5) >> 29) & 4;
  this->plane.normal.x = x * v7;
  this->plane.normal.y = v4;
  this->plane.normal.z = v5;
  this->m_lut_id = v6 | (8 * (v6 ^ 7));
}
