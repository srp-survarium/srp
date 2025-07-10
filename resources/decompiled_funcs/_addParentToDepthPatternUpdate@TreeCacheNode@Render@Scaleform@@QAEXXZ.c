void __thiscall Scaleform::Render::TreeCacheNode::addParentToDepthPatternUpdate(Scaleform::Render::TreeCacheNode *this)
{
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // eax

  pRoot = this->pRoot;
  if ( pRoot )
  {
    pParent = this->pParent;
    if ( pParent )
      Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
        pRoot,
        pParent,
        (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
  }
}
