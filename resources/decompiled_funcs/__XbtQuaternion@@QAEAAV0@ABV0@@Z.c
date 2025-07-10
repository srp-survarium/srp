btQuaternion *__usercall btQuaternion::operator*=@<eax>(btQuaternion *this@<ecx>, btQuaternion *result@<eax>)
{
  float v2; // xmm5_4
  float v3; // xmm0_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4

  v2 = this->m_floats[1];
  v3 = this->m_floats[2];
  v4 = (float)((float)((float)(result->m_floats[3] * this->m_floats[3])
                     - (float)(result->m_floats[0] * this->m_floats[0]))
             - (float)(result->m_floats[1] * v2))
     - (float)(result->m_floats[2] * v3);
  v5 = (float)((float)((float)(v2 * result->m_floats[0]) + (float)(v3 * result->m_floats[3]))
             + (float)(result->m_floats[2] * this->m_floats[3]))
     - (float)(result->m_floats[1] * this->m_floats[0]);
  v6 = (float)((float)((float)(result->m_floats[2] * this->m_floats[0])
                     + (float)(this->m_floats[1] * result->m_floats[3]))
             + (float)(result->m_floats[1] * this->m_floats[3]))
     - (float)(v3 * result->m_floats[0]);
  result->m_floats[0] = (float)((float)((float)(v3 * result->m_floats[1])
                                      + (float)(this->m_floats[0] * result->m_floats[3]))
                              + (float)(result->m_floats[0] * this->m_floats[3]))
                      - (float)(result->m_floats[2] * this->m_floats[1]);
  result->m_floats[1] = v6;
  result->m_floats[2] = v5;
  result->m_floats[3] = v4;
  return result;
}
