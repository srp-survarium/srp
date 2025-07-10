void __thiscall Scaleform::Render::Matrix3x4<float>::View(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Point3<float> *eyePt,
        const Scaleform::Render::Point3<float> *zAxis,
        const Scaleform::Render::Point3<float> *upVec)
{
  float xAxis; // [esp+8h] [ebp-18h]
  float xAxisa; // [esp+8h] [ebp-18h]
  float xAxis_4; // [esp+Ch] [ebp-14h]
  float xAxis_4a; // [esp+Ch] [ebp-14h]
  float xAxis_8; // [esp+10h] [ebp-10h]
  float xAxis_8a; // [esp+10h] [ebp-10h]
  float yAxis; // [esp+14h] [ebp-Ch]
  float yAxis_4; // [esp+18h] [ebp-8h]
  float yAxis_8; // [esp+1Ch] [ebp-4h]
  float zAxisa; // [esp+28h] [ebp+8h]
  float zAxisb; // [esp+28h] [ebp+8h]
  float zAxisc; // [esp+28h] [ebp+8h]
  float zAxisd; // [esp+28h] [ebp+8h]
  float zAxise; // [esp+28h] [ebp+8h]

  xAxis = zAxis->z * upVec->y - zAxis->y * upVec->z;
  xAxis_4 = zAxis->x * upVec->z - upVec->x * zAxis->z;
  xAxis_8 = zAxis->y * upVec->x - zAxis->x * upVec->y;
  zAxisa = xAxis_4 * xAxis_4 + xAxis * xAxis + xAxis_8 * xAxis_8;
  zAxisb = sqrt(zAxisa);
  xAxisa = xAxis / zAxisb;
  xAxis_4a = xAxis_4 / zAxisb;
  xAxis_8a = xAxis_8 / zAxisb;
  yAxis = zAxis->y * xAxis_8a - xAxis_4a * zAxis->z;
  yAxis_4 = xAxisa * zAxis->z - zAxis->x * xAxis_8a;
  yAxis_8 = zAxis->x * xAxis_4a - zAxis->y * xAxisa;
  this->M[0][0] = xAxisa;
  this->M[0][1] = xAxis_4a;
  this->M[0][2] = xAxis_8a;
  zAxisc = xAxisa * eyePt->x + xAxis_4a * eyePt->y + xAxis_8a * eyePt->z;
  this->M[0][3] = -zAxisc;
  this->M[1][0] = yAxis;
  this->M[1][1] = yAxis_4;
  this->M[1][2] = yAxis_8;
  zAxisd = yAxis * eyePt->x + yAxis_4 * eyePt->y + yAxis_8 * eyePt->z;
  this->M[1][3] = -zAxisd;
  *(Scaleform::Render::Point3<float> *)&this->M[2][0] = *zAxis;
  zAxise = eyePt->y * zAxis->y + eyePt->x * zAxis->x + eyePt->z * zAxis->z;
  this->M[2][3] = -zAxise;
}
