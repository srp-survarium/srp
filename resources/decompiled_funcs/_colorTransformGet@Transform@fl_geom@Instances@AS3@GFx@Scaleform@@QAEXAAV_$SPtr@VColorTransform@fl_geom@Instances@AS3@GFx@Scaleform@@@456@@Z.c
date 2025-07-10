void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::colorTransformGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::AS3::ASVM *pVM; // ebx
  float *Cxform; // esi
  Scaleform::GFx::AS3::Value *v6; // esi
  int i; // ebx
  unsigned int Flags; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v10; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform> pcolorTransform; // [esp+14h] [ebp-84h] BYREF
  Scaleform::GFx::AS3::Value argv[8]; // [esp+18h] [ebp-80h] BYREF
  char vars0; // [esp+98h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  pDispObj = this->pDispObj;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  pcolorTransform.pObject = 0;
  argv[0].Flags = 0;
  argv[0].Bonus.pWeakProxy = 0;
  argv[1].Flags = 0;
  argv[1].Bonus.pWeakProxy = 0;
  argv[2].Flags = 0;
  argv[2].Bonus.pWeakProxy = 0;
  argv[3].Flags = 0;
  argv[3].Bonus.pWeakProxy = 0;
  argv[4].Flags = 0;
  argv[4].Bonus.pWeakProxy = 0;
  argv[5].Flags = 0;
  argv[5].Bonus.pWeakProxy = 0;
  argv[6].Flags = 0;
  argv[6].Bonus.pWeakProxy = 0;
  argv[7].Flags = 0;
  argv[7].Bonus.pWeakProxy = 0;
  Cxform = (float *)Scaleform::GFx::DisplayObjectBase::GetCxform(pDispObj);
  argv[0].value.VNumber = *Cxform;
  argv[0].Flags = 4;
  argv[1].value.VNumber = Cxform[1];
  argv[1].Flags = 4;
  argv[2].value.VNumber = Cxform[2];
  argv[2].Flags = 4;
  argv[3].value.VNumber = Cxform[3];
  argv[3].Flags = 4;
  argv[4].value.VNumber = Cxform[4] * 255.0;
  argv[4].Flags = 4;
  argv[5].value.VNumber = Cxform[5] * 255.0;
  argv[5].Flags = 4;
  argv[6].value.VNumber = Cxform[6] * 255.0;
  argv[6].Flags = 4;
  argv[7].value.VNumber = Cxform[7] * 255.0;
  argv[7].Flags = 4;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pcolorTransform,
    pVM->ColorTransformClass.pObject,
    8u,
    argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pcolorTransform);
  v6 = (Scaleform::GFx::AS3::Value *)&vars0;
  for ( i = 7; i >= 0; --i )
  {
    Flags = v6[-1].Flags;
    --v6;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
    }
  }
  if ( pcolorTransform.pObject && ((int)pcolorTransform.pObject & 1) == 0 )
  {
    RefCount = pcolorTransform.pObject->RefCount;
    v10 = pcolorTransform.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pcolorTransform.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
    }
  }
}
