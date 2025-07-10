void __thiscall Scaleform::Render::Tessellator::ClosePath(Scaleform::Render::Tessellator *this)
{
  unsigned int LastVertex; // edx
  unsigned int Size; // eax
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_SrcVertices; // esi
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // ecx
  unsigned int v5; // edi
  float *p_x; // ebx
  Scaleform::Render::VertexBasic *v7; // edi
  int v8; // eax

  LastVertex = this->LastVertex;
  if ( this->SrcVertices.Size > LastVertex + 2 )
  {
    Size = this->SrcVertices.Size;
    p_SrcVertices = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices;
    Pages = this->SrcVertices.Pages;
    if ( p_SrcVertices->Pages[(Size - 1) >> 4][(Size - 1) & 0xF].x != Pages[LastVertex >> 4][LastVertex & 0xF].x
      || p_SrcVertices->Pages[(p_SrcVertices->Size - 1) >> 4][(p_SrcVertices->Size - 1) & 0xF].y != Pages[LastVertex >> 4][LastVertex & 0xF].y )
    {
      v5 = p_SrcVertices->Size >> 4;
      p_x = &Pages[LastVertex >> 4][LastVertex & 0xF].x;
      if ( v5 >= p_SrcVertices->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
          p_SrcVertices,
          p_SrcVertices->Size >> 4);
      v7 = p_SrcVertices->Pages[v5];
      v8 = p_SrcVertices->Size & 0xF;
      v7[v8].x = *p_x;
      v7[v8].y = p_x[1];
      ++p_SrcVertices->Size;
    }
  }
}
