void __thiscall Scaleform::Render::Matrix2x4<float>::SetInverse(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  double v3; // st7
  float invDet; // [esp+4h] [ebp+4h]
  float invDeta; // [esp+4h] [ebp+4h]

  invDet = m->M[0][0] * m->M[1][1] - m->M[1][0] * m->M[0][1];
  if ( invDet == 0.0 )
  {
    this->M[0][0] = 1.0;
    this->M[1][1] = 1.0;
    this->M[0][1] = 0.0;
    this->M[0][2] = 0.0;
    this->M[0][3] = 0.0;
    this->M[1][0] = 0.0;
    this->M[1][2] = 0.0;
    this->M[1][3] = 0.0;
    this->M[0][3] = -m->M[0][3];
    v3 = -m->M[1][3];
  }
  else
  {
    invDeta = 1.0 / invDet;
    this->M[0][0] = invDeta * m->M[1][1];
    this->M[1][1] = m->M[0][0] * invDeta;
    this->M[0][1] = -m->M[0][1] * invDeta;
    this->M[1][0] = invDeta * -m->M[1][0];
    this->M[0][3] = -(m->M[1][3] * this->M[0][1] + m->M[0][3] * this->M[0][0]);
    v3 = -(m->M[1][3] * this->M[1][1] + m->M[0][3] * this->M[1][0]);
  }
  this->M[1][3] = v3;
}
