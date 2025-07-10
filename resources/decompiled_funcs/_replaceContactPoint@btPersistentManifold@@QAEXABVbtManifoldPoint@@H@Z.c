void __userpurge btPersistentManifold::replaceContactPoint(
        btPersistentManifold *this@<ecx>,
        int insertIndex@<eax>,
        const btManifoldPoint *newPoint)
{
  int v3; // eax
  float m_accumImpulse; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  void *m_userPersistentData; // ebx
  int m_lifeTime; // edx
  float *v9; // eax

  v3 = insertIndex;
  m_accumImpulse = this->m_pointCache[v3].mConstraintRow[0].m_accumImpulse;
  v5 = this->m_pointCache[v3].mConstraintRow[1].m_accumImpulse;
  v6 = this->m_pointCache[v3].mConstraintRow[2].m_accumImpulse;
  m_userPersistentData = this->m_pointCache[v3].m_userPersistentData;
  m_lifeTime = this->m_pointCache[v3].m_lifeTime;
  v9 = (float *)((char *)&this->m_objectType + v3 * 288);
  qmemcpy(v9 + 4, newPoint, 0x120u);
  *((_DWORD *)v9 + 31) = m_userPersistentData;
  v9[32] = m_accumImpulse;
  v9[34] = v5;
  v9[35] = v6;
  v9[59] = m_accumImpulse;
  v9[67] = v5;
  v9[75] = v6;
  *((_DWORD *)v9 + 40) = m_lifeTime;
}
