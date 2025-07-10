void __thiscall Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheNode *pUpdateList; // edi
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *p_DepthUpdates; // ebx
  unsigned int Depth; // esi
  Scaleform::Render::TreeCacheNode *pNextUpdate; // ebp
  char v5; // al
  Scaleform::Render::TreeCacheRoot *v6; // [esp+4h] [ebp-4h]

  pUpdateList = this->pUpdateList;
  v6 = this;
  this->pUpdateList = 0;
  if ( pUpdateList )
  {
    p_DepthUpdates = &this->DepthUpdates;
    do
    {
      Depth = pUpdateList->Depth;
      pNextUpdate = pUpdateList->pNextUpdate;
      if ( Depth < p_DepthUpdates->DepthAvailable
        || (v5 = Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                   p_DepthUpdates,
                   Depth + 1),
            this = v6,
            v5) )
      {
        pUpdateList->pNextUpdate = p_DepthUpdates->pDepth[Depth];
        p_DepthUpdates->pDepth[Depth] = pUpdateList;
        if ( p_DepthUpdates->DepthUsed < Depth + 1 )
          p_DepthUpdates->DepthUsed = Depth + 1;
      }
      pUpdateList = pNextUpdate;
    }
    while ( pNextUpdate );
  }
  this->DepthUpdatesChained = 1;
}
