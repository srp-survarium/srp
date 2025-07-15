vostok::math::float4x4 *__usercall vostok::animation::get_bone_matrix_in_object_space@<eax>(
        const vostok::animation::skeleton *skeleton@<esi>,
        vostok::math::float4x4 *bone,
        const vostok::animation::skeleton_bone *matrices,
        vostok::math::float4x4 *matricesa)
{
  vostok::animation::get_bone_matrix_in_object_space_impl(
    bone,
    matrices,
    matricesa,
    (const vostok::animation::skeleton_bone *)&skeleton[1]
  + (skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
   - (int)&skeleton[1])
  / 28);
  return bone;
}
