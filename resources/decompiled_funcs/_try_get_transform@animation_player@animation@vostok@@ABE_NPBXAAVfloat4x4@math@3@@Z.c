char __thiscall vostok::animation::animation_player::try_get_transform(
        vostok::animation::animation_player *this,
        const vostok::animation::animation_player *animated_object,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *resulta)
{
  int m_animated_objects_count; // ebx
  vostok::animation::mixing::animated_object_holder *v5; // eax

  m_animated_objects_count = animated_object->m_mixing_tree.m_animated_objects_count;
  v5 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         animated_object->m_mixing_tree.m_animated_objects,
         &animated_object->m_mixing_tree.m_animated_objects[m_animated_objects_count],
         (const void *const *)&result);
  if ( v5 == &animated_object->m_mixing_tree.m_animated_objects[m_animated_objects_count] || v5->need_new_transform )
    return 0;
  qmemcpy((void *)resulta, v5, sizeof(vostok::math::float4x4));
  return 1;
}
