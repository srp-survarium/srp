void __thiscall Scaleform::Render::Hairliner::FinalizePath(
        Scaleform::Render::Hairliner *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4,
        bool a5)
{
  unsigned int LastVertex; // ebp
  unsigned int Size; // eax
  unsigned int v8; // ebx
  Scaleform::Render::Hairliner::PathType *v9; // ebx
  unsigned int v10; // eax
  unsigned int path_4; // [esp+Ch] [ebp-4h]

  LastVertex = this->LastVertex;
  Size = this->SrcVertices.Size;
  if ( Size >= LastVertex + 2 )
  {
    v8 = this->Paths.Size >> 4;
    path_4 = Size - 1;
    if ( v8 >= this->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4> *)&this->Paths,
        v8);
    v9 = this->Paths.Pages[v8];
    v10 = this->Paths.Size & 0xF;
    v9[v10].start = LastVertex;
    v9[v10].end = path_4;
    ++this->Paths.Size;
    this->LastVertex = this->SrcVertices.Size;
  }
  else if ( LastVertex < Size )
  {
    this->SrcVertices.Size = LastVertex;
  }
}
