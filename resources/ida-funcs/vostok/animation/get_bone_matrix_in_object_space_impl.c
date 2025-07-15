vostok::math::float4x4 *__cdecl vostok::animation::get_bone_matrix_in_object_space_impl(
        vostok::math::float4x4 *result,
        const vostok::animation::skeleton_bone *bone,
        const vostok::math::float4x4 *matrices,
        const vostok::animation::skeleton_bone *first_non_root_bone)
{
  vostok::math::float4x4 *v4; // ecx
  const vostok::animation::skeleton_bone *m_parent; // eax
  const vostok::math::float4x4 *bone_matrix_in_object_space_impl; // eax
  vostok::math::float4x4 *v7; // eax
  vostok::math::float4x4 *v8; // esi
  vostok::math::float4x4 *v9; // eax
  vostok::math::float4x4 v10; // [esp+8h] [ebp-C0h] BYREF
  vostok::math::float4x4 resulta; // [esp+48h] [ebp-80h] BYREF
  vostok::math::float4x4 v12; // [esp+88h] [ebp-40h] BYREF

  m_parent = bone->m_parent;
  if ( m_parent )
  {
    bone_matrix_in_object_space_impl = vostok::animation::get_bone_matrix_in_object_space_impl(
                                         &resulta,
                                         m_parent,
                                         matrices,
                                         first_non_root_bone);
    vostok::math::mul4x3(bone_matrix_in_object_space_impl, &matrices[bone - first_non_root_bone], &v12);
    v7 = &v12;
  }
  else
  {
    v7 = vostok::math::float4x4::identity(v4, &v10);
  }
  v8 = v7;
  v9 = result;
  qmemcpy(result, v8, sizeof(vostok::math::float4x4));
  return v9;
}
