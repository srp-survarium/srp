void __thiscall Scaleform::Render::Matrix2x4<float>::SetMatrix(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  *this = *m;
}


void __thiscall Scaleform::Render::Matrix2x4<float>::SetMatrix(
        Scaleform::Render::Matrix2x4<float> *this,
        __int64 v0_Sx,
        float v2_Tx,
        float v3_Shy,
        unsigned int v4_Sy,
        float v5_Ty)
{
  *(_QWORD *)&this->M[0][0] = v0_Sx;
  this->M[0][3] = v2_Tx;
  this->M[0][2] = 0.0;
  this->M[1][0] = v3_Shy;
  *(_QWORD *)&this->M[1][1] = v4_Sy;
  this->M[1][3] = v5_Ty;
}
