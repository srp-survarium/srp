void __thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::~ThunkFunction(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this)
{
  const Scaleform::GFx::AS3::Traits *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Object *v4; // ecx
  unsigned int v5; // eax

  pObject = this->OriginationTraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->OriginationTraits.pObject = (const Scaleform::GFx::AS3::Traits *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::Instances::ThunkFunction_vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  v4 = this->Prototype.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
