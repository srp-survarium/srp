void __usercall btGImpactCollisionAlgorithm::registerAlgorithm(btCollisionDispatcher *dispatcher@<esi>)
{
  btCollisionAlgorithmCreateFunc **v1; // eax
  int v2; // ecx

  if ( (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    s_gimpact_cf.m_swapped = 0;
    s_gimpact_cf.__vftable = (btGImpactCollisionAlgorithm::CreateFunc_vtbl *)&btGImpactCollisionAlgorithm::CreateFunc::`vftable';
    atexit(btGImpactCollisionAlgorithm::registerAlgorithm_::_2_::_dynamic_atexit_destructor_for__s_gimpact_cf__);
  }
  dispatcher->m_doubleDispatch[25][0] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][1] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][2] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][3] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][4] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][5] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][6] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][7] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][8] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][9] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][10] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][11] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][12] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][13] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][14] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][15] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][16] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][17] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][18] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][19] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][20] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][21] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][22] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][23] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][24] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][25] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][26] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][27] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][28] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][29] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][30] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][31] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][32] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][33] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][34] = &s_gimpact_cf;
  dispatcher->m_doubleDispatch[25][35] = &s_gimpact_cf;
  v1 = &dispatcher->m_doubleDispatch[0][25];
  v2 = 36;
  do
  {
    *v1 = &s_gimpact_cf;
    v1 += 36;
    --v2;
  }
  while ( v2 );
}
