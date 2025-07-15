const Scaleform::Render::Cxform *__thiscall Scaleform::GFx::DisplayObjectBase::GetCxform(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // eax

  pObject = this->pRenNode.pObject;
  if ( pObject )
    return (const Scaleform::Render::Cxform *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                                         + 4
                                                         * ((int)((int)&pObject[-1]
                                                                - ((unsigned int)pObject & 0xFFFFF000))
                                                          / 28)
                                                         + 20)
                                             + 80);
  else
    return &Scaleform::Render::Cxform::Identity;
}
