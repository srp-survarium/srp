void __userpurge vostok::animation::mixing::n_ary_tree::set_objects_transform(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree *thisa)
{
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // esi
  vostok::animation::mixing::animated_object_holder *i; // edi
  vostok::math::float4x4 *object_transform; // eax
  vostok::animation::mixing::n_ary_tree *v6; // ecx
  vostok::math::float4x4 animated_object; // [esp+10h] [ebp-40h] BYREF

  m_animated_objects = thisa->m_animated_objects;
  for ( i = &m_animated_objects[thisa->m_animated_objects_count]; m_animated_objects != i; ++m_animated_objects )
  {
    object_transform = vostok::animation::mixing::n_ary_tree::get_object_transform(
                         (vostok::animation::mixing::n_ary_tree *)&animated_object,
                         thisa,
                         &animated_object,
                         m_animated_objects->animated_object);
    vostok::animation::mixing::n_ary_tree::set_object_transform(
      v6,
      (int)thisa,
      a2,
      m_animated_objects->animated_object,
      object_transform);
  }
}
