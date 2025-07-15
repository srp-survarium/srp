vostok::math::float4x4 *__usercall vostok::animation::animation_player::get_object_transform@<eax>(
        vostok::animation::animation_player *this@<ecx>,
        const void *a2@<esi>)
{
  vostok::animation::mixing::n_ary_tree::get_object_transform(
    &this->m_mixing_tree,
    (vostok::math::float4x4 *)&this->m_mixing_tree,
    a2);
  return (vostok::math::float4x4 *)a2;
}
