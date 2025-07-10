void __thiscall Scaleform::Render::Matrix4x4<float>::Transpose(Scaleform::Render::Matrix4x4<float> *this)
{
  int v1; // eax
  float *v2; // edx
  Scaleform::Render::Matrix4x4<float> matDest; // [esp+0h] [ebp-80h]
  _DWORD src[16]; // [esp+40h] [ebp-40h] BYREF

  v1 = 0;
  v2 = &this->M[0][2];
  do
  {
    matDest.M[3][++v1 + 3] = *(v2 - 2);
    v2 += 4;
    *(float *)&src[v1 + 3] = *(v2 - 5);
    *(float *)&src[v1 + 7] = *(v2 - 4);
    *(float *)&src[v1 + 11] = *(v2 - 3);
  }
  while ( v1 < 4 );
  memcpy((unsigned __int8 *)this, (unsigned __int8 *)src, sizeof(Scaleform::Render::Matrix4x4<float>));
}
