long double __thiscall vostok::collision::cylinder_geometry_instance::get_surface_area(
        vostok::collision::cylinder_geometry_instance *this)
{
  long double v1; // st7
  float v2; // xmm0_4
  long double v3; // st7
  float v4; // xmm0_4
  __int64 v6; // [esp+4h] [ebp-18h]
  float x; // [esp+Ch] [ebp-10h]
  float v8; // [esp+Ch] [ebp-10h]
  float v9; // [esp+18h] [ebp-4h]
  float v10; // [esp+18h] [ebp-4h]

  x = this->m_matrix.i.x;
  v6 = *(_QWORD *)&this->m_matrix.lines[0].elements[1];
  v9 = x;
  v1 = sqrtf(
         (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y) + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
       + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
  v2 = x;
  v8 = v1 + v1;
  v3 = sqrtf(
         (float)((float)(*(float *)&v6 * *(float *)&v6) + (float)(*((float *)&v6 + 1) * *((float *)&v6 + 1)))
       + (float)(v2 * v2));
  v4 = v9;
  v10 = v3 + v8;
  return sqrtf(
           (float)((float)(*(float *)&v6 * *(float *)&v6) + (float)(*((float *)&v6 + 1) * *((float *)&v6 + 1)))
         + (float)(v4 * v4))
       * v10
       * 6.2831855;
}
