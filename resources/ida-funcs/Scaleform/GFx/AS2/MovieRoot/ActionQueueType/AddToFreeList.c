void __thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::AS2::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::AS2::ActionBuffer *pObject; // ecx
  Scaleform::GFx::InteractiveObject *v4; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v7; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v9; // eax

  pentry->Type = Entry_None;
  pObject = pentry->pActionBuffer.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pentry->pActionBuffer.pObject = 0;
  v4 = pentry->pCharacter.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  pentry->pCharacter.pObject = 0;
  if ( (pentry->Function.Flags & 2) == 0 )
  {
    Function = pentry->Function.Function;
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
  v7 = (pentry->Function.Flags & 1) == 0;
  pentry->Function.Function = 0;
  if ( v7 )
  {
    pLocalFrame = pentry->Function.pLocalFrame;
    if ( pLocalFrame )
    {
      v9 = pLocalFrame->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  pentry->Function.pLocalFrame = 0;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pentry->FunctionParams.Data,
    &pentry->FunctionParams,
    0);
  if ( this->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(pentry);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pentry);
  }
  else
  {
    pentry->pNextEntry = this->pFreeEntry;
    ++this->FreeEntriesCount;
    this->pFreeEntry = pentry;
  }
}
