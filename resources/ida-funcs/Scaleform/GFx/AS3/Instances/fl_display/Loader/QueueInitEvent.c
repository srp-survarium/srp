void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        Scaleform::GFx::DisplayObject *obj,
        Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pnLoadInitCL)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v5; // esi
  Scaleform::GFx::DisplayObject *pObject; // edi
  Scaleform::RefCountNTSImpl *v7; // ecx
  Scaleform::GFx::AS3::Value *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountNTSImpl *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ecx

  if ( this->pContentLoaderInfo.pObject )
  {
    inserted = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS3::MovieRoot::ActionQueueType *)&this->pTraits.pObject->pVM[1].__vftable[9].GetAdvanceStats,
                 AL_Count_);
    v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)inserted;
    if ( inserted )
    {
      pObject = this->pDispObj.pObject;
      inserted->Type = Entry_Function;
      if ( pObject )
        ++pObject->RefCount;
      v7 = inserted->pCharacter.pObject;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      v5[2].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pObject;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        v5 + 3,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
      v5[14].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Instances::fl_display::ExecuteInitEventCFunc;
      if ( ((int)v5[10].pObject & 0x1F) > 9u )
      {
        v8 = (Scaleform::GFx::AS3::Value *)&v5[10];
        if ( ((int)v5[10].pObject & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v8);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v8);
      }
      v5[10].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((int)v5[10].pObject & 0xFFFFFFE0);
      v9 = (Scaleform::RefCountVImpl *)v5[15].pObject;
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
      v5[15].pObject = 0;
      if ( obj )
        ++obj->RefCount;
      v10 = (Scaleform::RefCountNTSImpl *)v5[2].pObject;
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release(v10);
      v5[2].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)obj;
      if ( pnLoadInitCL.pObject )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pnLoadInitCL.pObject);
      v11 = (Scaleform::RefCountVImpl *)v5[15].pObject;
      if ( v11 )
        Scaleform::RefCountImpl::Release(v11);
      v5[15].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pnLoadInitCL.pObject;
    }
  }
  if ( pnLoadInitCL.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pnLoadInitCL.pObject);
}
