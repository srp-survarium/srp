void __userpurge vostok::render::skeleton_render_model::get_bind_pose(
        unsigned int count@<eax>,
        vostok::render::skeleton_render_model *this,
        vostok::math::float4x4 *matrices)
{
  unsigned int v3; // edi
  int v4; // esi

  v3 = count;
  if ( count )
  {
    v4 = 0;
    do
    {
      vostok::math::float4x4::try_invert(
        &matrices[v4],
        &this->m_inverted_bones_matrices_in_bind_pose._M_impl._M_start[v4]);
      ++v4;
      --v3;
    }
    while ( v3 );
  }
}
