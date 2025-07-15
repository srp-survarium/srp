char __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        const Scaleform::GFx::ASString *type,
        Scaleform::RefCountVImpl *target,
        bool useCapture,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::LogState *v9; // esi
  Scaleform::GFx::LogState *LogState; // eax
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *Constructor; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v12; // edi
  bool v13; // bl
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v15; // ecx
  const char *pData; // [esp-8h] [ebp-10h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> evtObj; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pImpl.pObject )
    return 1;
  pObject = this->pTraits.pObject;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  if ( pVM->HandleException )
  {
    v9 = Scaleform::GFx::StateBag::GetLogState(
           &pVM->pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag,
           (Scaleform::Ptr<Scaleform::GFx::LogState> *)&target)->pObject;
    if ( target )
      Scaleform::RefCountImpl::Release(target);
    if ( v9 )
    {
      pData = type->pNode->pData;
      LogState = Scaleform::GFx::AS3::ASVM::GetLogState(pVM);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &LogState->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Can't dispatch '%s' - exception is not cleared",
        pData);
    }
    return 1;
  }
  else
  {
    Constructor = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
    Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
      Constructor,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtObj,
      type,
      0,
      0);
    v12 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)target;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtObj.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)target);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtObj.pObject->CurrentTarget,
      v12);
    if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
            this,
            evtObj.pObject,
            useCapture)
      && dispObject )
    {
      dispObject->Flags |= 0x20u;
    }
    v13 = (*((_BYTE *)evtObj.pObject + 48) & 4) == 0;
    if ( ((int)evtObj.pObject & 1) == 0 )
    {
      RefCount = evtObj.pObject->RefCount;
      v15 = evtObj.pObject;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        evtObj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
      }
    }
    return v13;
  }
}
