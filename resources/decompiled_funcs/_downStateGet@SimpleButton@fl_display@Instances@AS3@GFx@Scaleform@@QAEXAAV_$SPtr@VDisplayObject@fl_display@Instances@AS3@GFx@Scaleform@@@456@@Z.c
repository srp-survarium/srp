void __thiscall Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::downStateGet(
        Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::AvmButton *v3; // ecx
  Scaleform::GFx::DisplayObject *DownStateObject; // eax
  int AvmObjOffset; // edx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v6; // ecx
  Scaleform::GFx::DisplayObject_vtbl **v7; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // ecx
  unsigned int RefCount; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    v3 = (Scaleform::GFx::AS3::AvmButton *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset);
  else
    v3 = 0;
  DownStateObject = Scaleform::GFx::AS3::AvmButton::GetDownStateObject(v3);
  if ( DownStateObject )
  {
    AvmObjOffset = DownStateObject->AvmObjOffset;
    v6 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)*((_DWORD *)&DownStateObject->pWeakProxy + AvmObjOffset);
    v7 = &DownStateObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + AvmObjOffset;
    if ( v6 )
      v8 = v6;
    else
      v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v7[1];
    if ( ((unsigned __int8)v8 & 1) != 0 )
      v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v8 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v8);
  }
  else
  {
    v9 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v9 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v9 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v9->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
        }
        result->pObject = 0;
      }
    }
  }
}
