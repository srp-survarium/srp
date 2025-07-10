Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::GetMatrix3DF(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  float *v3; // ecx
  long double *v4; // eax
  int v5; // edx
  double v6; // st7

  memset((int)result, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  result->M[0][0] = 1.0;
  result->M[1][1] = 1.0;
  v3 = &result->M[0][2];
  result->M[2][2] = 1.0;
  v4 = &this->mat4.M[0][1];
  result->M[3][3] = 1.0;
  v5 = 2;
  do
  {
    v6 = *(v4 - 1);
    v4 += 8;
    *(v3 - 2) = v6;
    v3 += 8;
    --v5;
    *(v3 - 9) = *(v4 - 8);
    *(v3 - 8) = *(v4 - 7);
    *(v3 - 7) = *(v4 - 6);
    *(v3 - 6) = *(v4 - 5);
    *(v3 - 5) = *(v4 - 4);
    *(v3 - 4) = *(v4 - 3);
    *(v3 - 3) = *(v4 - 2);
  }
  while ( v5 );
  return result;
}
