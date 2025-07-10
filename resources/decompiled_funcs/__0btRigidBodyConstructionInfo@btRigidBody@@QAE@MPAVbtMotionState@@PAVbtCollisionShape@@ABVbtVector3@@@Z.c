int __usercall btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo@<eax>(
        btRigidBody::btRigidBodyConstructionInfo *this@<ecx>,
        int result@<eax>,
        int a3@<esi>,
        int a4@<xmm0>)
{
  __int64 v4; // xmm0_8
  const vostok::math::float4x4 *v5; // xmm1_4

  *(_DWORD *)result = a4;
  *(_DWORD *)(result + 80) = a3;
  *(_DWORD *)(result + 4) = 0;
  *(_QWORD *)(result + 96) = *(_QWORD *)&this->m_mass;
  v4 = *(_QWORD *)&(&this->m_motionState)[1];
  *(float *)(result + 120) = FLOAT_0_5;
  *(_QWORD *)(result + 104) = v4;
  *(_DWORD *)(result + 128) = 1061997773;
  v5 = clear_value;
  *(_DWORD *)(result + 140) = 1000593162;
  *(_DWORD *)(result + 112) = 0;
  *(_DWORD *)(result + 116) = 0;
  *(_DWORD *)(result + 124) = 0;
  *(_DWORD *)(result + 132) = v5;
  *(_BYTE *)(result + 136) = 0;
  *(_DWORD *)(result + 144) = 1008981770;
  *(_DWORD *)(result + 148) = 1008981770;
  *(_DWORD *)(result + 152) = 1008981770;
  *(_DWORD *)(result + 16) = v5;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = v5;
  *(_DWORD *)(result + 40) = 0;
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 48) = 0;
  *(_DWORD *)(result + 52) = 0;
  *(_DWORD *)(result + 56) = v5;
  *(_DWORD *)(result + 60) = 0;
  *(_DWORD *)(result + 64) = 0;
  *(_DWORD *)(result + 68) = 0;
  *(_DWORD *)(result + 72) = 0;
  *(_DWORD *)(result + 76) = 0;
  return result;
}
