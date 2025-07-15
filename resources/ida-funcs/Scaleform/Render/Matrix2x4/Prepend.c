Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::Prepend(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  float v3; // xmm1_4
  Scaleform::Render::Matrix2x4<float> v5; // [esp+10h] [ebp-20h] BYREF

  Scaleform::Render::Matrix2x4<float>::SetMatrix(&v5, this);
  v3 = v5.M[1][1];
  this->M[0][0] = (float)(m->M[0][0] * v5.M[0][0]) + (float)(v5.M[0][1] * m->M[1][0]);
  this->M[1][0] = (float)(m->M[0][0] * v5.M[1][0]) + (float)(v3 * m->M[1][0]);
  this->M[0][1] = (float)(m->M[1][1] * v5.M[0][1]) + (float)(m->M[0][1] * v5.M[0][0]);
  this->M[1][1] = (float)(m->M[1][1] * v5.M[1][1]) + (float)(m->M[0][1] * v5.M[1][0]);
  this->M[1][2] = 0.0;
  this->M[0][2] = 0.0;
  this->M[0][3] = (float)((float)(m->M[1][3] * v5.M[0][1]) + (float)(m->M[0][3] * v5.M[0][0])) + v5.M[0][3];
  this->M[1][3] = (float)((float)(m->M[1][3] * v5.M[1][1]) + (float)(m->M[0][3] * v5.M[1][0])) + v5.M[1][3];
  return this;
}
