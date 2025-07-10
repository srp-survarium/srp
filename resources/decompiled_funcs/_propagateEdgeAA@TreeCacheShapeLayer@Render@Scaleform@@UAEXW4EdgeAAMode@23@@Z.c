void __thiscall Scaleform::Render::TreeCacheShapeLayer::propagateEdgeAA(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  Scaleform::Render::TreeNode *pNode; // eax
  Scaleform::Render::EdgeAAMode v3; // edx
  unsigned int v4; // esi
  int v5; // eax

  pNode = this->pNode;
  v3 = parentEdgeAA;
  if ( pNode )
  {
    v4 = (unsigned int)pNode & 0xFFFFF000;
    v5 = (int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28;
    if ( parentEdgeAA == EdgeAA_Disable )
    {
      v3 = EdgeAA_Disable;
    }
    else
    {
      v3 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(v4 + 20) + 4 * v5 + 20) & 0xFFFFFFFE) + 6) & 0xC;
      if ( v3 == EdgeAA_Inherit )
        v3 = parentEdgeAA;
    }
  }
  if ( (this->Flags & 0xC) != v3 )
  {
    this->Flags = v3 | this->Flags & 0xFFF3;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
}
