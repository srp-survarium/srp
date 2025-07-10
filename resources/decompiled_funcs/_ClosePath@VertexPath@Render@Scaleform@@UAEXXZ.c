void __thiscall Scaleform::Render::VertexPath::ClosePath(Scaleform::Render::VertexPath *this)
{
  unsigned int LastVertex; // edx
  unsigned int Size; // eax
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_Vertices; // esi
  Scaleform::Render::VertexBasic **Pages; // ecx
  unsigned int v5; // edi
  float *p_x; // ebx
  Scaleform::Render::VertexBasic *v7; // edi
  int v8; // eax

  LastVertex = this->LastVertex;
  if ( this->Vertices.Size - LastVertex > 2 )
  {
    Size = this->Vertices.Size;
    p_Vertices = &this->Vertices;
    Pages = this->Vertices.Pages;
    if ( p_Vertices->Pages[(Size - 1) >> 4][(Size - 1) & 0xF].x != Pages[LastVertex >> 4][LastVertex & 0xF].x
      || p_Vertices->Pages[(p_Vertices->Size - 1) >> 4][(p_Vertices->Size - 1) & 0xF].y != Pages[LastVertex >> 4][LastVertex & 0xF].y )
    {
      v5 = p_Vertices->Size >> 4;
      p_x = &Pages[LastVertex >> 4][LastVertex & 0xF].x;
      if ( v5 >= p_Vertices->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(p_Vertices, p_Vertices->Size >> 4);
      v7 = p_Vertices->Pages[v5];
      v8 = p_Vertices->Size & 0xF;
      v7[v8].x = *p_x;
      v7[v8].y = p_x[1];
      ++p_Vertices->Size;
    }
  }
}
