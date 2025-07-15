void __thiscall Scaleform::Render::TreeCacheNode::RemoveFromParent(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *pParent; // eax
  bool v3; // zf

  if ( this->pPrev )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
  }
  else
  {
    pParent = this->pParent;
    if ( pParent )
    {
      pParent->Flags &= ~0x10u;
      pParent->pMask = 0;
      this->Flags &= ~0x20u;
    }
  }
  v3 = (this->Flags & 0x40) == 0;
  this->pPrev = 0;
  this->pNext = 0;
  this->pParent = 0;
  this->Depth = 0;
  if ( !v3 )
    this->propagateMaskFlag(this, 0);
  if ( SLOBYTE(this->Flags) < 0 )
    this->propagateScale9Flag(this, 0);
  this->HandleRemoveNode(this);
}
