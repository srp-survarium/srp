void __usercall btRigidBody::applyTorqueImpulse(btRigidBody *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4

  v2 = *((float *)&this->__vftable + 2);
  v3 = *((float *)&this->__vftable + 1);
  v4 = (float)((float)(a2[69] * v3) + (float)(a2[70] * v2)) + (float)(a2[68] * *(float *)&this->__vftable);
  v5 = (float)((float)(a2[73] * v3) + (float)(a2[74] * v2)) + (float)(a2[72] * *(float *)&this->__vftable);
  v6 = a2[77] * v3;
  v7 = a2[78] * v2;
  v8 = a2[152] * v4;
  v9 = a2[153] * v5;
  v10 = a2[154] * (float)((float)(v6 + v7) + (float)(a2[76] * *(float *)&this->__vftable));
  a2[84] = a2[84] + v8;
  v11 = a2[85] + v9;
  v12 = a2[86] + v10;
  a2[85] = v11;
  a2[86] = v12;
}
