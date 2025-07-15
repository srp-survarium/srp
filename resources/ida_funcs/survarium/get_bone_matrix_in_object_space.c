vostok::math::float4x4 *__cdecl survarium::get_bone_matrix_in_object_space(
        vostok::math::float4x4 *result,
        const vostok::animation::skeleton_bone *bone,
        const vostok::animation::skeleton *skeleton,
        const vostok::math::float4x4 *matrices)
{
  vostok::animation::skeleton *v4; // ecx
  const vostok::animation::skeleton_bone *root; // esi
  vostok::animation::skeleton *v6; // ecx
  const vostok::animation::skeleton_bone *first_non_root_bone; // [esp+18h] [ebp-4h]

  root = vostok::animation::skeleton::get_root(v4, (int)skeleton);
  first_non_root_bone = &root[vostok::animation::skeleton::get_root_bones_count(v6, (int)skeleton)];
  survarium::get_bone_matrix_in_object_space_impl(result, bone, matrices, first_non_root_bone);
  return result;
}
