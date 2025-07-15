void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *obj)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v2; // esi
  Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl **v4; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *v5; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString evtName; // [esp+8h] [ebp-4h] BYREF

  v2 = obj;
  evtName.pNode = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[44].GetAdvanceStats;
  ++evtName.pNode->RefCount;
  if ( v2 )
  {
    (*(void (__thiscall **)(int, int))(*((_DWORD *)&v2->__vftable + BYTE1(v2[1].pPrev)) + 60))(
      (int)v2 + 4 * BYTE1(v2[1].pPrev),
      1);
    v4 = &v2->__vftable + BYTE1(v2[1].pPrev);
    if ( v4[2] )
      v5 = v4[2];
    else
      v5 = v4[1];
    if ( ((unsigned __int8)v5 & 1) != 0 )
      v5 = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)((char *)v5 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Content,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v5);
  }
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, &evtName, 0) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      this,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&obj,
      &evtName,
      0,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&obj->Target,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, obj, 0);
    if ( obj )
    {
      if ( ((unsigned __int8)obj & 1) == 0 )
      {
        RefCount = obj->RefCount;
        v7 = obj;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          obj->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
  }
  pNode = evtName.pNode;
  --evtName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
