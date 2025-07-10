void __thiscall Scaleform::Render::Matrix4x4<double>::View(
        Scaleform::Render::Matrix4x4<double> *this,
        const Scaleform::Render::Point3<double> *eyePt,
        const Scaleform::Render::Point3<double> *zAxis,
        const Scaleform::Render::Point3<double> *upVec)
{
  double *v4; // esi
  double v5; // [esp+4h] [ebp-80h]
  double v6; // [esp+Ch] [ebp-78h]
  double v7; // [esp+14h] [ebp-70h]
  double v8; // [esp+1Ch] [ebp-68h]
  double v9; // [esp+24h] [ebp-60h]
  double v10; // [esp+2Ch] [ebp-58h]
  double v11; // [esp+34h] [ebp-50h]
  double v12; // [esp+3Ch] [ebp-48h]
  double v13; // [esp+44h] [ebp-40h]
  double v14; // [esp+4Ch] [ebp-38h]
  double v15; // [esp+54h] [ebp-30h]
  double v16; // [esp+5Ch] [ebp-28h]

  v4 = (double *)this;
  if ( this )
  {
    this->M[0][0] = v5;
    this->M[0][1] = v6;
    this->M[0][2] = v7;
    this->M[0][3] = v8;
    this->M[1][0] = v9;
    this->M[1][1] = v10;
    this->M[1][2] = v11;
    this->M[1][3] = v12;
    this->M[2][0] = v13;
    this->M[2][1] = v14;
    this->M[2][2] = v15;
    this->M[2][3] = v16;
  }
  else
  {
    this = 0;
  }
  Scaleform::Render::Matrix3x4<double>::View((Scaleform::Render::Matrix3x4<double> *)this, eyePt, zAxis, upVec);
  v4[12] = 0.0;
  v4[13] = 0.0;
  v4[14] = 0.0;
  v4[15] = 1.0;
}
