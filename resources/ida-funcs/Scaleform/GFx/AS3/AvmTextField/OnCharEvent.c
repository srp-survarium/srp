char __thiscall Scaleform::GFx::AS3::AvmTextField::OnCharEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        wchar_t wcharCode,
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent_vtbl *controllerIdx)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // eax
  const Scaleform::GFx::ASString *v5; // esi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v6; // ebx
  const char *pClassName; // ecx
  Scaleform::GFx::AS3::ASVM *v8; // esi
  Scaleform::GFx::AS3::Object **p_pObject; // eax
  bool v10; // bl
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> evt; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+14h] [ebp-34h] BYREF
  char v21; // [esp+44h] [ebp-4h] BYREF

  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  v5 = (const Scaleform::GFx::ASString *)(*((_DWORD *)this[-1].pClassName + 4) + 420);
  if ( !pDispObj )
    pDispObj = this[-1].pAS3RawPtr;
  v6 = pDispObj;
  if ( ((unsigned __int8)pDispObj & 1) != 0 )
    v6 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
  if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(v6, v5, 0) )
    return 1;
  evt.pObject = 0;
  Scaleform::GFx::AS3::Value::Value(params, v5);
  pClassName = this[-1].pClassName;
  params[1].Flags = 1;
  params[1].value.VS._1.VBool = 1;
  params[2].Flags = 1;
  params[2].value.VS._1.VBool = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[2].Bonus.pWeakProxy = 0;
  v8 = *(Scaleform::GFx::AS3::ASVM **)(*((_DWORD *)pClassName + 4) + 40);
  p_pObject = &v8->TextEventExClass.pObject;
  if ( !v8->ExtensionsEnabled )
    p_pObject = &v8->TextEventClass.pObject;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    v8,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
    *p_pObject,
    3u,
    params);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v6);
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(evt.pObject, wcharCode);
  if ( v8->ExtensionsEnabled )
    evt.pObject[1].__vftable = controllerIdx;
  v10 = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
          v6,
          evt.pObject,
          (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
  v11 = (Scaleform::GFx::AS3::Value *)&v21;
  for ( i = 2; i >= 0; --i )
  {
    Flags = v11[-1].Flags;
    --v11;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        pWeakProxy = v11->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        v11->Flags &= 0xFFFFFDE0;
        v11->Bonus.pWeakProxy = 0;
        v11->value.VS._1.VInt = 0;
        v11->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
      }
    }
  }
  pObject = evt.pObject;
  if ( evt.pObject && ((int)evt.pObject & 1) == 0 )
  {
    RefCount = evt.pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      evt.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  return v10;
}
