void __thiscall Scaleform::Render::TreeCacheNode::propagateScale9Flag(
        Scaleform::Render::TreeCacheNode *this,
        __int16 partOfScale9)
{
  if ( Scaleform::Render::StateBag::GetState(
         (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                                    + 4
                                                    * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000))
                                                     / 28)
                                                    + 20)
                                        & 0xFFFFFFFE)
                                       + 64),
         State_Log) )
  {
    partOfScale9 |= 0x80u;
  }
  this->Flags = partOfScale9 | this->Flags & 0xFF7F;
}
