Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::operator=(
        Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *this,
        const Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__that)
{
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v5; // eax
  Scaleform::GFx::CharacterHandle *v6; // esi

  if ( __that->ThisObject.pObject )
    __that->ThisObject.pObject->RefCount = (__that->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->ThisObject.pObject;
  if ( this->ThisObject.pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ThisObject.pObject = __that->ThisObject.pObject;
  v5 = __that->ThisChar.pObject;
  if ( v5 )
    ++v5->RefCount;
  v6 = this->ThisChar.pObject;
  if ( v6 )
  {
    if ( --v6->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v6);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
  }
  this->ThisChar.pObject = __that->ThisChar.pObject;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->Function, &__that->Function);
  return this;
}
