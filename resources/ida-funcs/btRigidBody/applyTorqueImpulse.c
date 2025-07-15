void __usercall btRigidBody::applyTorqueImpulse(btRigidBody *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4

  v2 = *((float *)&this->__vftable + 2);
  v3 = *((float *)&this->__vftable + 1);
  v4 = (float)((float)(a2[73] * v3) + (float)(a2[74] * v2)) + (float)(a2[72] * *(float *)&this->__vftable);
  v5 = (float)((float)(a2[77] * v3) + (float)(a2[78] * v2)) + (float)(a2[76] * *(float *)&this->__vftable);
  v6 = a2[144]
     * (float)((float)((float)(a2[69] * v3) + (float)(a2[70] * v2)) + (float)(a2[68] * *(float *)&this->__vftable));
  v7 = a2[145] * v4;
  v8 = a2[146];
  v9 = a2 + 84;
  v10 = v8 * v5;
  *v9 = *v9 + v6;
  v11 = v9[1] + v7;
  v12 = v9[2] + v10;
  v9[1] = v11;
  v9[2] = v12;
}
