bool __usercall vostok::animation::mixing::operator>@<al>(
        const vostok::animation::mixing::animation_interval *left@<edi>,
        const vostok::animation::mixing::animation_interval *right@<esi>)
{
  vostok::animation::mixing::animation_interval *v2; // ebx
  vostok::animation::mixing::animation_interval *v3; // ebx
  float started; // [esp+4h] [ebp-4h]
  float v6; // [esp+4h] [ebp-4h]
  float v7; // [esp+4h] [ebp-4h]

  v2 = vostok::animation::mixing::animation_interval::animation(right);
  if ( vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object < v2->m_animation.m_object )
    return 0;
  v3 = vostok::animation::mixing::animation_interval::animation(right);
  if ( v3->m_animation.m_object < vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object )
    return 1;
  started = vostok::animation::mixing::animation_interval::start_time(left);
  if ( started > vostok::animation::mixing::animation_interval::start_time(right) )
    return 1;
  v6 = vostok::animation::mixing::animation_interval::start_time(left);
  if ( vostok::animation::mixing::animation_interval::start_time(right) > v6 )
    return 0;
  v7 = vostok::animation::mixing::animation_interval::length(left);
  return v7 > vostok::animation::mixing::animation_interval::length(right);
}
