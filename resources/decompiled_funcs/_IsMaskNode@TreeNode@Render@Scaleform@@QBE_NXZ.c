int __thiscall Scaleform::Render::TreeNode::IsMaskNode(Scaleform::Render::TreeNode *this)
{
  return (*(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                          + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                                          + 20)
                              + 6) >> 5)
       & 1;
}
