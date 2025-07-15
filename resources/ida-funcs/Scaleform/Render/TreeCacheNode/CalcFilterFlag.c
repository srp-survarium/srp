char __thiscall Scaleform::Render::TreeCacheNode::CalcFilterFlag(Scaleform::Render::TreeCacheNode *this)
{
  if ( !this->pParent )
    return 0;
  while ( (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                 + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                                 + 20)
                     & 0xFFFFFFFE)
                    + 6)
         & 0x400) == 0 )
  {
    this = this->pParent;
    if ( !this->pParent )
      return 0;
  }
  return 1;
}
