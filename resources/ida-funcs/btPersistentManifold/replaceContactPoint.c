void __userpurge btPersistentManifold::replaceContactPoint(
        btPersistentManifold *this@<ecx>,
        int insertIndex@<eax>,
        const btManifoldPoint *newPoint)
{
  int *v3; // eax
  int v4; // xmm0_4
  int v5; // xmm1_4
  int v6; // xmm2_4
  int v7; // ebx
  int v8; // edx

  v3 = &this->m_objectType + 72 * insertIndex;
  v4 = v3[59];
  v5 = v3[67];
  v6 = v3[75];
  v7 = v3[31];
  v8 = v3[40];
  qmemcpy(v3 + 4, newPoint, 0x120u);
  v3[31] = v7;
  v3[32] = v4;
  v3[34] = v5;
  v3[35] = v6;
  v3[59] = v4;
  v3[67] = v5;
  v3[75] = v6;
  v3[40] = v8;
}
