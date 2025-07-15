void __thiscall Scaleform::Render::MeshKeyManager::MeshKeyManager(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::MemoryHeap *renderHeap)
{
  unsigned int *p_SpinCount; // eax
  Scaleform::Render::MeshKeySet *v4; // eax

  this->__vftable = (Scaleform::Render::MeshKeyManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MeshKeyManager_vtbl *)&Scaleform::Render::MeshKeyManager::`vftable';
  Scaleform::Lock::Lock(&this->KeySetLock, 0);
  if ( this == (Scaleform::Render::MeshKeyManager *)-32 )
    p_SpinCount = 0;
  else
    p_SpinCount = &this->KeySetLock.cs.SpinCount;
  this->KeySets[0].Root.pPrev = (Scaleform::Render::MeshKeySet *)p_SpinCount;
  this->KeySets[0].Root.pNext = (Scaleform::Render::MeshKeySet *)p_SpinCount;
  v4 = &this->KeySets[1] != 0 ? (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.4 : 0;
  this->KeySets[1].Root.pPrev = v4;
  this->KeySets[1].Root.pNext = v4;
  this->pRenderHeap = renderHeap;
}
