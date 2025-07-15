bool __userpurge vostok::animation::mixing::n_ary_tree_event_iterator::is_less@<al>(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<edi>,
        const vostok::animation::mixing::n_ary_tree_event_iterator *other@<esi>,
        const boost::function<unsigned char __cdecl(void const *)> *animated_object_resolver)
{
  unsigned int event_time_in_ms; // eax
  unsigned int v4; // ecx
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp-8h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation_node; // [esp-4h] [ebp-10h]
  vostok::animation::mixing::animation_comparer_predicate v13; // [esp+0h] [ebp-Ch] BYREF

  event_time_in_ms = this->m_value.event_time_in_ms;
  v4 = other->m_value.event_time_in_ms;
  if ( event_time_in_ms < v4 )
    return 1;
  if ( event_time_in_ms > v4 )
    return 0;
  m_animation_node = other->m_animation_node;
  v11 = this->m_animation_node;
  v13.m_animated_object_resolver = animated_object_resolver;
  v13.m_use_synchronized_animations = 0;
  v13.m_use_overriding_animations = 1;
  v6 = vostok::animation::mixing::animation_comparer_predicate::operator()(&v13, v11, m_animation_node) - 1;
  if ( !v6 )
    return 1;
  if ( v6 == 1 )
    return 0;
  v7 = this->m_value.event_time_in_ms;
  v8 = other->m_value.event_time_in_ms;
  if ( v7 < v8 || v7 <= v8 && this->m_value.event_type < other->m_value.event_type )
    return 1;
  v9 = other->m_value.event_time_in_ms;
  v10 = this->m_value.event_time_in_ms;
  if ( v9 < v10 || v9 <= v10 && other->m_value.event_type < this->m_value.event_type )
    return 0;
  return this->m_animation_node < other->m_animation_node;
}
