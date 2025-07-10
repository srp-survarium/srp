BOOL __thiscall btBroadphasePairSortPredicate::operator()(
        btBroadphasePairSortPredicate *this,
        const btBroadphasePair *a,
        const btBroadphasePair *b)
{
  btBroadphaseProxy *m_pProxy0; // edx
  btBroadphaseProxy *v4; // esi
  int m_uniqueId; // ebp
  btBroadphaseProxy *m_pProxy1; // edi
  int v7; // ebx
  btBroadphaseProxy *v8; // eax
  int v9; // ecx
  int uidA0; // [esp+10h] [ebp-4h]

  m_pProxy0 = a->m_pProxy0;
  if ( a->m_pProxy0 )
    uidA0 = m_pProxy0->m_uniqueId;
  else
    uidA0 = -1;
  v4 = b->m_pProxy0;
  if ( b->m_pProxy0 )
    m_uniqueId = v4->m_uniqueId;
  else
    m_uniqueId = -1;
  m_pProxy1 = a->m_pProxy1;
  if ( m_pProxy1 )
    v7 = m_pProxy1->m_uniqueId;
  else
    v7 = -1;
  v8 = b->m_pProxy1;
  if ( v8 )
    v9 = v8->m_uniqueId;
  else
    v9 = -1;
  return uidA0 > m_uniqueId
      || m_pProxy0 == v4 && (v7 > v9 || m_pProxy0 == v4 && m_pProxy1 == v8 && a->m_algorithm > b->m_algorithm);
}
