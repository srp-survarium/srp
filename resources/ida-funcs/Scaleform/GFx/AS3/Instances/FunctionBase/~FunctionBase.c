void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::~FunctionBase(
        Scaleform::GFx::AS3::Instances::FunctionBase *this)
{
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::FunctionBase_vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  pObject = this->Prototype.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
