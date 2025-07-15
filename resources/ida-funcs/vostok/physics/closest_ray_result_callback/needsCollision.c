char __thiscall vostok::physics::closest_ray_result_callback::needsCollision(
        vostok::physics::closest_ray_result_callback *this,
        btBroadphaseProxy *proxy0)
{
  vostok::physics::bt_animated_rigid_body *m_collisionFilterGroup; // ecx
  char v4; // bl
  int v5; // eax
  bool v6; // cl

  m_collisionFilterGroup = (vostok::physics::bt_animated_rigid_body *)(unsigned __int16)proxy0->m_collisionFilterGroup;
  if ( ((unsigned __int16)m_collisionFilterGroup & this->m_collisionFilterMask) == 0
    || (proxy0->m_collisionFilterMask & this->m_collisionFilterGroup) == 0 )
  {
    goto LABEL_11;
  }
  v4 = 1;
  if ( ((unsigned __int8)m_collisionFilterGroup & 0x40) != 0 )
  {
    v5 = vostok::physics::bt_animated_rigid_body::bounding_sphere_touch(
           m_collisionFilterGroup,
           *((_DWORD *)proxy0->m_clientObject + 62),
           this->m_initiator);
    if ( !this->skip_touch )
    {
      v6 = this->m_need_re_trace || v5 == 1;
      this->m_need_re_trace = v6;
    }
    if ( !v5 )
LABEL_11:
      v4 = 0;
  }
  return this->m_need_re_trace ? 0 : v4;
}
