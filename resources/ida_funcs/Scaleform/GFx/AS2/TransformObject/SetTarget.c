void __thiscall Scaleform::GFx::AS2::TransformObject::SetTarget(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v4; // ebx
  Scaleform::GFx::CharacterHandle *v5; // esi
  Scaleform::GFx::CharacterHandle *v6; // esi

  if ( pcharacter )
  {
    pObject = pcharacter->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pcharacter);
    v4 = pObject;
    if ( pObject )
      ++pObject->RefCount;
    v5 = this->TargetHandle.pObject;
    if ( v5 )
    {
      if ( --v5->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v5);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
      }
    }
    this->TargetHandle.pObject = v4;
    this->pMovieRoot = pcharacter->pASRoot->pMovieImpl;
  }
  else
  {
    this->pMovieRoot = 0;
    v6 = this->TargetHandle.pObject;
    if ( v6 )
    {
      if ( --v6->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v6);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      }
    }
    this->TargetHandle.pObject = 0;
  }
}
