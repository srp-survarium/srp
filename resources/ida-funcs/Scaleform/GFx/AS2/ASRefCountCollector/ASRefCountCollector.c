void __thiscall Scaleform::GFx::AS2::ASRefCountCollector::ASRefCountCollector(
        Scaleform::GFx::AS2::ASRefCountCollector *this)
{
  this->__vftable = (Scaleform::GFx::AS2::ASRefCountCollector_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Roots.Size = 0;
  this->Roots.NumPages = 0;
  this->Roots.MaxPages = 0;
  this->Roots.Pages = 0;
  this->FirstFreeRootIndex = -1;
  this->ListRoot.pRCC = 0;
  this->ListRoot.RefCount = 1;
  this->ListRoot.Scaleform::GFx::AS2::RefCountCollector<323>::__vftable = (Scaleform::GFx::AS2::RefCountCollector<323>::Root_vtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::Root::`vftable';
  this->Flags = 0;
  this->FrameCnt = 0;
  this->PeakRootCount = 0;
  this->LastRootCount = 0;
  this->LastCollectedRoots = 0;
  this->LastPeakRootCount = 0;
  this->TotalFramesCount = 0;
  this->LastCollectionFrameNum = 0;
  this->MaxFramesBetweenCollections = 0;
  this->pLastPtr = &this->ListRoot;
  this->__vftable = (Scaleform::GFx::AS2::ASRefCountCollector_vtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable';
  this->MaxRootCount = 1000;
  this->PresetMaxRootCount = 1000;
}
