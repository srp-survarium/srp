void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::FunctionBase_vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  this->Prototype.pObject = 0;
  pV = Scaleform::GFx::AS3::VM::MakeObject(
         this->pTraits.pObject->pVM,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *)&t)->pV;
  pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)this->Prototype.pObject;
  if ( pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->Prototype.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
        this->Prototype.pObject = pV;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->Prototype.pObject = pV;
  }
}
