void __thiscall Scaleform::Render::MatrixState::getStereoProjectionMatrix(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Matrix4x4<float> *left,
        Scaleform::Render::Matrix4x4<float> *right,
        const Scaleform::Render::Matrix4x4<float> *original,
        float screenDist,
        float factor)
{
  double v7; // st7
  double v8; // st6
  double v9; // st7
  float v10; // [esp+454h] [ebp-108h]
  float v11; // [esp+454h] [ebp-108h]
  float v12; // [esp+458h] [ebp-104h]
  Scaleform::Render::Matrix4x4<float> m2; // [esp+45Ch] [ebp-100h] BYREF
  Scaleform::Render::Matrix4x4<float> dst; // [esp+49Ch] [ebp-C0h] BYREF
  Scaleform::Render::Matrix4x4<float> v15; // [esp+4DCh] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> v16; // [esp+51Ch] [ebp-40h] BYREF

  memset((int)&dst, 0, sizeof(dst));
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  dst.M[3][3] = 1.0;
  memset((int)&m2, 0, sizeof(m2));
  m2.M[0][0] = 1.0;
  m2.M[1][1] = 1.0;
  m2.M[2][2] = 1.0;
  m2.M[3][3] = 1.0;
  memset((int)&v15, 0, sizeof(v15));
  v15.M[0][0] = 1.0;
  v15.M[1][1] = 1.0;
  v15.M[2][2] = 1.0;
  v15.M[3][3] = 1.0;
  v12 = this->S3DParams.Distortion * factor * this->S3DParams.EyeSeparationCm / this->S3DParams.DisplayWidthCm;
  v10 = -v12;
  v7 = v10;
  v11 = v10 * screenDist * original->M[3][2] / original->M[0][0];
  v8 = v11;
  if ( v11 < 0.0 )
  {
    v11 = -v8;
    v8 = v11;
  }
  if ( left )
  {
    dst.M[0][3] = v7;
    m2.M[0][3] = v8;
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v16, original, &m2);
    memcpy((unsigned __int8 *)&v15, (unsigned __int8 *)&v16, sizeof(v15));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v16, &dst, &v15);
    memcpy((unsigned __int8 *)left, (unsigned __int8 *)&v16, sizeof(Scaleform::Render::Matrix4x4<float>));
    v9 = v11;
  }
  else
  {
    v9 = v8;
  }
  if ( right )
  {
    dst.M[0][3] = v12;
    m2.M[0][3] = -v9;
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v16, original, &m2);
    memcpy((unsigned __int8 *)&v15, (unsigned __int8 *)&v16, sizeof(v15));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v16, &dst, &v15);
    memcpy((unsigned __int8 *)right, (unsigned __int8 *)&v16, sizeof(Scaleform::Render::Matrix4x4<float>));
  }
}
