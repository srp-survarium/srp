void __thiscall Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(
        Scaleform::Render::MeshCacheItemUseNode *this,
        Scaleform::Render::MeshCacheItem *p)
{
  if ( this->pMeshItem )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItemUseNode>::$779B21075EDB092AAA8449DD539B31FB::pPrev = this->pPrev;
  }
  this->pMeshItem = p;
  if ( p )
  {
    this->pNext = p->PrimitiveBatches.Root.pNext;
    this->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&p->PrimitiveBatches;
    p->PrimitiveBatches.Root.pNext->pPrev = this;
    p->PrimitiveBatches.Root.pNext = this;
  }
}
