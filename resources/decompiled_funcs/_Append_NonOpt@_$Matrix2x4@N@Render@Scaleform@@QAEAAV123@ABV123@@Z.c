Scaleform::Render::Matrix2x4<double> *__thiscall Scaleform::Render::Matrix2x4<double>::Append_NonOpt(
        Scaleform::Render::Matrix2x4<double> *this,
        const Scaleform::Render::Matrix2x4<double> *m)
{
  Scaleform::Render::Matrix2x4<double> *result; // eax
  long double v3; // st7
  long double v4; // st6
  long double v5; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // st2

  result = this;
  v3 = this->M[0][0];
  v4 = this->M[0][1];
  v5 = this->M[0][3];
  v6 = this->M[1][0];
  v7 = this->M[1][1];
  v8 = this->M[1][3];
  this->M[0][0] = m->M[0][1] * v6 + m->M[0][0] * v3;
  this->M[1][0] = v3 * m->M[1][0] + v6 * m->M[1][1];
  this->M[0][1] = m->M[0][1] * v7 + m->M[0][0] * v4;
  this->M[1][1] = v4 * m->M[1][0] + v7 * m->M[1][1];
  this->M[0][2] = 0.0;
  this->M[1][2] = 0.0;
  this->M[0][3] = m->M[0][1] * v8 + m->M[0][0] * v5 + m->M[0][3];
  this->M[1][3] = v8 * m->M[1][1] + v5 * m->M[1][0] + m->M[1][3];
  return result;
}
