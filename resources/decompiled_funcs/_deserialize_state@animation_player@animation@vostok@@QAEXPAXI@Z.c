void __userpurge vostok::animation::animation_player::deserialize_state(
        vostok::animation::animation_player *this@<ecx>,
        char *buffer@<eax>,
        unsigned int time_in_ms)
{
  unsigned int *v3; // eax
  vostok::animation::mixing::n_ary_tree *v5; // ecx
  const vostok::animation::mixing::n_ary_tree *v6; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  vostok::animation::animation_player *v8; // eax
  vostok::animation::mixing::n_ary_tree *p_m_mixing_tree; // esi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v10; // eax
  const vostok::animation::mixing::n_ary_tree *v11; // edi
  vostok::animation::mixing::n_ary_tree *v12; // ecx
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::animation::mixing::n_ary_tree_animation_node *j; // ebp
  unsigned int m_animations_count; // [esp-Ch] [ebp-104h]
  unsigned int m_animated_objects_count; // [esp-8h] [ebp-100h]
  vostok::animation::mixing::n_ary_tree *v18; // [esp+0h] [ebp-F8h]
  vostok::mutable_buffer mixing_buffer; // [esp+10h] [ebp-E8h] BYREF
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functor; // [esp+18h] [ebp-E0h] BYREF
  _DWORD *v21; // [esp+38h] [ebp-C0h]
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor v22; // [esp+68h] [ebp-90h] BYREF

  v3 = (unsigned int *)(buffer + 4);
  v5 = (vostok::animation::mixing::n_ary_tree *)*v3;
  v6 = (const vostok::animation::mixing::n_ary_tree *)(v3 + 1);
  this->m_mixing_tree_buffer_size = *v3;
  if ( v3[8] )
  {
    for ( i = (vostok::animation::mixing::n_ary_tree_animation_node *)v3[2]; i; i = i->m_next_weight_animation )
      vostok::animation::invert_animation_times(i, time_in_ms);
    v6->m_tree_actual_time_in_ms = time_in_ms;
    v8 = (vostok::animation::animation_player *)this->m_tree_buffers[1];
    if ( this != (vostok::animation::animation_player *)this->m_current_buffer )
      v8 = this;
    this->m_current_buffer = (char (*)[16384])v8;
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &mixing_buffer,
      (unsigned __int8 *)v8,
      0x4000u);
    p_m_mixing_tree = &this->m_mixing_tree;
    m_animated_objects_count = v6->m_animated_objects_count;
    m_animations_count = v6->m_animations_count;
    get_transform_functor.vtable = 0;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::n_ary_tree_transition_tree_constructor(
      &v22,
      &mixing_buffer,
      v6,
      v6,
      m_animations_count,
      m_animated_objects_count,
      time_in_ms,
      &this->m_first_subscribed_channel,
      &get_transform_functor);
    v11 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::computed_tree(v10, v18);
    vostok::animation::mixing::n_ary_tree::operator=(p_m_mixing_tree, v11);
    vostok::animation::mixing::n_ary_tree::destroy(v12);
    if ( v21 )
      --*v21;
    if ( v22.m_get_transform_functor.vtable )
    {
      if ( ((int)v22.m_get_transform_functor.vtable & 1) == 0 )
      {
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v22.m_get_transform_functor.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&v22.m_get_transform_functor.functor, &v22.m_get_transform_functor.functor, 2);
      }
      v22.m_get_transform_functor.vtable = 0;
    }
    if ( get_transform_functor.vtable )
    {
      if ( ((int)get_transform_functor.vtable & 1) == 0 )
      {
        v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)get_transform_functor.vtable & 0xFFFFFFFE);
        if ( v14 )
          v14(&get_transform_functor.functor, &get_transform_functor.functor, 2);
      }
    }
    vostok::animation::mixing::n_ary_tree::adjust_animation_events_times(p_m_mixing_tree, v6);
    for ( j = v6->m_weight_root; j; j = j->m_next_weight_animation )
      vostok::animation::invert_animation_times(j, time_in_ms);
  }
  else
  {
    vostok::animation::mixing::n_ary_tree::destroy(v5);
    if ( this->m_mixing_tree.m_reference_counter.m_object )
      --this->m_mixing_tree.m_reference_counter.m_object->m_reference_count;
    if ( this != (vostok::animation::animation_player *)-34048 )
    {
      this->m_mixing_tree.m_reference_counter.m_object = 0;
      this->m_mixing_tree.m_weight_root = 0;
      this->m_mixing_tree.m_time_root = 0;
      this->m_mixing_tree.m_interpolators = 0;
      this->m_mixing_tree.m_animation_states = 0;
      this->m_mixing_tree.m_animation_events = 0;
      this->m_mixing_tree.m_animated_objects = 0;
      this->m_mixing_tree.m_animations_count = 0;
      this->m_mixing_tree.m_animated_objects_count = 0;
      this->m_mixing_tree.m_interpolators_count = 0;
      this->m_mixing_tree.m_tree_actual_time_in_ms = 0;
      this->m_mixing_tree.m_is_logging_enabled = 0;
    }
  }
}
