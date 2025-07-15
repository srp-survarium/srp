void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::focusGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::GFx::Sprite *pObject; // esi
  int v4; // eax
  int v5; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v6; // eax
  int TraitsType; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v8; // ecx
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite> v10; // [esp+4h] [ebp-4h] BYREF

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)v2 + 16 * *((unsigned __int8 *)v2 + 16212) + 3801,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&v10);
  pObject = v10.pObject;
  if ( !v10.pObject )
    goto LABEL_13;
  ++v10.pObject->RefCount;
  Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + pObject->AvmObjOffset)
                                  + 4))((int)pObject + 4 * pObject->AvmObjOffset);
  if ( v4 )
    v5 = v4 - 28;
  else
    v5 = 0;
  if ( *(_DWORD *)(v5 + 8) )
    v6 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v5 + 8);
  else
    v6 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v5 + 4);
  if ( ((unsigned __int8)v6 & 1) != 0 )
    v6 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v6 - 1);
  TraitsType = v6->pTraits.pObject->TraitsType;
  if ( TraitsType == 18 || TraitsType >= 23 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v6);
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else
  {
LABEL_13:
    v8 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)v8 - 1);
      }
      else
      {
        RefCount = v8->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
      result->pObject = 0;
    }
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
}
