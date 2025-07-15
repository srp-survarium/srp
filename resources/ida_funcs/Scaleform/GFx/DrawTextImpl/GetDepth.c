int __thiscall Scaleform::GFx::DrawTextImpl::GetDepth(Scaleform::GFx::DrawTextImpl *this)
{
  Scaleform::Render::TreeRoot *pObject; // esi
  unsigned int Size; // ebp
  int v4; // ebx
  Scaleform::Render::TreeText *v5; // edi
  int v6; // eax
  char v7; // dl
  _DWORD *v8; // eax
  char v9; // dl
  unsigned int v10; // ecx

  pObject = this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  Size = Scaleform::Render::TreeContainer::GetSize(pObject);
  v4 = 0;
  if ( !Size )
    return -1;
  v5 = this->pTextNode.pObject;
  v6 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                 + 20);
  v7 = *(_BYTE *)(v6 + 144);
  v8 = (_DWORD *)(v6 + 144);
  v9 = v7 & 1;
  while ( 1 )
  {
    v10 = v9 ? (*v8 & 0xFFFFFFFE) + 8 : (unsigned int)v8;
    if ( *(Scaleform::Render::TreeText **)(v10 + 4 * v4) == v5 )
      break;
    if ( ++v4 >= Size )
      return -1;
  }
  return v4;
}
