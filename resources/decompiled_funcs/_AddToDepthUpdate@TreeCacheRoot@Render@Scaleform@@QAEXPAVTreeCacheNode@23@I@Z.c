void __thiscall Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
        Scaleform::Render::TreeCacheRoot *this,
        Scaleform::Render::TreeCacheNode *pnode,
        unsigned int flags)
{
  if ( (pnode->UpdateFlags & 0x80000000) != 0 )
  {
    pnode->UpdateFlags |= flags;
  }
  else
  {
    if ( this->DepthUpdatesChained )
    {
      Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::Link(
        &this->DepthUpdates,
        pnode->Depth,
        &pnode->pNextUpdate,
        pnode);
    }
    else
    {
      pnode->pNextUpdate = this->pUpdateList;
      this->pUpdateList = pnode;
    }
    pnode->UpdateFlags |= flags | 0x80000000;
  }
}
