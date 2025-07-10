void __thiscall Scaleform::Render::VertexPath::FinalizePath(
        Scaleform::Render::VertexPath *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4,
        bool a5)
{
  unsigned int LastVertex; // ebp
  unsigned int v7; // edx
  unsigned int v8; // ebx
  Scaleform::Render::PathBasic *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // [esp+8h] [ebp-4h]

  LastVertex = this->LastVertex;
  v7 = this->Vertices.Size - LastVertex;
  v11 = v7;
  if ( v7 >= 3 )
  {
    v8 = this->Paths.Size >> 2;
    if ( v8 >= this->Paths.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(&this->Paths, v8);
      v7 = v11;
    }
    v9 = this->Paths.Pages[v8];
    v10 = this->Paths.Size & 3;
    v9[v10].Start = LastVertex;
    v9[v10].Count = v7;
    ++this->Paths.Size;
    this->LastVertex = this->Vertices.Size;
  }
  else if ( LastVertex < this->Vertices.Size )
  {
    this->Vertices.Size = LastVertex;
  }
}
