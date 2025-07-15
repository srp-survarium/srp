void __thiscall Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(Scaleform::Render::Matrix2x4<float> *this)
{
  float v1; // xmm1_4

  v1 = s_bm_current_air_resistance;
  *(_QWORD *)&this->M[0][0] = LODWORD(s_bm_current_air_resistance);
  *(_QWORD *)&this->M[0][2] = 0;
  this->M[1][0] = 0.0;
  *(_QWORD *)&this->M[1][1] = LODWORD(v1);
  this->M[1][3] = 0.0;
}


void __thiscall Scaleform::Render::Matrix2x4<double>::Matrix2x4<double>(Scaleform::Render::Matrix2x4<double> *this)
{
  this->M[0][0] = 1.0;
  this->M[0][1] = 0.0;
  this->M[0][2] = 0.0;
  this->M[0][3] = 0.0;
  this->M[1][0] = 0.0;
  this->M[1][2] = 0.0;
  this->M[1][3] = 0.0;
  this->M[1][1] = 1.0;
}
