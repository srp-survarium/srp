void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnAdded(Scaleform::GFx::AS3::AvmDisplayObj *this, bool byTimeline)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  const Scaleform::GFx::ASString *v4; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  _DWORD *v9; // ecx
  const Scaleform::GFx::ASString *pASRoot; // edi
  unsigned int v11; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v12; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> evt; // [esp+8h] [ebp-4h] BYREF

  pAS3RawPtr = this->pAS3RawPtr;
  v4 = (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15];
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)&pAS3RawPtr[-1].pReleaseProxy.pObject + 3);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pAS3CollectiblePtr,
    v5);
  this->pAS3RawPtr = 0;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v5,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
      v4,
      1,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
      v5);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v5,
      evt.pObject,
      this->pDispObj);
    if ( evt.pObject )
    {
      if ( ((int)evt.pObject & 1) == 0 )
      {
        RefCount = evt.pObject->RefCount;
        pObject = evt.pObject;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          evt.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
  {
    this->pDispObj->pASRoot->CheckAvm(this->pDispObj->pASRoot);
    pDispObj = this->pDispObj;
    v9 = &pDispObj->pASRoot->Scaleform::GFx::DisplayObjectBase::__vftable;
    if ( !*(_BYTE *)(v9[10] + 96) )
    {
      pASRoot = (const Scaleform::GFx::ASString *)pDispObj->pASRoot;
      (*(void (__thiscall **)(_DWORD *))(*v9 + 16))(v9);
      Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
        (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)pASRoot[10].pNode[21].RefCount,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
        pASRoot + 76,
        0,
        0);
      this->PropagateEvent(this, evt.pObject, !byTimeline);
      if ( evt.pObject )
      {
        if ( ((int)evt.pObject & 1) == 0 )
        {
          v11 = evt.pObject->RefCount;
          v12 = evt.pObject;
          if ( (v11 & 0x3FFFFF) != 0 )
          {
            evt.pObject->RefCount = v11 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
    }
  }
}
