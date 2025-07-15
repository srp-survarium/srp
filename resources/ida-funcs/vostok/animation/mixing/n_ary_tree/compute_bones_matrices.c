void __userpurge vostok::animation::mixing::n_ary_tree::compute_bones_matrices(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        unsigned int *bones_masks@<eax>,
        vostok::animation::mixing::animation_state *animated_object,
        const vostok::animation::skeleton *skeleton,
        vostok::math::float4x4 *const begin,
        vostok::math::float4x4 *const end)
{
  vostok::animation::bone_matrices_computer *v6; // eax
  vostok::animation::bone_matrices_computer *v7; // ecx
  vostok::animation::bone_matrices_computer *v8; // ecx
  vostok::animation::bone_matrices_computer v10; // [esp+0h] [ebp-18h] BYREF

  vostok::animation::bone_matrices_computer::bone_matrices_computer(
    this->m_animation_states,
    this->m_animations_count,
    &v10,
    animated_object,
    skeleton);
  vostok::animation::bone_matrices_computer::compute_bones_matrices(v7, v6, begin, bones_masks);
  vostok::animation::bone_matrices_computer::~bone_matrices_computer(v8, (int)&v10);
}
