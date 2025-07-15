void __thiscall Scaleform::Render::Tessellator::Transform(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned int v2; // edi
  Scaleform::Render::TessVertex *v4; // edx
  double x; // st7
  float *p_x; // edx
  double v7; // st7
  float v8; // [esp+Ch] [ebp+4h]

  this->MinX = 1.0e30;
  v2 = 0;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  for ( this->MaxY = -1.0e30; v2 < this->MeshVertices.Size; ++v2 )
  {
    v4 = this->MeshVertices.Pages[v2 >> 4];
    x = v4[v2 & 0xF].x;
    p_x = &v4[v2 & 0xF].x;
    v8 = x;
    v7 = p_x[1];
    *p_x = m->M[0][0] * v8 + v7 * m->M[0][1] + m->M[0][3];
    p_x[1] = v7 * m->M[1][1] + v8 * m->M[1][0] + m->M[1][3];
    if ( this->MinX > (double)*p_x )
      this->MinX = *p_x;
    if ( this->MinY > (double)p_x[1] )
      this->MinY = p_x[1];
    if ( this->MaxX < (double)*p_x )
      this->MaxX = *p_x;
    if ( this->MaxY < (double)p_x[1] )
      this->MaxY = p_x[1];
  }
}
