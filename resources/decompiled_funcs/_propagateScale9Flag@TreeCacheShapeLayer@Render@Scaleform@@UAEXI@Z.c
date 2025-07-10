void __thiscall Scaleform::Render::TreeCacheShapeLayer::propagateScale9Flag(
        Scaleform::Render::TreeCacheShapeLayer *this,
        unsigned int partOfScale9)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v4; // eax

  pNode = this->pNode;
  if ( pNode
    && Scaleform::Render::StateBag::GetState(
         (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                                                    + 4
                                                    * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000))
                                                     / 28)
                                                    + 20)
                                        & 0xFFFFFFFE)
                                       + 64),
         State_Log) )
  {
    partOfScale9 |= 0x80u;
  }
  v4 = partOfScale9 | this->Flags & 0xFF7F;
  if ( v4 != this->Flags )
  {
    this->Flags = v4;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}
