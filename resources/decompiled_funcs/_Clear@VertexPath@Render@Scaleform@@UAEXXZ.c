void __thiscall Scaleform::Render::VertexPath::Clear(Scaleform::Render::VertexPath *this)
{
  this->Vertices.MaxPages = 0;
  this->Vertices.NumPages = 0;
  this->Vertices.Size = 0;
  this->Vertices.Pages = 0;
  this->Paths.MaxPages = 0;
  this->Paths.NumPages = 0;
  this->Paths.Size = 0;
  this->Paths.Pages = 0;
  this->LastVertex = 0;
}
