void __thiscall Scaleform::Render::Matrix2x4<float>::SetLerp(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2,
        float t)
{
  this->M[0][0] = m1->M[0][0] + (m2->M[0][0] - m1->M[0][0]) * t;
  this->M[1][0] = (m2->M[1][0] - m1->M[1][0]) * t + m1->M[1][0];
  this->M[0][1] = (m2->M[0][1] - m1->M[0][1]) * t + m1->M[0][1];
  this->M[1][1] = (m2->M[1][1] - m1->M[1][1]) * t + m1->M[1][1];
  this->M[0][2] = (m2->M[0][2] - m1->M[0][2]) * t + m1->M[0][2];
  this->M[1][2] = (m2->M[1][2] - m1->M[1][2]) * t + m1->M[1][2];
  this->M[0][3] = (m2->M[0][3] - m1->M[0][3]) * t + m1->M[0][3];
  this->M[1][3] = t * (m2->M[1][3] - m1->M[1][3]) + m1->M[1][3];
}
