int __thiscall Scaleform::Render::TreeNode::GetEdgeAAMode(Scaleform::Render::TreeNode *this)
{
  return *(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                              + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                              + 20)
                  + 6)
       & 0xC;
}
