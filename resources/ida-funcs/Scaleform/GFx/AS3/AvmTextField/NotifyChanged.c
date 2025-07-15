void __thiscall Scaleform::GFx::AS3::AvmTextField::NotifyChanged(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // eax
  const Scaleform::GFx::ASString *v3; // esi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // ebx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> evt; // [esp+Ch] [ebp-4h] BYREF

  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  v3 = (const Scaleform::GFx::ASString *)(*((_DWORD *)this[-1].pClassName + 4) + 424);
  if ( !pDispObj )
    pDispObj = this[-1].pAS3RawPtr;
  v4 = pDispObj;
  if ( ((unsigned __int8)pDispObj & 1) != 0 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
  if ( v4 )
  {
    if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v4, v3, 0) )
    {
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
        v4,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
        v3,
        1,
        0);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v4);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        v4,
        evt.pObject,
        (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
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
  }
}
