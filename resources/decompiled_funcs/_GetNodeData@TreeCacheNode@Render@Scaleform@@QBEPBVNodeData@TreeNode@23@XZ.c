const Scaleform::Render::TreeNode::NodeData *__thiscall Scaleform::Render::TreeCacheNode::GetNodeData(
        Scaleform::Render::TreeCacheNode *this)
{
  return (const Scaleform::Render::TreeNode::NodeData *)(*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                                                   + 4
                                                                   * ((int)((int)&this->pNode[-1]
                                                                          - ((int)this->pNode & 0xFFFFF000))
                                                                    / 28)
                                                                   + 20)
                                                       & 0xFFFFFFFE);
}
