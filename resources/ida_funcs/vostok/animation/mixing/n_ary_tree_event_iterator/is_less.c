// local variable allocation has failed, the output may be wrong!
bool __usercall vostok::animation::mixing::n_ary_tree_event_iterator::is_less@<al>(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<edi>,
        const vostok::animation::mixing::n_ary_tree_event_iterator *other@<esi>,
        int a3@<ecx>)
{
  unsigned int event_time_in_ms; // eax
  unsigned int v4; // ecx
  __int32 v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // [esp-8h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation_node; // [esp-4h] [ebp-8h]
  int predicate; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  predicate = a3;
  event_time_in_ms = this->m_value.event_time_in_ms;
  v4 = other->m_value.event_time_in_ms;
  if ( event_time_in_ms < v4 )
    return 1;
  if ( event_time_in_ms > v4 )
    return 0;
  m_animation_node = other->m_animation_node;
  v9 = this->m_animation_node;
  LOWORD(predicate) = 256;
  v6 = vostok::animation::mixing::animation_comparer_predicate::operator()(
         (vostok::animation::mixing::animation_comparer_predicate *)&predicate,
         v9,
         m_animation_node)
     - 1;
  if ( !v6 )
    return 1;
  if ( v6 == 1 )
    return 0;
  v7 = this->m_value.event_time_in_ms;
  v8 = other->m_value.event_time_in_ms;
  if ( v7 < v8 )
    return 1;
  if ( v7 > v8 )
    return 0;
  return this->m_value.event_type < other->m_value.event_type;
}
