void __userpurge vostok::render::skeleton_render_model_instance::update_render_matrices(
        unsigned int count@<eax>,
        vostok::render::skeleton_render_model_instance *this,
        const vostok::math::float4x4 *matrices)
{
  int v3; // ebx
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 *v5; // edi
  bool v6; // zf
  unsigned int v7; // [esp+Ch] [ebp-84h]
  vostok::math::float4x4 result; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v9; // [esp+50h] [ebp-40h] BYREF

  if ( count )
  {
    v3 = 0;
    v7 = count;
    do
    {
      qmemcpy(
        (void *)&this->m_prev_bones_matrices._M_impl._M_start[v3],
        &this->m_bones_matrices._M_impl._M_start[v3],
        sizeof(this->m_prev_bones_matrices._M_impl._M_start[v3]));
      vostok::math::mul4x3(
        &result,
        &this->m_original.m_object->m_inverted_bones_matrices_in_bind_pose._M_impl._M_start[v3],
        &matrices[v3]);
      v4 = vostok::math::transpose(&v9, &result);
      v5 = &this->m_bones_matrices._M_impl._M_start[v3++];
      v6 = v7-- == 1;
      qmemcpy((void *)v5, v4, sizeof(vostok::math::float4x4));
    }
    while ( !v6 );
  }
}
