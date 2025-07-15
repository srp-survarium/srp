void __thiscall vostok::render::skeleton_render_model_instance::get_bind_pose(
        vostok::render::skeleton_render_model_instance *this,
        vostok::math::float4x4 *matrices,
        unsigned int count)
{
  unsigned int v3; // ebx
  vostok::render::skeleton_render_model *m_object; // edi
  int v5; // esi

  v3 = count;
  m_object = this->m_original.m_object;
  if ( count )
  {
    v5 = 0;
    do
    {
      vostok::math::float4x4::try_invert(&m_object->m_inverted_bones_matrices_in_bind_pose.m_begin[v5], &matrices[v5]);
      ++v5;
      --v3;
    }
    while ( v3 );
  }
}
