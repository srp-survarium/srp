vostok::math::float4x4 *__thiscall vostok::animation::mixing::n_ary_tree::get_object_transform(
        vostok::animation::mixing::n_ary_tree *this,
        const vostok::animation::mixing::n_ary_tree *result,
        vostok::math::float4x4 *animated_object,
        const void *animated_objecta)
{
  char v4; // bl
  vostok::animation::mixing::animated_object_holder *v5; // eax
  float v6; // ecx
  vostok::math::float4x4 *p_transform; // esi
  vostok::math::float4x4 *v8; // eax
  vostok::animation::bone_matrices_computer *v9; // ecx
  vostok::animation::bone_matrices_computer *v10; // ecx
  float v11; // ecx
  vostok::math::float4x4 *v12; // eax
  vostok::animation::bone_matrices_computer *v13; // ecx
  vostok::math::float4x4 *object_transform; // eax
  vostok::animation::bone_matrices_computer v16; // [esp+18h] [ebp-98h] BYREF
  vostok::math::float4x4 left; // [esp+30h] [ebp-80h] BYREF
  vostok::math::float4x4 v18; // [esp+70h] [ebp-40h] BYREF

  v4 = 0;
  v5 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         result->m_animated_objects,
         &result->m_animated_objects[result->m_animated_objects_count],
         &animated_objecta);
  v6 = *(float *)&result->m_animation_states;
  p_transform = &v5->transform;
  if ( v6 != 0.0 )
  {
    vostok::animation::bone_matrices_computer::bone_matrices_computer(
      (vostok::animation::mixing::animation_state *)LODWORD(v6),
      result->m_animations_count,
      &v16,
      (vostok::animation::mixing::animation_state *)animated_objecta,
      0);
    vostok::animation::bone_matrices_computer::get_object_transform(v9, v8, &left);
    vostok::animation::bone_matrices_computer::~bone_matrices_computer(v10, (int)&v16);
  }
  v11 = *(float *)&result->m_animation_states;
  if ( v11 != 0.0 )
  {
    v4 = 1;
    vostok::animation::bone_matrices_computer::bone_matrices_computer(
      (vostok::animation::mixing::animation_state *)LODWORD(v11),
      result->m_animations_count,
      &v16,
      (vostok::animation::mixing::animation_state *)animated_objecta,
      0);
    object_transform = vostok::animation::bone_matrices_computer::get_object_transform(v13, v12, &v18);
    vostok::math::mul4x3(&left, object_transform, p_transform);
    p_transform = &left;
  }
  qmemcpy((void *)animated_object, p_transform, sizeof(vostok::math::float4x4));
  if ( (v4 & 1) != 0 )
    vostok::animation::bone_matrices_computer::~bone_matrices_computer(0, (int)&v16);
  return animated_object;
}
