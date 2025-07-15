void __thiscall Scaleform::Render::Matrix3x4<float>::View(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Point3<float> *eyePt,
        const Scaleform::Render::Point3<float> *zAxis,
        const Scaleform::Render::Point3<float> *upVec)
{
  float v6; // [esp+8h] [ebp-18h]
  float v7; // [esp+8h] [ebp-18h]
  float v8; // [esp+Ch] [ebp-14h]
  float v9; // [esp+Ch] [ebp-14h]
  float v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+10h] [ebp-10h]
  float v12; // [esp+14h] [ebp-Ch]
  float v13; // [esp+18h] [ebp-8h]
  float v14; // [esp+1Ch] [ebp-4h]
  float v15; // [esp+28h] [ebp+8h]
  float v16; // [esp+28h] [ebp+8h]
  float v17; // [esp+28h] [ebp+8h]
  float v18; // [esp+28h] [ebp+8h]
  float v19; // [esp+28h] [ebp+8h]

  v6 = zAxis->z * upVec->y - zAxis->y * upVec->z;
  v8 = zAxis->x * upVec->z - upVec->x * zAxis->z;
  v10 = zAxis->y * upVec->x - zAxis->x * upVec->y;
  v15 = v8 * v8 + v6 * v6 + v10 * v10;
  v16 = sqrt(v15);
  v7 = v6 / v16;
  v9 = v8 / v16;
  v11 = v10 / v16;
  v12 = zAxis->y * v11 - v9 * zAxis->z;
  v13 = v7 * zAxis->z - zAxis->x * v11;
  v14 = zAxis->x * v9 - zAxis->y * v7;
  this->M[0][0] = v7;
  this->M[0][1] = v9;
  this->M[0][2] = v11;
  v17 = v7 * eyePt->x + v9 * eyePt->y + v11 * eyePt->z;
  this->M[0][3] = -v17;
  this->M[1][0] = v12;
  this->M[1][1] = v13;
  this->M[1][2] = v14;
  v18 = v12 * eyePt->x + v13 * eyePt->y + v14 * eyePt->z;
  this->M[1][3] = -v18;
  *(Scaleform::Render::Point3<float> *)&this->M[2][0] = *zAxis;
  v19 = eyePt->y * zAxis->y + eyePt->x * zAxis->x + eyePt->z * zAxis->z;
  this->M[2][3] = -v19;
}


void __thiscall Scaleform::Render::Matrix3x4<double>::View(
        Scaleform::Render::Matrix3x4<double> *this,
        const Scaleform::Render::Point3<double> *eyePt,
        const Scaleform::Render::Point3<double> *zAxis,
        const Scaleform::Render::Point3<double> *upVec)
{
  long double v4; // st7
  long double v5; // st6
  long double v6; // st5
  long double v7; // st7
  long double v8; // st4
  long double v9; // st3
  long double v10; // st2
  long double v11; // st6
  long double xAxis; // [esp+8h] [ebp-18h]
  long double xAxis_8; // [esp+10h] [ebp-10h]
  long double xAxis_16; // [esp+18h] [ebp-8h]

  xAxis = upVec->y * zAxis->z - zAxis->y * upVec->z;
  xAxis_8 = zAxis->x * upVec->z - upVec->x * zAxis->z;
  xAxis_16 = zAxis->y * upVec->x - zAxis->x * upVec->y;
  v4 = sqrt(xAxis * xAxis + xAxis_8 * xAxis_8 + xAxis_16 * xAxis_16);
  v5 = xAxis / v4;
  v6 = xAxis_8 / v4;
  v7 = xAxis_16 / v4;
  v8 = zAxis->y * v7 - v6 * zAxis->z;
  v9 = v5 * zAxis->z - zAxis->x * v7;
  v10 = v5;
  v11 = zAxis->x * v6 - zAxis->y * v5;
  this->M[0][0] = v10;
  this->M[0][1] = v6;
  this->M[0][2] = v7;
  this->M[0][3] = -(v10 * eyePt->x + v6 * eyePt->y + v7 * eyePt->z);
  this->M[1][0] = v8;
  this->M[1][1] = v9;
  this->M[1][2] = v11;
  this->M[1][3] = -(v8 * eyePt->x + v9 * eyePt->y + v11 * eyePt->z);
  *(Scaleform::Render::Point3<double> *)&this->M[2][0] = *zAxis;
  this->M[2][3] = -(zAxis->y * eyePt->y + eyePt->x * zAxis->x + eyePt->z * zAxis->z);
}
