void __thiscall Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(
        Scaleform::GFx::AS2::MovieRoot::ActionEntry *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::ActionBuffer *pObject; // ecx
  Scaleform::GFx::InteractiveObject *v8; // ecx

  Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(
    this->FunctionParams.Data.Data,
    this->FunctionParams.Data.Size);
  if ( this->FunctionParams.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FunctionParams.Data.Data);
  if ( (this->Function.Flags & 2) == 0 )
  {
    Function = this->Function.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Function.Flags & 1) == 0;
  this->Function.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Function.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Function.pLocalFrame = 0;
  pObject = this->pActionBuffer.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v8 = this->pCharacter.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
}
