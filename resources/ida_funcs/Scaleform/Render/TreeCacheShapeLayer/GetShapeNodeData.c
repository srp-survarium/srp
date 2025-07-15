const Scaleform::Render::TreeShape::NodeData *__thiscall Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::TreeNode *pNode; // eax

  pNode = this->pNode;
  if ( !pNode )
    pNode = this->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  return (const Scaleform::Render::TreeShape::NodeData *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000)
                                                                                + 0x14)
                                                                    + 4
                                                                    * ((int)((int)&pNode[-1]
                                                                           - ((unsigned int)pNode & 0xFFFFF000))
                                                                     / 28)
                                                                    + 20)
                                                        & 0xFFFFFFFE);
}
