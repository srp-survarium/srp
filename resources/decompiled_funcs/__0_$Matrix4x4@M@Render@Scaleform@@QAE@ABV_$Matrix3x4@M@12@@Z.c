void __thiscall Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(
        Scaleform::Render::Matrix4x4<float> *this,
        const Scaleform::Render::Matrix3x4<float> *m)
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
  this->M[3][0] = 0.0;
  this->M[3][1] = 0.0;
  this->M[3][2] = 0.0;
  this->M[3][3] = 1.0;
}
