void __thiscall Scaleform::Render::TreeCacheNode::HandleRemoveNode(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheNode *pMask; // ecx

  this->pRoot = 0;
  pMask = this->pMask;
  if ( pMask )
    pMask->HandleRemoveNode(pMask);
}
