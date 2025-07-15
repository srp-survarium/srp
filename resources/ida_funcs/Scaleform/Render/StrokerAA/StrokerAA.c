void __thiscall Scaleform::Render::StrokerAA::StrokerAA(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->MiterLimit = 3.0;
  this->__vftable = (Scaleform::Render::StrokerAA_vtbl *)&Scaleform::Render::StrokerAA::`vftable';
  this->WidthLeft = 0.0;
  this->WidthRight = 0.0;
  this->LineJoin = RoundJoin;
  this->StartLineCap = RoundCap;
  this->AaWidthLeft = 0.5;
  this->EndLineCap = RoundCap;
  this->AaWidthRight = 0.5;
  this->StyleLeft = 1;
  this->Tolerance = 1.0;
  this->StyleRight = 1;
  this->IntersectionEpsilon = 0.0099999998;
  this->Closed = 0;
  this->Path.Path.pHeap = heap;
  this->Path.Path.Size = 0;
  this->Path.Path.NumPages = 0;
  this->Path.Path.MaxPages = 0;
  this->Path.Path.Pages = 0;
  this->Vertices.pHeap = heap;
  this->Vertices.Size = 0;
  this->Vertices.NumPages = 0;
  this->Vertices.MaxPages = 0;
  this->Vertices.Pages = 0;
  this->Triangles.pHeap = heap;
  this->Triangles.Size = 0;
  this->Triangles.NumPages = 0;
  this->Triangles.MaxPages = 0;
  this->Triangles.Pages = 0;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
}
