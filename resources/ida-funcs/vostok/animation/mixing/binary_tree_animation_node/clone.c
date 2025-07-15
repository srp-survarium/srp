const vostok::animation::mixing::animation_interval *__usercall vostok::animation::mixing::binary_tree_animation_node::clone@<eax>(
        vostok::mutable_buffer *buffer@<ecx>,
        const vostok::animation::mixing::animation_interval *animation_intervals_begin@<eax>,
        const vostok::animation::mixing::animation_interval *animation_intervals_end)
{
  char *m_data; // ebp
  const vostok::animation::mixing::animation_interval *v5; // esi
  int v6; // eax
  const vostok::animation::mixing::animation_interval *result; // eax
  const vostok::animation::mixing::animation_interval *v8; // eax
  vostok::animation::mixing::animation_interval *v9; // edi
  vostok::animation::mixing::animation_interval *v10; // eax
  float start_time; // [esp+0h] [ebp-18h]
  float length; // [esp+4h] [ebp-14h]
  const vostok::animation::mixing::animation_interval *animation_intervals_enda; // [esp+1Ch] [ebp+4h]

  m_data = buffer->m_data;
  v5 = animation_intervals_begin;
  v6 = 12 * (animation_intervals_end - animation_intervals_begin);
  buffer->m_size -= v6;
  buffer->m_data = &m_data[v6];
  result = (const vostok::animation::mixing::animation_interval *)m_data;
  if ( v5 != animation_intervals_end )
  {
    v8 = (const vostok::animation::mixing::animation_interval *)(m_data - (char *)v5);
    animation_intervals_enda = (const vostok::animation::mixing::animation_interval *)(m_data - (char *)v5);
    do
    {
      v9 = (const vostok::animation::mixing::animation_interval *)((char *)v5 + (_DWORD)v8);
      if ( (const vostok::animation::mixing::animation_interval *)((char *)v5 + (_DWORD)v8) )
      {
        length = vostok::animation::mixing::animation_interval::length(v5);
        start_time = vostok::animation::mixing::animation_interval::start_time(v5);
        v10 = vostok::animation::mixing::animation_interval::animation(v5);
        vostok::animation::mixing::animation_interval::animation_interval(v9, &v10->m_animation, start_time, length);
        v8 = animation_intervals_enda;
      }
      ++v5;
    }
    while ( v5 != animation_intervals_end );
    return (const vostok::animation::mixing::animation_interval *)m_data;
  }
  return result;
}
