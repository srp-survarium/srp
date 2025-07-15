void __thiscall vostok::math::aabb_plane::normalize(vostok::math::aabb_plane *this)
{
  float v1; // xmm1_4

  v1 = s_bm_current_air_resistance
     / fsqrt(
         (float)((float)(this->plane.normal.z * this->plane.normal.z)
               + (float)(this->plane.normal.x * this->plane.normal.x))
       + (float)(this->plane.normal.y * this->plane.normal.y));
  this->plane.normal.x = this->plane.normal.x * v1;
  this->plane.normal.y = v1 * this->plane.normal.y;
  this->plane.normal.z = this->plane.normal.z * v1;
  this->plane.d = this->plane.d * v1;
  vostok::math::aabb_plane::setup_lut_id(this);
}
