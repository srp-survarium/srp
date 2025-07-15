void __thiscall Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel srclvl,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel dstlvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pActionRoot; // eax
  const Scaleform::GFx::AS3::MovieRoot::ActionEntry *Next; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **p_pActionRoot; // ebp
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **v9; // eax
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::RefCountNTSImpl *v11; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *p_pAS3Obj; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // ebp
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::Resource *v16; // ecx
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator iter; // [esp+4h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *srclvla; // [esp+20h] [ebp+4h]
  Scaleform::GFx::AS3::MovieRoot::ActionLevel dstlvla; // [esp+24h] [ebp+8h]

  if ( this->ActionQueue.Entries[srclvl].pActionRoot )
  {
    p_ActionQueue = &this->ActionQueue;
    pActionRoot = this->ActionQueue.Entries[srclvl].pActionRoot;
    iter.pActionQueue = &this->ActionQueue;
    srclvla = &this->ActionQueue;
    iter.Level = srclvl;
    iter.ModId = 0;
    iter.pLastEntry = 0;
    iter.pRootEntry = 0;
    iter.pCurEntry = pActionRoot;
    Next = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter);
    if ( Next )
    {
      p_pActionRoot = &p_ActionQueue->Entries[dstlvl].pActionRoot;
      for ( dstlvla = (Scaleform::GFx::AS3::MovieRoot::ActionLevel)p_pActionRoot;
            ;
            p_pActionRoot = (Scaleform::GFx::AS3::MovieRoot::ActionEntry **)dstlvla )
      {
        NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(p_ActionQueue);
        v9 = (Scaleform::GFx::AS3::MovieRoot::ActionEntry **)p_pActionRoot[1];
        if ( v9 )
        {
          NewEntry->pNextEntry = *v9;
          p_pActionRoot[1]->pNextEntry = NewEntry;
        }
        else
        {
          NewEntry->pNextEntry = *p_pActionRoot;
          *p_pActionRoot = NewEntry;
        }
        p_pActionRoot[1] = NewEntry;
        if ( !NewEntry->pNextEntry )
          p_pActionRoot[2] = NewEntry;
        ++p_ActionQueue->ModId;
        NewEntry->Type = Next->Type;
        pObject = Next->pCharacter.pObject;
        if ( pObject )
          ++pObject->RefCount;
        v11 = NewEntry->pCharacter.pObject;
        if ( v11 )
          Scaleform::RefCountNTSImpl::Release(v11);
        p_pAS3Obj = &Next->pAS3Obj;
        p_pObject = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&NewEntry->pAS3Obj.pObject;
        NewEntry->pCharacter.pObject = Next->pCharacter.pObject;
        if ( &Next->pAS3Obj != &NewEntry->pAS3Obj )
        {
          if ( p_pAS3Obj->pObject )
            p_pAS3Obj->pObject->RefCount = (p_pAS3Obj->pObject->RefCount + 1) & 0x8FBFFFFF;
          v14 = *p_pObject;
          if ( *p_pObject )
          {
            if ( ((unsigned __int8)v14 & 1) != 0 )
            {
              *p_pObject = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v14 - 1);
            }
            else
            {
              RefCount = v14->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v14->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
              }
            }
          }
          *p_pObject = p_pAS3Obj->pObject;
        }
        NewEntry->mEventId.Id = Next->mEventId.Id;
        NewEntry->mEventId.WcharCode = Next->mEventId.WcharCode;
        NewEntry->mEventId.KeyCode = Next->mEventId.KeyCode;
        NewEntry->mEventId.AsciiCode = Next->mEventId.AsciiCode;
        NewEntry->mEventId.RollOverCnt = Next->mEventId.RollOverCnt;
        NewEntry->mEventId.ControllerIndex = Next->mEventId.ControllerIndex;
        NewEntry->mEventId.KeysState.States = Next->mEventId.KeysState.States;
        NewEntry->mEventId.MouseWheelDelta = Next->mEventId.MouseWheelDelta;
        NewEntry->CFunction = Next->CFunction;
        v16 = (Scaleform::GFx::Resource *)Next->pNLoadInitCL.pObject;
        if ( v16 )
          Scaleform::RefCountImpl::AddRef(v16);
        v17 = (Scaleform::RefCountVImpl *)NewEntry->pNLoadInitCL.pObject;
        if ( v17 )
          Scaleform::RefCountImpl::Release(v17);
        NewEntry->pNLoadInitCL.pObject = Next->pNLoadInitCL.pObject;
        Next = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter);
        if ( !Next )
          break;
        p_ActionQueue = srclvla;
      }
    }
    if ( iter.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
  }
}
