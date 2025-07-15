vostok::math::float4x4 *__userpurge transform_getter::get_transform@<eax>(
        transform_getter *this@<ecx>,
        const stlp_std::random_access_iterator_tag *a2@<edi>,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *animated_object)
{
  boost::function1<vostok::math::float4x4,void const *> *v5; // ecx
  vostok::math::float4x4 *v6; // eax
  _BYTE v7[64]; // [esp+8h] [ebp-40h] BYREF

  if ( vostok::animation::animation_player::try_get_transform(
         (vostok::animation::animation_player *)this,
         a2,
         (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)this->animation_player,
         animated_object,
         (vostok::animation::mixing::animated_object_holder *)v7) )
  {
    v6 = result;
    qmemcpy(result, v7, sizeof(vostok::math::float4x4));
  }
  else
  {
    boost::function1<vostok::math::float4x4,void const *>::operator()(
      v5,
      &this->functor->vtable,
      result,
      animated_object);
    return result;
  }
  return v6;
}
