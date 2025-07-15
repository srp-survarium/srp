Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Tessellator::StretchTo(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Matrix2x4<float> *result,
        float x1,
        float y1,
        float x2,
        float y2)
{
  unsigned int v7; // ecx
  Scaleform::Render::TessVertex **Pages; // edx
  int v9; // eax
  double v10; // st7
  double MinX; // st6
  float v12; // ebx
  double v13; // st6
  double v14; // rt0
  double v15; // st6
  double v16; // st7
  unsigned int i; // ecx
  Scaleform::Render::TessVertex *v18; // eax
  double x; // st6
  double y; // st7
  Scaleform::Render::Matrix2x4<float> m; // [esp+40h] [ebp-20h] BYREF

  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  result->M[1][3] = 0.0;
  result->M[1][1] = 1.0;
  if ( this->MaxX <= (double)this->MinX || this->MaxY <= (double)this->MinY )
  {
    v7 = 0;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    if ( this->MeshVertices.Size )
    {
      Pages = this->MeshVertices.Pages;
      do
      {
        v9 = (int)&Pages[v7 >> 4][v7 & 0xF];
        m.M[0][0] = *(float *)v9;
        v10 = m.M[0][0];
        MinX = this->MinX;
        *(_QWORD *)&m.M[0][1] = *(_QWORD *)(v9 + 4);
        v12 = *(float *)(v9 + 12);
        m.M[1][0] = *(float *)(v9 + 16);
        m.M[0][3] = v12;
        if ( MinX > m.M[0][0] )
          this->MinX = m.M[0][0];
        v13 = m.M[0][1];
        if ( this->MinY > (double)m.M[0][1] )
          this->MinY = m.M[0][1];
        if ( this->MaxX >= v10 )
        {
          v16 = v13;
        }
        else
        {
          v14 = v13;
          v15 = v10;
          v16 = v14;
          this->MaxX = v15;
        }
        if ( this->MaxY < v16 )
          this->MaxY = v16;
        ++v7;
      }
      while ( v7 < this->MeshVertices.Size );
    }
  }
  if ( this->MaxX > (double)this->MinX && this->MaxY > (double)this->MinY )
  {
    Scaleform::Render::Matrix2x4<float>::SetRectToRect(
      result,
      this->MinX,
      this->MinY,
      this->MaxX,
      this->MaxY,
      x1,
      y1,
      x2,
      y2);
    for ( i = 0; i < this->MeshVertices.Size; v18->y = y * result->M[1][1] + x * result->M[1][0] + result->M[1][3] )
    {
      v18 = &this->MeshVertices.Pages[i >> 4][i & 0xF];
      ++i;
      x = v18->x;
      y = v18->y;
      v18->x = result->M[0][1] * y + result->M[0][0] * x + result->M[0][3];
    }
    m.M[0][0] = result->M[0][0];
    m.M[0][1] = result->M[0][1];
    m.M[0][2] = result->M[0][2];
    m.M[0][3] = result->M[0][3];
    m.M[1][0] = result->M[1][0];
    m.M[1][1] = result->M[1][1];
    m.M[1][2] = result->M[1][2];
    m.M[1][3] = result->M[1][3];
    Scaleform::Render::Matrix2x4<float>::SetInverse(result, &m);
  }
  return result;
}
