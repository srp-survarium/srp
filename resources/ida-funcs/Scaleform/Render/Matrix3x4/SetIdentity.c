void __thiscall Scaleform::Render::Matrix3x4<float>::SetIdentity(Scaleform::Render::Matrix3x4<float> *this)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  memset((unsigned __int8 *)this, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  v2 = clear_value;
  LODWORD(this->M[0][0]) = clear_value;
  LODWORD(this->M[1][1]) = v2;
  LODWORD(this->M[2][2]) = v2;
}
