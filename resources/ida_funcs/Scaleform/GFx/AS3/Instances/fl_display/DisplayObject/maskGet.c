void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::maskGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::GFx::DisplayObject *Mask; // eax
  Scaleform::WeakPtrProxy *pWeakProxy; // eax

  pObject = result->pObject;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = 0;
  }
  v5 = this->pDispObj.pObject;
  if ( v5 && Scaleform::GFx::DisplayObject::GetMask(v5) )
  {
    Mask = Scaleform::GFx::DisplayObject::GetMask(this->pDispObj.pObject);
    if ( Mask )
      Mask = (Scaleform::GFx::DisplayObject *)((char *)Mask + 4 * Mask->AvmObjOffset);
    if ( Mask->pWeakProxy )
      pWeakProxy = Mask->pWeakProxy;
    else
      pWeakProxy = (Scaleform::WeakPtrProxy *)Mask->RefCount;
    if ( ((unsigned __int8)pWeakProxy & 1) != 0 )
      pWeakProxy = (Scaleform::WeakPtrProxy *)((char *)pWeakProxy - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pWeakProxy);
  }
}
