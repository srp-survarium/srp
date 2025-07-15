void __thiscall Scaleform::GFx::InteractiveObject::MoveNameHandle(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v4; // esi
  Scaleform::GFx::CharacterHandle *v5; // esi
  Scaleform::GFx::CharacterHandle *v6; // eax

  pObject = poldChar->pNameHandle.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v4 = this->pNameHandle.pObject;
  if ( v4 )
  {
    if ( --v4->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  this->pNameHandle.pObject = poldChar->pNameHandle.pObject;
  v5 = poldChar->pNameHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v5);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  poldChar->pNameHandle.pObject = 0;
  v6 = this->pNameHandle.pObject;
  if ( v6 )
    v6->pCharacter = this;
}
