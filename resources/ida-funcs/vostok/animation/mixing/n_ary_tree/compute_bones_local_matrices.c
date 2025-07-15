void __userpurge vostok::animation::mixing::n_ary_tree::compute_bones_local_matrices(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        const vostok::animation::skeleton *skeleton@<eax>,
        vostok::animation::mixing::animation_state *animated_object,
        vostok::math::float4x4 *const begin,
        vostok::animation::bone_matrices_computer *end,
        unsigned int *bones_masks)
{
  vostok::animation::bone_matrices_computer *v6; // ecx
  vostok::animation::bone_matrices_computer computer; // [esp+0h] [ebp-18h] BYREF

  vostok::animation::bone_matrices_computer::bone_matrices_computer(
    this->m_animation_states,
    this->m_animations_count,
    &computer,
    animated_object,
    skeleton);
  vostok::animation::bone_matrices_computer::compute_bones_local_matrices(
    end,
    &computer,
    begin,
    (const unsigned int *)end);
  vostok::animation::bone_matrices_computer::~bone_matrices_computer(v6, (int)&computer);
}
