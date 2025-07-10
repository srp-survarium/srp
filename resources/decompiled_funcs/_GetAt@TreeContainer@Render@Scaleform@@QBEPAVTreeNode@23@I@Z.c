Scaleform::Render::TreeNode *__thiscall Scaleform::Render::TreeContainer::GetAt(
        Scaleform::Render::TreeContainer *this,
        unsigned int index)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                            + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                            + 20)
                + 144);
  if ( (*(_BYTE *)v2 & 1) != 0 )
    return *(Scaleform::Render::TreeNode **)((*v2 & 0xFFFFFFFE) + 8 + 4 * index);
  else
    return (Scaleform::Render::TreeNode *)v2[index];
}
