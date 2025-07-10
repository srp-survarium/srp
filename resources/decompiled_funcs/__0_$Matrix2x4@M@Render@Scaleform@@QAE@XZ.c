void __thiscall Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(Scaleform::Render::Matrix2x4<float> *this)
{
  const vostok::math::float4x4 *v1; // xmm1_4

  v1 = clear_value;
  *(_QWORD *)&this->M[0][0] = (unsigned int)clear_value;
  *(_QWORD *)&this->M[0][2] = 0;
  this->M[1][0] = 0.0;
  *(_QWORD *)&this->M[1][1] = (unsigned int)v1;
  this->M[1][3] = 0.0;
}
