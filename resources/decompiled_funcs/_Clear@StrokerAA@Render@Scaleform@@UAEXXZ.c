void __thiscall Scaleform::Render::StrokerAA::Clear(Scaleform::Render::StrokerAA *this)
{
  Scaleform::Render::StrokePath::ClearAndRelease(&this->Path);
  this->Vertices.MaxPages = 0;
  this->Vertices.NumPages = 0;
  this->Vertices.Size = 0;
  this->Vertices.Pages = 0;
  this->Triangles.MaxPages = 0;
  this->Triangles.NumPages = 0;
  this->Triangles.Size = 0;
  this->Triangles.Pages = 0;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->Closed = 0;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
}
