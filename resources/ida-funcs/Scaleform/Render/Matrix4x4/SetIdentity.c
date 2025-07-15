void __thiscall Scaleform::Render::Matrix4x4<float>::SetIdentity(Scaleform::Render::Matrix4x4<float> *this)
{
  float v2; // xmm0_4

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v2 = s_bm_current_air_resistance;
  this->M[0][0] = s_bm_current_air_resistance;
  this->M[1][1] = v2;
  this->M[2][2] = v2;
  this->M[3][3] = v2;
}
