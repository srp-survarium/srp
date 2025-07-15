void __thiscall Scaleform::Render::Matrix4x4<float>::Transpose(Scaleform::Render::Matrix4x4<float> *this)
{
  int v1; // eax
  float *v2; // edx
  _DWORD src[16]; // [esp+4h] [ebp-40h] BYREF

  v1 = 0;
  v2 = &this->M[0][2];
  do
  {
    *(float *)&src[v1++] = *(v2 - 2);
    v2 += 4;
    *(float *)&src[v1 + 3] = *(v2 - 5);
    *(float *)&src[v1 + 7] = *(v2 - 4);
    *(float *)&src[v1 + 11] = *(v2 - 3);
  }
  while ( v1 < 4 );
  memcpy((int)this, (const __m128i *)src, sizeof(Scaleform::Render::Matrix4x4<float>));
}


void __thiscall Scaleform::Render::Matrix4x4<double>::Transpose(Scaleform::Render::Matrix4x4<double> *this)
{
  int v1; // eax
  long double *v2; // edx
  double v3; // [esp+0h] [ebp-88h]
  Scaleform::Render::Matrix4x4<double> matDest; // [esp+8h] [ebp-80h] BYREF

  v1 = 0;
  v2 = &this->M[0][2];
  do
  {
    ++v1;
    *(&v3 + v1) = *(v2 - 2);
    v2 += 4;
    matDest.M[0][v1 + 3] = *(v2 - 5);
    matDest.M[1][v1 + 3] = *(v2 - 4);
    matDest.M[2][v1 + 3] = *(v2 - 3);
  }
  while ( v1 < 4 );
  memcpy((int)this, (const __m128i *)&matDest, sizeof(Scaleform::Render::Matrix4x4<double>));
}
