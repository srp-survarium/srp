bool __usercall vostok::animation::mixing::operator<@<al>(
        const vostok::animation::mixing::animation_interval *left@<edi>,
        const vostok::animation::mixing::animation_interval *right@<esi>)
{
  vostok::animation::mixing::animation_interval *v2; // ebx
  vostok::animation::mixing::animation_interval *v3; // ebx
  BOOL v4; // eax
  float started; // [esp+4h] [ebp-4h]
  float v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+4h] [ebp-4h]

  v2 = vostok::animation::mixing::animation_interval::animation(right);
  if ( vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object < v2->m_animation.m_object )
    return 1;
  v3 = vostok::animation::mixing::animation_interval::animation(right);
  v4 = v3->m_animation.m_object < vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object;
  if ( v4 > 0 )
    return 0;
  started = vostok::animation::mixing::animation_interval::start_time(left);
  if ( vostok::animation::mixing::animation_interval::start_time(right) > started )
    return 1;
  v7 = vostok::animation::mixing::animation_interval::start_time(left);
  if ( v7 > vostok::animation::mixing::animation_interval::start_time(right) )
    return 0;
  v8 = vostok::animation::mixing::animation_interval::length(left);
  return vostok::animation::mixing::animation_interval::length(right) > v8;
}
