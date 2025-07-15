void __thiscall btAlignedObjectArray<btBroadphasePair>::swap(
        btAlignedObjectArray<btBroadphasePair> *this,
        int index0,
        int index1)
{
  btBroadphasePair *m_data; // edx
  btBroadphasePair *v4; // eax
  btBroadphasePair *v5; // esi
  btBroadphasePair *v6; // edi
  btBroadphaseProxy *m_pProxy0; // [esp+10h] [ebp-10h]
  btBroadphaseProxy *m_pProxy1; // [esp+14h] [ebp-Ch]
  btBroadphaseProxy *m_algorithm; // [esp+18h] [ebp-8h]
  btBroadphaseProxy *m_internalInfo1; // [esp+1Ch] [ebp-4h]

  m_data = this->m_data;
  v4 = &m_data[index0];
  m_pProxy0 = v4->m_pProxy0;
  m_pProxy1 = v4->m_pProxy1;
  m_algorithm = (btBroadphaseProxy *)v4->m_algorithm;
  m_internalInfo1 = (btBroadphaseProxy *)v4->m_internalInfo1;
  v5 = &m_data[index1];
  v4->m_pProxy0 = v5->m_pProxy0;
  v5 = (btBroadphasePair *)((char *)v5 + 4);
  v4->m_pProxy1 = v5->m_pProxy0;
  v5 = (btBroadphasePair *)((char *)v5 + 4);
  v4->m_algorithm = (btCollisionAlgorithm *)v5->m_pProxy0;
  v4->m_internalTmpValue = (int)v5->m_pProxy1;
  v6 = &this->m_data[index1];
  v6->m_pProxy0 = m_pProxy0;
  v6 = (btBroadphasePair *)((char *)v6 + 4);
  v6->m_pProxy0 = m_pProxy1;
  v6 = (btBroadphasePair *)((char *)v6 + 4);
  v6->m_pProxy0 = m_algorithm;
  v6->m_pProxy1 = m_internalInfo1;
}


void __userpurge btAlignedObjectArray<GrahamVector2>::swap(
        int index0@<eax>,
        btAlignedObjectArray<GrahamVector2> *this,
        int index1)
{
  GrahamVector2 *m_data; // edx
  _BYTE v4[32]; // [esp+10h] [ebp-20h] BYREF

  m_data = this->m_data;
  qmemcpy(v4, &m_data[index0], sizeof(v4));
  qmemcpy(&m_data[index0], &m_data[index1], sizeof(GrahamVector2));
  qmemcpy(&this->m_data[index1], v4, sizeof(this->m_data[index1]));
}
