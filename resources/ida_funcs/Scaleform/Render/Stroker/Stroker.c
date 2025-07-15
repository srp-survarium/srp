void __thiscall Scaleform::Render::Stroker::Stroker(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->pHeap = heap;
  this->__vftable = (Scaleform::Render::Stroker_vtbl *)&Scaleform::Render::Stroker::`vftable';
  this->Path.Path.pHeap = heap;
  this->Path.Path.Size = 0;
  this->Path.Path.NumPages = 0;
  this->Path.Path.MaxPages = 0;
  this->Path.Path.Pages = 0;
  this->Width = 1.0;
  this->MiterLimit = 3.0;
  this->LineJoin = RoundJoin;
  this->StartLineCap = RoundCap;
  this->CurveTolerance = 1.0;
  this->EndLineCap = RoundCap;
  this->Closed = 0;
  this->IntersectionEpsilon = 0.0099999998;
}
