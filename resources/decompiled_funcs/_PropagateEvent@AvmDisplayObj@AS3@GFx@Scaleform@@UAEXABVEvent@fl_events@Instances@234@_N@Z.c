void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        const Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto,
        bool __formal)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebx
  unsigned int RefCount; // edx
  const Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // ecx

  evtProto->Clone(evtProto, (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&evtProto);
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)&pAS3RawPtr[-1].pReleaseProxy.pObject + 3);
  if ( v5 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtProto->Target,
      v5);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v5,
      evtProto,
      this->pDispObj);
  }
  if ( evtProto && ((unsigned __int8)evtProto & 1) == 0 )
  {
    RefCount = evtProto->RefCount;
    v7 = evtProto;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      evtProto->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
  }
}
