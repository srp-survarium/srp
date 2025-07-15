void __thiscall Scaleform::Render::StrokeSorter::AddVertexNV(
        Scaleform::Render::StrokeSorter *this,
        float x,
        float y,
        unsigned __int8 segType)
{
  unsigned int Size; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // edi
  unsigned int v6; // eax
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *p_SrcVertices; // esi
  unsigned int v8; // edi
  int v9; // eax
  int v_12; // [esp+Ch] [ebp-4h]

  Size = this->SrcVertices.Size;
  if ( Size == this->LastVertex
    && Size
    && (Pages = this->SrcVertices.Pages, x == Pages[(Size - 1) >> 4][(Size - 1) & 0xF].x)
    && y == Pages[(this->SrcVertices.Size - 1) >> 4][(this->SrcVertices.Size - 1) & 0xF].y )
  {
    this->LastVertex = this->SrcPaths.Pages[(this->SrcPaths.Size - 1) >> 4][(this->SrcPaths.Size - 1) & 0xF].start;
    v6 = this->SrcPaths.Size;
    if ( v6 )
      this->SrcPaths.Size = v6 - 1;
  }
  else
  {
    p_SrcVertices = &this->SrcVertices;
    v8 = this->SrcVertices.Size >> 4;
    LOWORD(v_12) = segType;
    BYTE2(v_12) = 0;
    if ( v8 >= this->SrcVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(&this->SrcVertices, v8);
    v9 = (int)&p_SrcVertices->Pages[v8][p_SrcVertices->Size & 0xF];
    *(float *)v9 = x;
    *(float *)(v9 + 4) = y;
    *(float *)(v9 + 8) = 0.0;
    *(_DWORD *)(v9 + 12) = v_12;
    ++p_SrcVertices->Size;
  }
}
