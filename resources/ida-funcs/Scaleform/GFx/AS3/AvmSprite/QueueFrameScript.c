void __thiscall Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(
        Scaleform::GFx::AS3::AvmSprite *this,
        unsigned int frame)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ecx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_AVMVersion; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // edi
  Scaleform::RefCountNTSImpl *v11; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v12; // ecx
  unsigned int RefCount; // eax
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::GFx::AS3::Value method; // [esp+Ch] [ebp-10h] BYREF

  pAS3RawPtr = this->pAS3RawPtr;
  pWeakProxy = 0;
  method.Flags = 0;
  method.Bonus.pWeakProxy = 0;
  pObject = pAS3RawPtr;
  if ( !pAS3RawPtr )
    pObject = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pObject & 1) != 0 )
    pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
  if ( pObject )
  {
    if ( !pAS3RawPtr )
      pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
    v6 = pAS3RawPtr;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, unsigned int, Scaleform::GFx::AS3::Value *))v6->__vftable[1].IsAS3Object)(
           v6,
           frame,
           &method) )
    {
      p_AVMVersion = (Scaleform::GFx::AS3::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].AVMVersion;
      NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(p_AVMVersion);
      pInsertEntry = p_AVMVersion->Entries[3].pInsertEntry;
      if ( pInsertEntry )
      {
        NewEntry->pNextEntry = pInsertEntry->pNextEntry;
        p_AVMVersion->Entries[3].pInsertEntry->pNextEntry = NewEntry;
      }
      else
      {
        NewEntry->pNextEntry = p_AVMVersion->Entries[3].pActionRoot;
        p_AVMVersion->Entries[3].pActionRoot = NewEntry;
      }
      p_AVMVersion->Entries[3].pInsertEntry = NewEntry;
      if ( !NewEntry->pNextEntry )
        p_AVMVersion->Entries[3].pLastEntry = NewEntry;
      ++p_AVMVersion->ModId;
      pDispObj = this->pDispObj;
      NewEntry->Type = Entry_Event;
      if ( pDispObj )
        ++pDispObj->RefCount;
      v11 = NewEntry->pCharacter.pObject;
      if ( v11 )
        Scaleform::RefCountNTSImpl::Release(v11);
      NewEntry->pCharacter.pObject = pDispObj;
      Scaleform::GFx::AS3::Value::Assign(&NewEntry->Function, &method);
      NewEntry->CFunction = 0;
      v12 = NewEntry->pAS3Obj.pObject;
      if ( v12 )
      {
        if ( ((unsigned __int8)v12 & 1) != 0 )
        {
          NewEntry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v12 - 1);
        }
        else
        {
          RefCount = v12->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v12->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
        NewEntry->pAS3Obj.pObject = 0;
      }
      v14 = (Scaleform::RefCountVImpl *)NewEntry->pNLoadInitCL.pObject;
      if ( v14 )
        Scaleform::RefCountImpl::Release(v14);
      NewEntry->pNLoadInitCL.pObject = 0;
    }
    pWeakProxy = method.Bonus.pWeakProxy;
  }
  if ( (method.Flags & 0x1F) > 9 )
  {
    if ( (method.Flags & 0x200) != 0 )
    {
      if ( !--pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&method);
    }
  }
}
