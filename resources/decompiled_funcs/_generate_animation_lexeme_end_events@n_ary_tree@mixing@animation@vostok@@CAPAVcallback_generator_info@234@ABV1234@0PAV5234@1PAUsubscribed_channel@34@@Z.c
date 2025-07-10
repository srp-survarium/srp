vostok::animation::mixing::callback_generator_info *__cdecl vostok::animation::mixing::n_ary_tree::generate_animation_lexeme_end_events(
        const vostok::animation::mixing::n_ary_tree *new_tree,
        vostok::animation::mixing::callback_generator_info *callback_generators_buffer_begin,
        vostok::animation::subscribed_channel *callback_generators_buffer_end)
{
  const vostok::animation::mixing::n_ary_tree *previous_tree; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // edi
  vostok::animation::mixing::callback_generator_info *result; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi
  vostok::animation::mixing::callback_generator_info *v7; // ebx
  const vostok::animation::mixing::callback_generator_info *next; // esi
  const void *user_data; // eax
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // ecx
  vostok::animation::mixing::callback_generator_info *v11; // esi
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  unsigned int animation_interval_id; // ebx
  float animation_time; // xmm0_4
  const void *m_animated_object; // ebp
  vostok::animation::mixing::animation_interval *v16; // eax
  vostok::resources::managed_resource *m_object; // eax
  unsigned int v18; // edx
  float v19; // xmm0_4
  vostok::animation::mixing::animation_comparer_predicate v20; // [esp+14h] [ebp-14h] BYREF
  vostok::animation::mixing::callback_generator_info *previous_generator_info; // [esp+18h] [ebp-10h]
  vostok::animation::mixing::callback_generator_info *callback_generators_head; // [esp+1Ch] [ebp-Ch]
  unsigned int v23; // [esp+20h] [ebp-8h]
  float v24; // [esp+24h] [ebp-4h]

  m_weight_root = previous_tree->m_weight_root;
  result = 0;
  callback_generators_head = 0;
  previous_generator_info = 0;
  if ( m_weight_root )
  {
    do
    {
      v6 = new_tree->m_weight_root;
      v20.m_use_synchronized_animations = 0;
      v20.m_use_overriding_animations = 0;
      if ( v6 )
      {
        while ( vostok::animation::mixing::animation_comparer_predicate::operator()(&v20, v6, m_weight_root) )
        {
          v6 = v6->m_next_weight_animation;
          if ( !v6 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        v7 = (vostok::animation::mixing::callback_generator_info *)callback_generators_buffer_end;
        if ( callback_generators_buffer_end )
        {
          while ( 1 )
          {
            if ( LOBYTE(v7->animation.m_object->__vftable) == 3 )
            {
              next = v7->next;
              if ( next )
                break;
            }
LABEL_17:
            v7 = (vostok::animation::mixing::callback_generator_info *)v7->animated_object;
            if ( !v7 )
              goto LABEL_27;
          }
          while ( 1 )
          {
            if ( BYTE1(next[2].animation.m_object)
              && (!next[1].next
               || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
               || next[1].next == (const vostok::animation::mixing::callback_generator_info *)vostok::animation::mixing::animation_interval::animation(&m_weight_root->m_animation_intervals[m_weight_root->m_animation_state->animation_interval_id])->m_animation.m_object) )
            {
              user_data = (const void *)next[1].user_data;
              if ( !user_data || user_data == m_weight_root->m_animated_object )
                break;
            }
            next = (const vostok::animation::mixing::callback_generator_info *)LODWORD(next[1].animation_time);
            if ( !next )
              goto LABEL_17;
          }
          m_animation_intervals = m_weight_root->m_animation_intervals;
          v11 = callback_generators_buffer_begin++;
          m_animation_state = m_weight_root->m_animation_state;
          animation_interval_id = m_animation_state->animation_interval_id;
          if ( v11 )
          {
            animation_time = m_animation_state->animation_time;
            m_animated_object = m_weight_root->m_animated_object;
            v23 = m_weight_root->user_data;
            v24 = animation_time;
            v16 = vostok::animation::mixing::animation_interval::animation(&m_animation_intervals[animation_interval_id]);
            v11->animation.m_object = 0;
            m_object = v16->m_animation.m_object;
            if ( m_object )
            {
              v11->animation.m_object = m_object;
              _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
            }
            v18 = v23;
            v19 = v24;
            v11->animated_object = m_animated_object;
            v11->next = 0;
            v11->user_data = v18;
            v11->animation_time = v19;
            v11->event_type = 2;
            v11->channel_ids = 0;
            v11->animation_interval_id = animation_interval_id;
          }
          if ( previous_generator_info )
            previous_generator_info->next = v11;
          else
            callback_generators_head = v11;
          previous_generator_info = v11;
        }
      }
LABEL_27:
      m_weight_root = m_weight_root->m_next_weight_animation;
    }
    while ( m_weight_root );
    return callback_generators_head;
  }
  return result;
}
