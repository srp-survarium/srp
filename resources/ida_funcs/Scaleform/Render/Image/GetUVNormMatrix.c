void __thiscall Scaleform::Render::Image::GetUVNormMatrix(
        Scaleform::Render::Image *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  Scaleform::Render::Texture *v4; // eax
  double v5; // st7
  Scaleform::Render::Rect<unsigned long> *v6; // eax
  int v7; // edx
  float v8; // [esp+28h] [ebp-28h]
  float v9; // [esp+2Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+30h] [ebp-20h] BYREF

  v4 = this->GetTexture(this, manager);
  v5 = 0.0;
  if ( v4 )
  {
    v4->GetUVGenMatrix(v4, mat);
    this->GetRect(this, (Scaleform::Render::Rect<unsigned long> *)&m);
    v9 = (float)LODWORD(m.M[0][0]);
    v8 = (float)LODWORD(m.M[0][1]);
    mat->M[0][3] = mat->M[0][0] * v9 + mat->M[0][1] * v8 + mat->M[0][3];
    v5 = v9 * mat->M[1][0] + v8 * mat->M[1][1] + mat->M[1][3];
  }
  else
  {
    mat->M[0][0] = 1.0;
    mat->M[1][1] = 1.0;
    mat->M[0][1] = 0.0;
    mat->M[0][2] = 0.0;
    mat->M[0][3] = 0.0;
    mat->M[1][0] = 0.0;
    mat->M[1][2] = 0.0;
  }
  mat->M[1][3] = v5;
  v6 = this->GetRect(this, &m);
  v7 = v6->y2 - v6->y1;
  m.M[0][0] = (float)(v6->x2 - v6->x1);
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][1] = (float)(unsigned int)v7;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  Scaleform::Render::Matrix2x4<float>::Prepend(mat, &m);
}
