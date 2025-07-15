vostok::math::float4x4 *__userpurge vostok::render::skeleton_render_model_instance::get_bone_matrix@<eax>(
        vostok::render::skeleton_render_model_instance *this@<eax>,
        const unsigned __int16 skeleton_bone_idx@<cx>,
        vostok::math::float4x4 *bones_matrices,
        _DWORD *world_space,
        char a5)
{
  int v6; // esi
  vostok::math::float4x4 *v7; // eax
  vostok::math::float4x4 v9; // [esp+10h] [ebp-C0h] BYREF
  vostok::math::float4x4 v10; // [esp+50h] [ebp-80h] BYREF
  vostok::math::float4x4 v11; // [esp+90h] [ebp-40h] BYREF

  v6 = skeleton_bone_idx << 6;
  vostok::math::try_invert4x4(
    (const vostok::math::float4x4 *)((char *)this->m_original.m_object->m_inverted_bones_matrices_in_bind_pose.m_begin
                                   + v6),
    &v10);
  v7 = vostok::math::transpose((const vostok::math::float4x4 *)(v6 + *world_space), &v11);
  vostok::math::mul4x3(v7, &v10, &v9);
  if ( a5 )
    vostok::math::mul4x3(&this->m_transform, &v9, bones_matrices);
  else
    qmemcpy(bones_matrices, &v9, sizeof(vostok::math::float4x4));
  return bones_matrices;
}


vostok::math::float4x4 *__userpurge vostok::render::skeleton_render_model_instance::get_bone_matrix@<eax>(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        vostok::render::skeleton_render_model_instance *a2@<eax>,
        vostok::math::float4x4 *result,
        unsigned __int16 skeleton_bone_idx,
        char world_space)
{
  vostok::render::skeleton_render_model_instance::get_bone_matrix(
    a2,
    skeleton_bone_idx,
    result,
    &a2->m_bones_matrices.m_begin,
    world_space);
  return result;
}
