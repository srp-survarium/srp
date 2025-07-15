char __usercall btAxisSweep3Internal<unsigned short>::testAabbOverlap@<al>(
        btBroadphaseProxy *proxy0@<ecx>,
        btBroadphaseProxy *proxy1@<eax>,
        btAxisSweep3Internal<unsigned short> *this)
{
  int v5; // ecx
  btBroadphaseProxy *v6; // edx
  __int16 *p_m_collisionFilterMask; // eax
  int v8; // edi

  v5 = 0;
  v6 = proxy0 + 1;
  p_m_collisionFilterMask = &proxy1[1].m_collisionFilterMask;
  v8 = (char *)proxy0 - (char *)proxy1;
  while ( *(unsigned __int16 *)((char *)p_m_collisionFilterMask + v8) >= (unsigned __int16)*(p_m_collisionFilterMask - 3)
       && (unsigned __int16)*p_m_collisionFilterMask >= LOWORD(v6->m_clientObject) )
  {
    ++v5;
    ++p_m_collisionFilterMask;
    v6 = (btBroadphaseProxy *)((char *)v6 + 2);
    if ( v5 >= 3 )
      return 1;
  }
  return 0;
}
