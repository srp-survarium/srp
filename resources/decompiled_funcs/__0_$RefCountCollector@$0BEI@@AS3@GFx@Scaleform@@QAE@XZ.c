void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>(
        Scaleform::GFx::AS3::RefCountCollector<328> *this)
{
  this->__vftable = (Scaleform::GFx::AS3::RefCountCollector<328>_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::AS3::RefCountCollector<328>_vtbl *)&Scaleform::GFx::AS3::ASRefCountCollector::`vftable';
  this->RefCount = 1;
  this->ListRoot.RefCount = 1;
  this->ListRoot.pRCCRaw = 0;
  this->ListRoot.__vftable = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode_vtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode::`vftable';
  this->WProxyHash.mHash.pTable = 0;
  this->Flags = 0;
  this->HeadDelayedPtrRelease.pObject = 0;
  this->pExcludedRoots = 0;
  this->CurrentMaxGen = 2;
  this->pLastPtr = &this->ListRoot;
  this->Roots[0].pRootHead = 0;
  this->Roots[0].nRoots = 0;
  this->Roots[1].pRootHead = 0;
  this->Roots[1].nRoots = 0;
  this->Roots[2].pRootHead = 0;
  this->Roots[2].nRoots = 0;
  this->FinalizeRoots.pRootHead = 0;
  this->FinalizeRoots.nRoots = 0;
}
