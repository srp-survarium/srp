void __thiscall Scaleform::Render::TreeCacheRoot::~TreeCacheRoot(Scaleform::Render::TreeCacheRoot *this)
{
  this->__vftable = (Scaleform::Render::TreeCacheRoot_vtbl *)&Scaleform::Render::TreeCacheRoot::`vftable';
  if ( this->pPrev )
  {
    this->pPrev->Scaleform::Render::TreeCacheContainer::Scaleform::Render::TreeCacheNode::pNext = this->pNext;
    this->pNext->Scaleform::Render::TreeCacheContainer::Scaleform::Render::TreeCacheNode::pPrev = this->pPrev;
    this->pNext = 0;
    this->pPrev = 0;
  }
  if ( this->DepthUpdates.pDepth != this->DepthUpdates.ArrayReserve )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->DepthUpdates.pDepth);
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(this);
}
