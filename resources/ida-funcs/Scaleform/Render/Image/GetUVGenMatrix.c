void __thiscall Scaleform::Render::Image::GetUVGenMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  Scaleform::Render::Texture *v4; // eax
  Scaleform::Render::Texture_vtbl *v5; // eax
  float *v6; // esi
  float v7; // [esp+Ch] [ebp-38h]
  float v8; // [esp+10h] [ebp-34h]
  _DWORD v9[4]; // [esp+14h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> m1; // [esp+24h] [ebp-20h] BYREF

  v4 = this->GetTexture(this, manager);
  if ( v4 )
  {
    v5 = v4->__vftable;
    if ( this->pInverseMatrix )
    {
      ((void (__stdcall *)(Scaleform::Render::Matrix2x4<float> *))v5->GetUVGenMatrix)(&m1);
      v6 = (float *)mat;
      Scaleform::Render::Matrix2x4<float>::SetToAppend(mat, this->pInverseMatrix, &m1);
    }
    else
    {
      v6 = (float *)mat;
      ((void (__stdcall *)(Scaleform::Render::Matrix2x4<float> *))v5->GetUVGenMatrix)(mat);
    }
    this->GetRect(this, (Scaleform::Render::Rect<unsigned long> *)v9);
    v8 = (float)v9[0];
    v7 = (float)v9[1];
    v6[3] = *v6 * v8 + v6[1] * v7 + v6[3];
    v6[7] = v8 * v6[4] + v7 * v6[5] + v6[7];
  }
  else
  {
    mat->M[0][0] = 1.0;
    mat->M[0][1] = 0.0;
    mat->M[0][2] = 0.0;
    mat->M[0][3] = 0.0;
    mat->M[1][0] = 0.0;
    mat->M[1][2] = 0.0;
    mat->M[1][3] = 0.0;
    mat->M[1][1] = 1.0;
  }
}
