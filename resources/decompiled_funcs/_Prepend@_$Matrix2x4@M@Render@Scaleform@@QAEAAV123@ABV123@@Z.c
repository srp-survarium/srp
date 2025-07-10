Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::Prepend(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Matrix2x4<float> *result; // eax
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm5_4

  result = this;
  v3 = this->M[0][0];
  v4 = this->M[0][1];
  v5 = this->M[1][0];
  v6 = this->M[1][1];
  v7 = this->M[0][3];
  v8 = this->M[1][3];
  this->M[0][0] = (float)(m->M[1][0] * v4) + (float)(m->M[0][0] * this->M[0][0]);
  this->M[1][0] = (float)(m->M[1][0] * v6) + (float)(m->M[0][0] * v5);
  this->M[0][1] = (float)(v4 * m->M[1][1]) + (float)(v3 * m->M[0][1]);
  this->M[1][1] = (float)(v6 * m->M[1][1]) + (float)(v5 * m->M[0][1]);
  this->M[1][2] = 0.0;
  this->M[0][2] = 0.0;
  this->M[0][3] = (float)((float)(v4 * m->M[1][3]) + (float)(v3 * m->M[0][3])) + v7;
  this->M[1][3] = (float)((float)(v6 * m->M[1][3]) + (float)(v5 * m->M[0][3])) + v8;
  return result;
}
