void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnRemoved(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        bool byTimeline)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // ecx
  const Scaleform::GFx::ASString *p_pMovieImpl; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ebx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // ecx
  Scaleform::GFx::ASMovieRootBase *v9; // ecx
  const Scaleform::GFx::ASString *v10; // edi
  unsigned int v11; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v12; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v13; // ecx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> evt; // [esp+8h] [ebp-4h] BYREF

  pASRoot = this->pDispObj->pASRoot;
  pAS3RawPtr = this->pAS3RawPtr;
  p_pMovieImpl = (const Scaleform::GFx::ASString *)&pASRoot[15].pMovieImpl;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v6 = pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      v6,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
      p_pMovieImpl,
      1,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v6);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v6, evt.pObject, this->pDispObj);
    if ( evt.pObject )
    {
      if ( ((int)evt.pObject & 1) == 0 )
      {
        RefCount = evt.pObject->RefCount;
        pObject = evt.pObject;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
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
    v9 = this->pDispObj->pASRoot;
    if ( !LOBYTE(v9[2].OnMovieFocus) )
    {
      v10 = (const Scaleform::GFx::ASString *)this->pDispObj->pASRoot;
      v9->CheckAvm(v9);
      Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
        (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v10[10].pNode[19].Size,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
        v10 + 78,
        0,
        0);
      this->PropagateEvent(this, evt.pObject, !byTimeline);
      if ( evt.pObject )
      {
        if ( ((int)evt.pObject & 1) == 0 )
        {
          v11 = evt.pObject->RefCount;
          v12 = evt.pObject;
          if ( ((unsigned int)&byte_3FFFFF & v11) != 0 )
          {
            evt.pObject->RefCount = v11 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
    }
  }
  this->pAS3RawPtr = v6;
  v13 = this->pAS3CollectiblePtr.pObject;
  if ( v13 )
  {
    if ( ((unsigned __int8)v13 & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v13 - 1);
      this->pAS3CollectiblePtr.pObject = 0;
    }
    else
    {
      v14 = v13->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v14) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
      }
      this->pAS3CollectiblePtr.pObject = 0;
    }
  }
}
