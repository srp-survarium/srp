void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::hitAreaGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite> *result)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  int v3; // eax
  int v4; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // eax
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *v7; // ecx
  unsigned int RefCount; // eax

  pObject = this->pDispObj.pObject;
  if ( !pObject )
    goto LABEL_11;
  v3 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetFOV)(pObject);
  if ( !v3 )
    goto LABEL_11;
  v4 = v3 + 4 * *(unsigned __int8 *)(v3 + 65);
  if ( *(_DWORD *)(v4 + 8) )
    v5 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v4 + 8);
  else
    v5 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v4 + 4);
  if ( ((unsigned __int8)v5 & 1) != 0 )
    v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v5 - 1);
  TraitsType = v5->pTraits.pObject->TraitsType;
  if ( TraitsType == Traits_Sprite || TraitsType == Traits_MovieClip )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v5);
  }
  else
  {
LABEL_11:
    v7 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)((char *)v7 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
        result->pObject = 0;
      }
    }
  }
}
