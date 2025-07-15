void __thiscall vostok::math::aabb_plane::setup_lut_id(vostok::math::aabb_plane *this)
{
  int v1; // eax

  v1 = (this->plane.normal.x >= 0.0)
     | ~(LODWORD(this->plane.normal.y) >> 30) & 2
     | ~(LODWORD(this->plane.normal.z) >> 29) & 4;
  this->m_lut_id = v1 | (8 * (v1 ^ 7));
}
