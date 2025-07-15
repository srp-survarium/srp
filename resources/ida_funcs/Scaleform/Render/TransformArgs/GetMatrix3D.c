void __thiscall Scaleform::Render::TransformArgs::GetMatrix3D(
        Scaleform::Render::TransformArgs *this,
        Scaleform::Render::TransformFlags flags,
        Scaleform::Render::Matrix3x4<float> *m)
{
  unsigned __int8 src[48]; // [esp+0h] [ebp-30h] BYREF

  if ( (flags & 0x80u) == 0 )
  {
    *(float *)src = this->Mat.M[0][0];
    *(float *)&src[4] = this->Mat.M[0][1];
    *(float *)&src[8] = this->Mat.M[0][2];
    *(float *)&src[12] = this->Mat.M[0][3];
    *(float *)&src[16] = this->Mat.M[1][0];
    *(float *)&src[20] = this->Mat.M[1][1];
    *(float *)&src[24] = this->Mat.M[1][2];
    *(float *)&src[28] = this->Mat.M[1][3];
    *(float *)&src[32] = 0.0;
    *(float *)&src[36] = 0.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[44] = 0.0;
    memcpy((unsigned __int8 *)m, src, sizeof(Scaleform::Render::Matrix3x4<float>));
  }
  else if ( (flags & 0x40) != 0 )
  {
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(m, &this->Mat3D, &this->Mat);
  }
  else
  {
    memcpy((unsigned __int8 *)m, (unsigned __int8 *)&this->Mat3D, sizeof(Scaleform::Render::Matrix3x4<float>));
  }
}
