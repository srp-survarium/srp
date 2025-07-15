long double __thiscall vostok::collision::box_geometry_instance::get_surface_area(
        vostok::collision::box_geometry_instance *this)
{
  float v3; // [esp+8h] [ebp-Ch]
  float v4; // [esp+Ch] [ebp-8h]

  v3 = sqrtf(
         (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y) + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
       + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  v4 = sqrtf(
         (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y) + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
       + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
  return (sqrtf(
            (float)((float)(this->m_matrix.k.z * this->m_matrix.k.z) + (float)(this->m_matrix.k.x * this->m_matrix.k.x))
          + (float)(this->m_matrix.k.y * this->m_matrix.k.y))
        * (v3 + v4)
        + v3 * v4)
       * 8.0;
}
