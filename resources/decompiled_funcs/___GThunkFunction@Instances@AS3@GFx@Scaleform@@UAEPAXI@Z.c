Scaleform::GFx::AS3::Instances::CheckTypeTF *__thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        char a2)
{
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::CheckTypeTF_vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  pObject = this->Prototype.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
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
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
