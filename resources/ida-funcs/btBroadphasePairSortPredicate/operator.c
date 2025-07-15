BOOL __thiscall btBroadphasePairSortPredicate::operator()(
        btBroadphasePairSortPredicate *this,
        const btBroadphasePair *a,
        const btBroadphasePair *b)
{
  btBroadphaseProxy *m_pProxy0; // esi
  btBroadphaseProxy *v4; // edi
  int v5; // ebx
  btBroadphaseProxy *m_pProxy1; // edx
  btBroadphaseProxy *v7; // eax
  int v8; // ecx
  int v10; // [esp+8h] [ebp-8h]
  int m_uniqueId; // [esp+Ch] [ebp-4h]

  m_pProxy0 = a->m_pProxy0;
  if ( a->m_pProxy0 )
    m_uniqueId = m_pProxy0->m_uniqueId;
  else
    m_uniqueId = -1;
  v4 = b->m_pProxy0;
  if ( b->m_pProxy0 )
    v5 = v4->m_uniqueId;
  else
    v5 = -1;
  m_pProxy1 = a->m_pProxy1;
  if ( m_pProxy1 )
    v10 = m_pProxy1->m_uniqueId;
  else
    v10 = -1;
  v7 = b->m_pProxy1;
  if ( v7 )
    v8 = v7->m_uniqueId;
  else
    v8 = -1;
  return m_uniqueId > v5
      || m_pProxy0 == v4 && (v10 > v8 || m_pProxy0 == v4 && m_pProxy1 == v7 && a->m_algorithm > b->m_algorithm);
}
