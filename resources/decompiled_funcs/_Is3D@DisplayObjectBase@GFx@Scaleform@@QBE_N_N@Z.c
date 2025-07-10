bool __thiscall Scaleform::GFx::DisplayObjectBase::Is3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::Render::TreeNode *pObject; // eax
  bool result; // al

  do
  {
    pObject = this->pRenNode.pObject;
    result = pObject
          && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                   + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                                   + 20)
                       + 6)
            & 0x200) != 0;
    if ( !bInherit )
      break;
    if ( result )
      return 1;
    this = this->pParent;
  }
  while ( this );
  return result;
}
