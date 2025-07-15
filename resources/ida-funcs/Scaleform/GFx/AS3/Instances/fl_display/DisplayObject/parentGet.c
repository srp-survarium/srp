void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::parentGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer> *result)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v3; // eax
  int v4; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *pObject; // ecx
  unsigned int RefCount; // eax

  pParent = this->pDispObj.pObject->pParent;
  if ( !pParent )
    goto LABEL_13;
  v3 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + pParent->AvmObjOffset)
                                  + 4))((int)pParent + 4 * pParent->AvmObjOffset);
  if ( v3 )
    v4 = v3 - 28;
  else
    v4 = 0;
  if ( *(_DWORD *)(v4 + 8) )
    v5 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v4 + 8);
  else
    v5 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v4 + 4);
  if ( ((unsigned __int8)v5 & 1) != 0 )
    v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v5 - 1);
  if ( v5 && v5->pTraits.pObject->TraitsType >= Traits_DisplayObjectContainer )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v5);
  }
  else
  {
LABEL_13:
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)((char *)pObject - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
        result->pObject = 0;
      }
    }
  }
}
