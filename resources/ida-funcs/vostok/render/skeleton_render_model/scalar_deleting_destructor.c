vostok::render::skeleton_render_model *__thiscall vostok::render::skeleton_render_model::`scalar deleting destructor'(
        vostok::render::skeleton_render_model *this,
        char a2)
{
  vostok::fixed_vector<vostok::math::float4x4,128> *p_m_inverted_bones_matrices_in_bind_pose; // eax
  vostok::math::float4x4 *m_begin; // ecx

  p_m_inverted_bones_matrices_in_bind_pose = &this->m_inverted_bones_matrices_in_bind_pose;
  m_begin = this->m_inverted_bones_matrices_in_bind_pose.m_begin;
  p_m_inverted_bones_matrices_in_bind_pose->m_end = m_begin;
  vostok::render::render_model::~render_model((vostok::render::render_model *)m_begin, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
