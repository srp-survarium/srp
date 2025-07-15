void __thiscall Scaleform::Render::StrokeSorter::FinalizePath(
        Scaleform::Render::StrokeSorter *this,
        unsigned int closeFlag,
        unsigned int __formal,
        bool a4,
        bool a5)
{
  unsigned int LastVertex; // ebp
  unsigned int Size; // eax
  unsigned int v8; // ebx
  Scaleform::Render::StrokeSorter::PathType *v9; // ecx
  unsigned int v10; // eax
  unsigned int p_4; // [esp+Ch] [ebp-4h]

  LastVertex = this->LastVertex;
  Size = this->SrcVertices.Size;
  if ( Size <= LastVertex + 1 )
  {
    if ( LastVertex < Size )
      this->SrcVertices.Size = LastVertex;
  }
  else
  {
    p_4 = Size - LastVertex;
    if ( closeFlag )
      p_4 |= 0x20000000u;
    v8 = this->SrcPaths.Size >> 4;
    if ( v8 >= this->SrcPaths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcPaths,
        v8);
    v9 = this->SrcPaths.Pages[v8];
    v10 = this->SrcPaths.Size & 0xF;
    v9[v10].start = LastVertex;
    v9[v10].numVer = p_4;
    ++this->SrcPaths.Size;
    this->LastVertex = this->SrcVertices.Size;
  }
}
