void __thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::AS3::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_Function; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::RefCountVImpl *v9; // ecx

  pentry->Type = Entry_None;
  pObject = pentry->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pentry->pCharacter.pObject = 0;
  v4 = pentry->pAS3Obj.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      pentry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
    }
    else
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
    pentry->pAS3Obj.pObject = 0;
  }
  p_Function = &pentry->Function;
  pentry->CFunction = 0;
  if ( (pentry->Function.Flags & 0x1F) > 9 )
  {
    if ( (pentry->Function.Flags & 0x200) != 0 )
    {
      pWeakProxy = pentry->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_Function->Flags &= 0xFFFFFDE0;
      pentry->Function.Bonus.pWeakProxy = 0;
      pentry->Function.value.VNumber = 0.0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pentry->Function);
    }
  }
  p_Function->Flags &= 0xFFFFFFE0;
  v9 = (Scaleform::RefCountVImpl *)pentry->pNLoadInitCL.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  pentry->pNLoadInitCL.pObject = 0;
  if ( this->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(pentry);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pentry);
  }
  else
  {
    pentry->pNextEntry = this->pFreeEntry;
    ++this->FreeEntriesCount;
    this->pFreeEntry = pentry;
  }
}
