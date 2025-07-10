void __thiscall Scaleform::Render::TreeCacheRoot::HandleChanges(
        Scaleform::Render::TreeCacheRoot *this,
        __int16 changeBits)
{
  Scaleform::Render::TreeNode *pNode; // ecx

  if ( (changeBits & 0x1000) != 0 )
  {
    pNode = this->pNode;
    if ( (*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                    + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                    + 20)
        & 0xFFFFFFFE) != 0 )
      this->ViewValid = Scaleform::Render::Viewport::GetCullRectF(
                          (Scaleform::Render::Viewport *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000)
                                                                                 + 0x14)
                                                                     + 4
                                                                     * ((int)((int)&pNode[-1]
                                                                            - ((unsigned int)pNode & 0xFFFFF000))
                                                                      / 28)
                                                                     + 20)
                                                         & 0xFFFFFFFE)
                                                        + 160),
                          &this->ViewCullRect,
                          0);
  }
  Scaleform::Render::TreeCacheContainer::HandleChanges(this, changeBits & 0xEFFF);
}
