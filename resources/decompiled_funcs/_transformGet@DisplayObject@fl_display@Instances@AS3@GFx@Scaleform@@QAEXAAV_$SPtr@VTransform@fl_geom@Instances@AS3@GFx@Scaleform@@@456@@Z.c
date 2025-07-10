void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::transformGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::ASVM *pVM; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_geom::Transform *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Transform> ptransform; // [esp+4h] [ebp-4h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  ptransform.pObject = 0;
  if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
         pVM,
         (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&ptransform,
         pVM->TransformClass.pObject,
         0,
         0) )
  {
    ptransform.pObject->pDispObj = this->pDispObj.pObject;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&ptransform);
  if ( ptransform.pObject && ((int)ptransform.pObject & 1) == 0 )
  {
    RefCount = ptransform.pObject->RefCount;
    pObject = ptransform.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      ptransform.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
