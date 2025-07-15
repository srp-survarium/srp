void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        const Scaleform::GFx::ASString *evtType,
        bool useCapture,
        unsigned int listenersArrSize)
{
  int v4; // edi
  int v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::EventId::IdCode v7; // edx
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v9; // eax

  v4 = *(_DWORD *)(((int)this->pTraits.pObject & 0xFFFFFFFE) + 64);
  v5 = *(_DWORD *)(v4 + 424);
  if ( !v5 )
    return;
  pNode = evtType->pNode;
  if ( evtType->pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 320) )
  {
    *(_DWORD *)(*(_DWORD *)(v5 + 8) + 16244) |= 0x80000u;
    v7 = Event_EnterFrame;
LABEL_14:
    if ( !listenersArrSize )
    {
      pObject = this->pTraits.pObject;
      if ( (unsigned int)(pObject->TraitsType - 17) <= 0xC && (pObject->Flags & 0x20) == 0 )
        Scaleform::GFx::AS3::EventChains::RemoveFromChain(
          (Scaleform::GFx::AS3::EventChains *)(*(_DWORD *)(v4 + 424) + 176),
          v7,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC);
    }
    return;
  }
  if ( pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 324) )
  {
    v7 = Event_FrameConstructed;
    goto LABEL_14;
  }
  if ( pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 328) )
  {
    v7 = Event_ExitFrame;
    goto LABEL_14;
  }
  if ( pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 296) )
  {
    v7 = Event_Activate;
    goto LABEL_14;
  }
  if ( pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 316) )
  {
    v7 = Event_Deactivate;
    goto LABEL_14;
  }
  if ( pNode == *(Scaleform::GFx::ASStringNode **)(v5 + 360) )
  {
    v7 = Event_Render;
    goto LABEL_14;
  }
  if ( *(Scaleform::GFx::ASStringNode **)(v5 + 380) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 396) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 372) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 376) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 392) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 388) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 408) == pNode
    || *(Scaleform::GFx::ASStringNode **)(v5 + 404) == pNode )
  {
    v9 = this->pImpl.pObject;
    if ( useCapture )
    {
      if ( v9->CaptureButtonHandlersCnt != 0xFF )
        --v9->CaptureButtonHandlersCnt;
    }
    else if ( v9->ButtonHandlersCnt != 0xFF )
    {
      --v9->ButtonHandlersCnt;
    }
  }
}
