void __thiscall Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  this->M[0][0] = m->M[0][0];
  this->M[0][1] = m->M[0][1];
  this->M[0][2] = m->M[0][2];
  this->M[0][3] = m->M[0][3];
  this->M[1][0] = m->M[1][0];
  this->M[1][1] = m->M[1][1];
  this->M[1][2] = m->M[1][2];
  this->M[1][3] = m->M[1][3];
  this->M[2][0] = 0.0;
  this->M[2][1] = 0.0;
  this->M[2][2] = 1.0;
  this->M[2][3] = 0.0;
}


void __thiscall Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Matrix4x4<float> *m)
{
  this->M[0][0] = m->M[0][0];
  this->M[0][1] = m->M[0][1];
  this->M[0][2] = m->M[0][2];
  this->M[0][3] = m->M[0][3];
  this->M[1][0] = m->M[1][0];
  this->M[1][1] = m->M[1][1];
  this->M[1][2] = m->M[1][2];
  this->M[1][3] = m->M[1][3];
  this->M[2][0] = m->M[2][0];
  this->M[2][1] = m->M[2][1];
  this->M[2][2] = m->M[2][2];
  this->M[2][3] = m->M[2][3];
}


void __thiscall Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(Scaleform::Render::Matrix3x4<float> *this)
{
  float v2; // xmm0_4

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  v2 = s_bm_current_air_resistance;
  this->M[0][0] = s_bm_current_air_resistance;
  this->M[1][1] = v2;
  this->M[2][2] = v2;
}
