void __thiscall Scaleform::GFx::MovieImpl::SetModalClip(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *pmovie,
        unsigned int controllerIdx)
{
  Scaleform::GFx::FocusGroupDescr *v3; // ebx
  Scaleform::GFx::CharacterHandle *v4; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v6; // edi
  Scaleform::GFx::CharacterHandle *v7; // esi

  v3 = &this->FocusGroups[this->FocusGroupIndexes[controllerIdx]];
  if ( pmovie )
  {
    pObject = pmovie->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pmovie);
    v6 = pObject;
    if ( pObject )
      ++pObject->RefCount;
    v7 = v3->ModalClip.pObject;
    if ( v7 )
    {
      if ( --v7->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v7);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
    }
    v3->ModalClip.pObject = v6;
  }
  else
  {
    v4 = this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].ModalClip.pObject;
    if ( v4 )
    {
      if ( --v4->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v4);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
    }
    v3->ModalClip.pObject = 0;
  }
}
