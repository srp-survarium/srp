long double __thiscall vostok::collision::sphere_geometry_instance::get_surface_area(
        vostok::collision::sphere_geometry_instance *this)
{
  long double v1; // st7

  v1 = sqrtf(
         (float)((float)(this->m_matrix.i.x * this->m_matrix.i.x) + (float)(this->m_matrix.i.y * this->m_matrix.i.y))
       + (float)(this->m_matrix.i.z * this->m_matrix.i.z));
  return v1 * v1 * 12.566371;
}
