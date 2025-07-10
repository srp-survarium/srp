void __userpurge vostok::animation::mixing::n_ary_tree::convert_to_object_matrices(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        const vostok::animation::skeleton *skeleton@<eax>,
        vostok::animation::mixing::animation_state *animated_object,
        vostok::math::float4x4 *const begin,
        vostok::math::float4x4 *const end)
{
  vostok::animation::bone_matrices_computer *v5; // eax
  vostok::animation::bone_matrices_computer *v6; // ecx
  vostok::animation::bone_matrices_computer v7; // [esp+0h] [ebp-18h] BYREF

  vostok::animation::bone_matrices_computer::bone_matrices_computer(
    this->m_animation_states,
    this->m_animations_count,
    &v7,
    animated_object,
    skeleton);
  vostok::animation::bone_matrices_computer::convert_to_object_matrices(
    begin,
    v5,
    (vostok::math::float4x4 *)v7.m_animated_object);
  vostok::animation::bone_matrices_computer::~bone_matrices_computer(v6, (int)&v7);
}
