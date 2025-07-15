vostok::math::aabb *__thiscall vostok::render::user_render_model_instance::get_aabb(
        vostok::render::user_render_model_instance *this,
        vostok::math::aabb *result)
{
  vostok::render::user_render_surface *m_surface; // ecx
  vostok::math::aabb *v3; // eax
  __int64 v4; // xmm0_8

  m_surface = this->m_surface;
  v3 = result;
  v4 = *(_QWORD *)&m_surface->m_aabbox.min.x;
  m_surface = (vostok::render::user_render_surface *)((char *)m_surface + 8);
  *(_QWORD *)&result->min.x = v4;
  *(_QWORD *)&result->min.elements[2] = *(_QWORD *)&m_surface->m_aabbox.min.x;
  *(_QWORD *)&result->max.elements[1] = *(_QWORD *)&m_surface->m_aabbox.min.elements[2];
  return v3;
}
