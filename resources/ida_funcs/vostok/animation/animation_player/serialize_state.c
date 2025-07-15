void __userpurge vostok::animation::animation_player::serialize_state(
        char *buffer@<eax>,
        unsigned int buffer_size@<ecx>,
        vostok::animation::animation_player *this)
{
  char v3; // bl
  vostok::animation::mixing::n_ary_tree *v4; // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  unsigned int m_animated_objects_count; // edx
  unsigned int m_tree_actual_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v8; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // edi
  unsigned int i; // ebp
  vostok::animation::mixing::n_ary_tree *v11; // [esp+0h] [ebp-C8h]
  vostok::mutable_buffer tree_buffer; // [esp+10h] [ebp-B8h] BYREF
  boost::function<vostok::math::float4x4 __cdecl(void const *)> get_transform_functor; // [esp+18h] [ebp-B0h] BYREF
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor v14; // [esp+38h] [ebp-90h] BYREF

  v3 = 0;
  tree_buffer.m_data = 0;
  *(_DWORD *)buffer = -1315241803;
  *((_DWORD *)buffer + 1) = this->m_mixing_tree_buffer_size;
  v4 = (vostok::animation::mixing::n_ary_tree *)(buffer + 8);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &tree_buffer,
    (unsigned __int8 *)buffer + 8,
    buffer_size);
  tree_buffer.m_data += 48;
  tree_buffer.m_size -= 48;
  if ( this->m_mixing_tree_buffer_size )
  {
    if ( v4 )
    {
      m_animated_objects_count = this->m_mixing_tree.m_animated_objects_count;
      m_tree_actual_time_in_ms = this->m_mixing_tree.m_tree_actual_time_in_ms;
      get_transform_functor.vtable = 0;
      v3 = 3;
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::n_ary_tree_transition_tree_constructor(
        &v14,
        &tree_buffer,
        &this->m_mixing_tree,
        &this->m_mixing_tree,
        this->m_mixing_tree.m_animations_count,
        m_animated_objects_count,
        m_tree_actual_time_in_ms,
        &this->m_first_subscribed_channel,
        &get_transform_functor);
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::computed_tree(v8, v11);
    }
    if ( (v3 & 2) != 0 )
    {
      v3 &= ~2u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v5,
        (int *)&v14);
    }
    if ( (v3 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v5,
        (int *)&get_transform_functor);
  }
  else if ( v4 )
  {
    v4->m_reference_counter.m_object = 0;
    v4->m_weight_root = 0;
    v4->m_time_root = 0;
    v4->m_interpolators = 0;
    v4->m_animation_states = 0;
    v4->m_animation_events = 0;
    v4->m_animated_objects = 0;
    v4->m_animations_count = 0;
    v4->m_animated_objects_count = 0;
    v4->m_interpolators_count = 0;
    v4->m_tree_actual_time_in_ms = 0;
    v4->m_is_logging_enabled = 0;
  }
  vostok::animation::mixing::n_ary_tree::adjust_animation_events_times(v4, &this->m_mixing_tree);
  m_weight_root = v4->m_weight_root;
  for ( i = this->m_mixing_tree.m_tree_actual_time_in_ms;
        m_weight_root;
        m_weight_root = m_weight_root->m_next_weight_animation )
  {
    vostok::animation::invert_animation_times(m_weight_root, i);
  }
}
