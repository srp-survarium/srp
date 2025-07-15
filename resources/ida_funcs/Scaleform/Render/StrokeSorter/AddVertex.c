void __thiscall Scaleform::Render::StrokeSorter::AddVertex(Scaleform::Render::StrokeSorter *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *p_SrcVertices; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v_12; // [esp+Ch] [ebp-4h]

  p_SrcVertices = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  LOWORD(v_12) = 1;
  BYTE2(v_12) = 0;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(&this->SrcVertices, v4);
  v5 = (int)&p_SrcVertices->Pages[v4][p_SrcVertices->Size & 0xF];
  *(float *)v5 = x;
  *(float *)(v5 + 4) = y;
  *(float *)(v5 + 8) = 0.0;
  *(_DWORD *)(v5 + 12) = v_12;
  ++p_SrcVertices->Size;
}
