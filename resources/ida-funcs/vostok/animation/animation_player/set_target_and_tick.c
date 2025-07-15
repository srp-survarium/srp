char __userpurge vostok::animation::animation_player::set_target_and_tick@<al>(
        vostok::animation::animation_player *this@<edi>,
        const vostok::math::float4x4 *transform_in_case_of_a_single_object_usage@<ecx>,
        const vostok::animation::mixing::expression *expression,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  vostok::animation::animation_player *v4; // ecx
  vostok::animation::animation_player *v5; // ecx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<vostok::math::float4x4,vostok::math::float4x4 (__cdecl*)(vostok::math::float4x4 const &,void const *),boost::_bi::list2<boost::reference_wrapper<vostok::math::float4x4 const >,boost::arg<1> > > v8; // [esp-8h] [ebp-38h]
  char v9; // [esp+Fh] [ebp-21h]
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functor; // [esp+10h] [ebp-20h] BYREF

  v8.l_.a1_.t_ = transform_in_case_of_a_single_object_usage;
  v8.f_ = (vostok::math::float4x4 *(__cdecl *)(vostok::math::float4x4 *, const vostok::math::float4x4 *, const void *))vostok::animation::single_object_get_transform;
  get_transform_functor.vtable = 0;
  boost::function1<vostok::math::float4x4,void const *>::assign_to<boost::_bi::bind_t<vostok::math::float4x4,vostok::math::float4x4 (__cdecl *)(vostok::math::float4x4 const &,void const *),boost::_bi::list2<boost::reference_wrapper<vostok::math::float4x4 const>,boost::arg<1>>>>(
    (boost::function1<vostok::math::float4x4,void const *> *)transform_in_case_of_a_single_object_usage,
    (boost::_bi::bind_t<vostok::math::float4x4,vostok::math::float4x4 (__cdecl*)(vostok::math::float4x4 const &,void const *),boost::_bi::list2<boost::reference_wrapper<vostok::math::float4x4 const >,boost::arg<1> > > *)&get_transform_functor,
    v8);
  if ( this->m_mixing_tree.m_animations_count )
    vostok::animation::animation_player::tick(v4, (int)this, current_time_in_ms);
  v9 = vostok::animation::animation_player::set_target(
         expression,
         (vostok::animation::mixing::n_ary_tree_converter *)v4,
         this,
         (char *)current_time_in_ms,
         &get_transform_functor);
  vostok::animation::animation_player::tick(v5, (int)this, current_time_in_ms);
  if ( get_transform_functor.vtable )
  {
    if ( ((int)get_transform_functor.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)get_transform_functor.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&get_transform_functor.functor, &get_transform_functor.functor, 2);
    }
  }
  return v9;
}


char __userpurge vostok::animation::animation_player::set_target_and_tick@<al>(
        vostok::animation::animation_player *this@<esi>,
        vostok::animation::subscribed_channel **current_time_in_ms@<edi>,
        vostok::animation::animation_player *a3@<ecx>,
        const vostok::animation::mixing::expression *expression,
        boost::function<vostok::math::float4x4 __cdecl(void const *)> *get_transform_functor)
{
  char v5; // bl
  vostok::animation::animation_player *v6; // ecx

  if ( this->m_mixing_tree.m_animations_count )
    vostok::animation::animation_player::tick(a3, (int)this, current_time_in_ms);
  v5 = vostok::animation::animation_player::set_target(
         expression,
         (vostok::animation::mixing::n_ary_tree_converter *)a3,
         this,
         (char *)current_time_in_ms,
         get_transform_functor);
  vostok::animation::animation_player::tick(v6, (int)this, current_time_in_ms);
  return v5;
}
