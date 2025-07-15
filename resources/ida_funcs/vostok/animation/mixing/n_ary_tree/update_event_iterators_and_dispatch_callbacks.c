bool __thiscall vostok::animation::mixing::n_ary_tree::update_event_iterators_and_dispatch_callbacks(
        vostok::animation::mixing::n_ary_tree *this,
        vostok::animation::mixing::n_ary_tree *target_time_in_ms,
        vostok::animation::mixing::animation_state **channels_head,
        vostok::animation::subscribed_channel **callbacks_are_actual,
        bool *callbacks_are_actuala)
{
  vostok::animation::mixing::n_ary_tree *v5; // esi
  vostok::animation::mixing::animation_state *m_animation_states; // edi
  const vostok::animation::mixing::callback_generator_info *v7; // ebx
  const vostok::animation::mixing::animation_state *v8; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation_node; // esi
  void *v10; // esp
  unsigned int previous_animation_interval_id; // eax
  double v12; // st7
  vostok::animation::mixing::animation_interval *v13; // eax
  vostok::animation::mixing::n_ary_tree *v14; // ecx
  bool result; // al
  vostok::animation::mixing::callback_generator_info *v16; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v17; // ecx
  float animation_time; // [esp+0h] [ebp-4Ch]
  unsigned __int16 v19; // [esp+4h] [ebp-48h]
  unsigned __int8 channel_ids; // [esp+8h] [ebp-44h]
  unsigned int user_data; // [esp+Ch] [ebp-40h]
  unsigned __int8 v22; // [esp+10h] [ebp-3Ch]
  vostok::animation::mixing::callback_generator_info v23; // [esp+14h] [ebp-38h] BYREF
  const vostok::animation::mixing::animation_state *e; // [esp+38h] [ebp-14h]
  void *animated_object; // [esp+3Ch] [ebp-10h]
  int event_type; // [esp+40h] [ebp-Ch]
  const vostok::animation::mixing::callback_generator_info *callback_generators_head; // [esp+44h] [ebp-8h]
  vostok::animation::mixing::callback_generator_info *previous_generator_info; // [esp+48h] [ebp-4h]
  bool result_3; // [esp+5Bh] [ebp+Fh]

  v5 = target_time_in_ms;
  m_animation_states = target_time_in_ms->m_animation_states;
  v7 = 0;
  v8 = &m_animation_states[target_time_in_ms->m_animations_count];
  callback_generators_head = 0;
  previous_generator_info = 0;
  e = v8;
  if ( m_animation_states != v8 )
  {
    do
    {
      this = (vostok::animation::mixing::n_ary_tree *)m_animation_states->event_iterator.m_value.event_time_in_ms;
      if ( this == (vostok::animation::mixing::n_ary_tree *)channels_head )
      {
        this = (vostok::animation::mixing::n_ary_tree *)m_animation_states->event_iterator.m_value.event_type;
        if ( ((unsigned __int8)this & 0x3E) != 0 )
        {
          m_animation_node = m_animation_states->event_iterator.m_animation_node;
          if ( (!m_animation_node->m_is_transitting_to_zero || ((unsigned __int8)this & 2) != 0)
            && m_animation_node->m_can_generate_events )
          {
            event_type = (unsigned __int16)this;
            v10 = alloca(24);
            if ( (m_animation_states->event_iterator.m_value.event_type & 4) != 0 )
              previous_animation_interval_id = m_animation_states->previous_animation_interval_id;
            else
              previous_animation_interval_id = m_animation_states->animation_interval_id;
            this = (vostok::animation::mixing::n_ary_tree *)m_animation_node->m_animation_intervals;
            if ( &v23 )
            {
              v12 = m_animation_states->animation_time;
              v22 = previous_animation_interval_id;
              animated_object = (void *)m_animation_node->m_animated_object;
              user_data = m_animation_node->user_data;
              channel_ids = m_animation_states->event_iterator.m_value.channel_ids;
              v19 = event_type;
              animation_time = v12;
              v13 = vostok::animation::mixing::animation_interval::animation((vostok::animation::mixing::animation_interval *)this + previous_animation_interval_id);
              vostok::animation::mixing::callback_generator_info::callback_generator_info(
                &v23,
                &v13->m_animation,
                animated_object,
                animation_time,
                v19,
                channel_ids,
                user_data,
                v22);
            }
            if ( previous_generator_info )
              previous_generator_info->next = &v23;
            else
              callback_generators_head = &v23;
            v8 = e;
            previous_generator_info = &v23;
            v7 = callback_generators_head;
          }
        }
      }
      ++m_animation_states;
    }
    while ( m_animation_states != v8 );
    v5 = target_time_in_ms;
  }
  vostok::animation::mixing::n_ary_tree::remove_animations(this, v5, channels_head);
  vostok::animation::mixing::n_ary_tree::update_event_iterators(
    v14,
    (int)v5,
    (vostok::animation::mixing::n_ary_tree_event_iterator *)channels_head);
  result = vostok::animation::mixing::n_ary_tree::dispatch_callbacks(
             v7,
             (const vostok::animation::subscribed_channel **)callbacks_are_actual,
             (unsigned int)channels_head,
             callbacks_are_actuala);
  result_3 = result;
  v16 = (vostok::animation::mixing::callback_generator_info *)v7;
  if ( v7 )
  {
    do
    {
      v17 = &v16->animation.vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>;
      v16 = (vostok::animation::mixing::callback_generator_info *)v16->next;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v17);
    }
    while ( v16 );
    return result_3;
  }
  return result;
}
