void __thiscall Scaleform::GFx::AS2::TransformObject::Finalize_GC(Scaleform::GFx::AS2::TransformObject *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // esi

  this->pMovieRoot = 0;
  pObject = this->TargetHandle.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
