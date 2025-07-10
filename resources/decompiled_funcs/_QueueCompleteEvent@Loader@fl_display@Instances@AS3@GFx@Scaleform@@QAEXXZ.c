void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v3; // esi
  Scaleform::GFx::DisplayObject *pObject; // edi
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::GFx::AS3::Value *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  if ( this->pContentLoaderInfo.pObject )
  {
    inserted = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS3::MovieRoot::ActionQueueType *)&this->pTraits.pObject->pVM[1].__vftable[9].GetAdvanceStats,
                 AL_Count_);
    v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)inserted;
    if ( inserted )
    {
      pObject = this->pDispObj.pObject;
      inserted->Type = Entry_Function;
      if ( pObject )
        ++pObject->RefCount;
      v5 = inserted->pCharacter.pObject;
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      v3[2].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pObject;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        v3 + 3,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
      v3[14].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Instances::fl_display::ExecuteCompleteEventCFunc;
      if ( ((int)v3[10].pObject & 0x1F) > 9u )
      {
        v6 = (Scaleform::GFx::AS3::Value *)&v3[10];
        if ( ((int)v3[10].pObject & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
      }
      v3[10].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((int)v3[10].pObject & 0xFFFFFFE0);
      v7 = (Scaleform::RefCountVImpl *)v3[15].pObject;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      v3[15].pObject = 0;
    }
  }
}
