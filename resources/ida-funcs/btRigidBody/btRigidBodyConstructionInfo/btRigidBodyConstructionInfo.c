_DWORD *__userpurge btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo@<eax>(
        btRigidBody::btRigidBodyConstructionInfo *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>,
        _DWORD *thisa,
        struct btMotionState *a5,
        struct btCollisionShape *a6,
        const struct btVector3 *a7)
{
  thisa[1] = 0;
  *thisa = a3;
  thisa[20] = a2;
  thisa[24] = LODWORD(this->m_mass);
  thisa[25] = this->m_motionState;
  thisa[26] = (&this->m_motionState)[1];
  thisa[27] = (&this->m_motionState)[2];
  thisa[28] = 0;
  thisa[29] = 0;
  thisa[31] = 0;
  thisa[32] = LODWORD(FLOAT_0_80000001);
  thisa[33] = LODWORD(s_bm_current_air_resistance);
  thisa[35] = LODWORD(FLOAT_0_0049999999);
  thisa[30] = LODWORD(c_anim_center);
  *((_BYTE *)thisa + 136) = 0;
  thisa[36] = LODWORD(FLOAT_0_0099999998);
  thisa[37] = LODWORD(FLOAT_0_0099999998);
  thisa[38] = LODWORD(FLOAT_0_0099999998);
  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)(thisa + 4));
  thisa[16] = 0;
  thisa[17] = 0;
  thisa[18] = 0;
  thisa[19] = 0;
  return thisa;
}
