void __thiscall Scaleform::Render::TreeCacheRoot::AddToUpdate(
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
    pnode->pNextUpdate = this->pUpdateList;
    this->pUpdateList = pnode;
    pnode->UpdateFlags |= flags | 0x80000000;
  }
}
