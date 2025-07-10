void __thiscall Scaleform::Render::Tessellator::emitStrokerVertex(
        Scaleform::Render::Tessellator *this,
        float x,
        float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // esi
  unsigned int v4; // edi
  int v5; // eax

  p_MeshVertices = &this->MeshVertices;
  v4 = this->MeshVertices.Size >> 4;
  if ( v4 >= this->MeshVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v4);
  v5 = (int)&p_MeshVertices->Pages[v4][p_MeshVertices->Size & 0xF];
  *(float *)v5 = x;
  *(float *)(v5 + 4) = y;
  *(_DWORD *)(v5 + 8) = -1;
  *(_DWORD *)(v5 + 12) = 65537;
  *(_DWORD *)(v5 + 16) = 0;
  ++p_MeshVertices->Size;
}
