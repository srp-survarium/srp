void __thiscall Scaleform::Render::StrokeGenerator::StrokeGenerator(
        Scaleform::Render::StrokeGenerator *this,
        Scaleform::MemoryHeap *h)
{
  Scaleform::Render::LinearHeap *p_Heap2; // edi

  this->Heap1.pHeap = h;
  this->Heap1.pPagePool = 0;
  this->Heap1.pLastPage = 0;
  this->Heap1.MaxPages = 0;
  p_Heap2 = &this->Heap2;
  this->Heap1.Granularity = 0x2000;
  this->Heap2.Granularity = 0x2000;
  this->Heap2.pHeap = h;
  this->Heap2.pPagePool = 0;
  this->Heap2.pLastPage = 0;
  this->Heap2.MaxPages = 0;
  Scaleform::Render::Stroker::Stroker(&this->mStroker, &this->Heap1);
  Scaleform::Render::StrokeSorter::StrokeSorter(&this->mStrokeSorter, p_Heap2);
  this->mPath.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::VertexPath::`vftable';
  this->mPath.Vertices.Size = 0;
  this->mPath.Vertices.NumPages = 0;
  this->mPath.Vertices.MaxPages = 0;
  this->mPath.Vertices.Pages = 0;
  this->mPath.Vertices.pHeap = &this->Heap1;
  this->mPath.Paths.Size = 0;
  this->mPath.Paths.NumPages = 0;
  this->mPath.Paths.MaxPages = 0;
  this->mPath.Paths.Pages = 0;
  this->mPath.Paths.pHeap = &this->Heap1;
}
