void __thiscall Scaleform::Render::Matrix2x4<double>::SetInverse(
        Scaleform::Render::Matrix2x4<double> *this,
        const Scaleform::Render::Matrix2x4<double> *m)
{
  long double v2; // st7
  long double v3; // st7
  long double v4; // st7

  v2 = m->M[0][0] * m->M[1][1] - m->M[0][1] * m->M[1][0];
  if ( 0.0 == v2 )
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
    v4 = 1.0 / v2;
    this->M[0][0] = v4 * m->M[1][1];
    this->M[1][1] = m->M[0][0] * v4;
    this->M[0][1] = -(m->M[0][1] * v4);
    this->M[1][0] = -(v4 * m->M[1][0]);
    this->M[0][3] = -(m->M[0][3] * this->M[0][0] + m->M[1][3] * this->M[0][1]);
    v3 = -(m->M[1][3] * this->M[1][1] + m->M[0][3] * this->M[1][0]);
  }
  this->M[1][3] = v3;
}
