BOOL __thiscall Scaleform::GFx::DisplayObjectBase::Has3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // eax

  pObject = this->pRenNode.pObject;
  return pObject
      && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                               + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                               + 20)
                   + 6)
        & 0x200) != 0;
}
