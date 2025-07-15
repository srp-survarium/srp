char __thiscall Scaleform::GFx::DisplayObjContainer::Has3D(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::Render::TreeNode *pObject; // eax
  unsigned int Size; // ebx
  int v5; // edi
  int i; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) != 0 )
  {
    return 1;
  }
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v5 = 0;
  if ( !Size )
    return 0;
  for ( i = 0; ; ++i )
  {
    pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter;
    if ( pCharacter )
    {
      if ( pCharacter->Has3D(pCharacter) )
        break;
    }
    if ( ++v5 >= Size )
      return 0;
  }
  return 1;
}
