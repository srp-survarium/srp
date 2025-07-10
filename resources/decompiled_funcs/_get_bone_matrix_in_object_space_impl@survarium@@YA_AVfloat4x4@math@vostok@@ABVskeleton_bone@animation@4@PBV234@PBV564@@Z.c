vostok::math::float4x4 *__cdecl survarium::get_bone_matrix_in_object_space_impl(
        vostok::math::float4x4 *result,
        const vostok::animation::skeleton_bone *bone,
        const vostok::math::float4x4 *matrices,
        const vostok::animation::skeleton_bone *first_non_root_bone)
{
  const vostok::math::float4x4 *bone_matrix_in_object_space_impl; // eax
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 *v7; // [esp+8h] [ebp-11Ch]
  survarium::game_options v8; // [esp+5Ch] [ebp-C8h] BYREF
  vostok::math::float4x4 v9; // [esp+DCh] [ebp-48h] BYREF
  unsigned int matrix_index; // [esp+120h] [ebp-4h]

  matrix_index = bone - first_non_root_bone;
  if ( bone->m_parent )
  {
    bone_matrix_in_object_space_impl = survarium::get_bone_matrix_in_object_space_impl(
                                         &v9,
                                         bone->m_parent,
                                         matrices,
                                         first_non_root_bone);
    v7 = vostok::math::operator*(
           (vostok::math::float4x4 *)&v8.m_conflicted_action_to_bind,
           &matrices[matrix_index],
           bone_matrix_in_object_space_impl);
  }
  else
  {
    v5 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&v8);
    v7 = vostok::math::float4x4::identity(v5);
  }
  qmemcpy((void *)result, v7, sizeof(vostok::math::float4x4));
  return result;
}
