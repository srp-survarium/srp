Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Hairliner::StretchTo(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Matrix2x4<float> *result,
        float x1,
        float y1,
        float x2,
        float y2)
{
  unsigned int v7; // ecx
  Scaleform::Render::Hairliner::OutVertexType **Pages; // edx
  float *p_x; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st7
  unsigned int i; // ecx
  Scaleform::Render::Hairliner::OutVertexType *v14; // eax
  double x; // st6
  double y; // st7
  float v18; // [esp+38h] [ebp-28h]
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
    if ( this->OutVertices.Size )
    {
      Pages = this->OutVertices.Pages;
      do
      {
        p_x = &Pages[v7 >> 4][v7 & 0xF].x;
        v10 = *p_x;
        v18 = p_x[1];
        if ( this->MinX > v10 )
          this->MinX = *p_x;
        if ( this->MinY > (double)v18 )
          this->MinY = v18;
        if ( this->MaxX >= v10 )
        {
          v12 = v18;
        }
        else
        {
          v11 = v10;
          v12 = v18;
          this->MaxX = v11;
        }
        if ( this->MaxY < v12 )
          this->MaxY = v12;
        ++v7;
      }
      while ( v7 < this->OutVertices.Size );
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
    for ( i = 0; i < this->OutVertices.Size; v14->y = y * result->M[1][1] + x * result->M[1][0] + result->M[1][3] )
    {
      v14 = &this->OutVertices.Pages[i >> 4][i & 0xF];
      ++i;
      x = v14->x;
      y = v14->y;
      v14->x = result->M[0][1] * y + result->M[0][0] * x + result->M[0][3];
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
