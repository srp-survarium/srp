void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::stageGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Stage> *result)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v4; // ecx
  Scaleform::GFx::DisplayObject *v5; // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v6; // ecx
  Scaleform::GFx::AS3::Stage *Stage; // eax
  int v8; // eax
  _DWORD *v9; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v10; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v11; // ecx
  unsigned int RefCount; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    v4 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + pObject->AvmObjOffset);
  else
    v4 = 0;
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v4) )
  {
    v5 = this->pDispObj.pObject;
    if ( v5 )
      v6 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&v5->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v5->AvmObjOffset);
    else
      v6 = 0;
    Stage = Scaleform::GFx::AS3::AvmDisplayObj::GetStage(v6);
    if ( Stage
      && (v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&Stage->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + Stage->AvmObjOffset)
                                          + 20))((int)Stage + 4 * Stage->AvmObjOffset)) != 0 )
    {
      v9 = (_DWORD *)(v8 - 36);
    }
    else
    {
      v9 = 0;
    }
    (*(void (__thiscall **)(_DWORD *, int))(*v9 + 60))(v9, 1);
    v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v9[2];
    if ( !v10 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v9[1];
    if ( ((unsigned __int8)v10 & 1) != 0 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v10 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v10);
  }
  else
  {
    v11 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)v11 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
        result->pObject = 0;
      }
    }
  }
}
