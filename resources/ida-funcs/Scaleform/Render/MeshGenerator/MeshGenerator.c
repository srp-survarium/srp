void __thiscall Scaleform::Render::MeshGenerator::MeshGenerator(
        Scaleform::Render::MeshGenerator *this,
        Scaleform::MemoryHeap *h)
{
  Scaleform::Render::LinearHeap *p_Heap3; // edi
  Scaleform::Render::LinearHeap *p_Heap4; // ebx

  this->Heap1.pHeap = h;
  this->Heap1.pPagePool = 0;
  this->Heap1.pLastPage = 0;
  this->Heap1.MaxPages = 0;
  this->Heap1.Granularity = 0x2000;
  this->Heap2.pPagePool = 0;
  this->Heap2.pLastPage = 0;
  this->Heap2.MaxPages = 0;
  this->Heap2.pHeap = h;
  this->Heap2.Granularity = 0x2000;
  p_Heap3 = &this->Heap3;
  this->Heap3.pPagePool = 0;
  this->Heap3.pLastPage = 0;
  this->Heap3.MaxPages = 0;
  this->Heap3.pHeap = h;
  this->Heap3.Granularity = 0x2000;
  p_Heap4 = &this->Heap4;
  this->Heap4.pPagePool = 0;
  this->Heap4.pLastPage = 0;
  this->Heap4.MaxPages = 0;
  this->Heap4.pHeap = h;
  this->Heap4.Granularity = 0x2000;
  Scaleform::Render::Tessellator::Tessellator(&this->mTess, &this->Heap1, &this->Heap2);
  Scaleform::Render::Stroker::Stroker(&this->mStroker, p_Heap3);
  Scaleform::Render::StrokeSorter::StrokeSorter(&this->mStrokeSorter, p_Heap4);
  Scaleform::Render::Hairliner::Hairliner(&this->mHairliner, p_Heap3);
  Scaleform::Render::StrokerAA::StrokerAA(&this->mStrokerAA, p_Heap3);
}
