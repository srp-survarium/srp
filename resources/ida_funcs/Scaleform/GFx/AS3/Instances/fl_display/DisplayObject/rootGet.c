void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::rootGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // ecx
  Scaleform::GFx::DisplayObject *Root; // eax
  Scaleform::GFx::DisplayObject_vtbl **v5; // esi
  Scaleform::GFx::DisplayObject_vtbl *v6; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // ecx
  unsigned int RefCount; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    v3 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + pObject->AvmObjOffset);
  else
    v3 = 0;
  Root = Scaleform::GFx::AS3::AvmDisplayObj::GetRoot(v3);
  if ( Root
    && (v5 = &Root->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + Root->AvmObjOffset) != 0 )
  {
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **, int))(*v5)->GetRatio)(v5, 1);
    v6 = v5[2];
    if ( !v6 )
      v6 = v5[1];
    if ( ((unsigned __int8)v6 & 1) != 0 )
      v6 = (Scaleform::GFx::DisplayObject_vtbl *)((char *)v6 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v6);
  }
  else
  {
    v7 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v7->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
        result->pObject = 0;
      }
    }
  }
}
