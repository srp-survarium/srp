Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::Invert(
        Scaleform::Render::Matrix2x4<float> *this)
{
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  m.M[0][0] = this->M[0][0];
  m.M[0][1] = this->M[0][1];
  m.M[0][2] = this->M[0][2];
  m.M[0][3] = this->M[0][3];
  m.M[1][0] = this->M[1][0];
  m.M[1][1] = this->M[1][1];
  m.M[1][2] = this->M[1][2];
  m.M[1][3] = this->M[1][3];
  Scaleform::Render::Matrix2x4<float>::SetInverse(this, &m);
  return this;
}


Scaleform::Render::Matrix2x4<double> *__thiscall Scaleform::Render::Matrix2x4<double>::Invert(
        Scaleform::Render::Matrix2x4<double> *this)
{
  Scaleform::Render::Matrix2x4<double> m; // [esp+8h] [ebp-40h] BYREF

  m.M[0][0] = this->M[0][0];
  m.M[0][1] = this->M[0][1];
  m.M[0][2] = this->M[0][2];
  m.M[0][3] = this->M[0][3];
  m.M[1][0] = this->M[1][0];
  m.M[1][1] = this->M[1][1];
  m.M[1][2] = this->M[1][2];
  m.M[1][3] = this->M[1][3];
  Scaleform::Render::Matrix2x4<double>::SetInverse(this, &m);
  return this;
}
