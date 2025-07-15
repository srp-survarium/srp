void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        bool extCall)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v5; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::DisplayObject_vtbl **v8; // eax
  Scaleform::GFx::DisplayObject_vtbl *v9; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *UpdateTransform3D; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // [esp-8h] [ebp-18h]
  Scaleform::StringDataPtr gname; // [esp+8h] [ebp-8h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  if ( extCall )
  {
    pObject = this->pDispObj.pObject;
    if ( pObject )
    {
      v8 = &pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + pObject->AvmObjOffset;
      if ( v8[2] )
        v9 = v8[2];
      else
        v9 = v8[1];
      if ( ((unsigned __int8)v9 & 1) != 0 )
        v9 = (Scaleform::GFx::DisplayObject_vtbl *)((char *)v9 - 1);
      if ( v9 )
      {
        UpdateTransform3D = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)v9->UpdateTransform3D;
        if ( UpdateTransform3D )
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            UpdateTransform3D + 14,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
      }
    }
  }
  else
  {
    CurrentDomain = pVM->CurrentDomain;
    gname.pStr = "flash.display.LoaderInfo";
    gname.Size = 24;
    Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, CurrentDomain);
    v5 = Class;
    if ( Class )
      Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      pVM,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&this->pContentLoaderInfo,
      Class,
      0,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pContentLoaderInfo.pObject->pLoader,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    Scaleform::GFx::AS3::Instances::fl_display::Loader::CreateStageObject(this);
    if ( v5 && ((unsigned __int8)v5 & 1) == 0 )
    {
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
}
