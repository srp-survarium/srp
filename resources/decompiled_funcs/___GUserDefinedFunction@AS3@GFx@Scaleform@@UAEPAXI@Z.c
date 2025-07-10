Scaleform::GFx::AS3::UserDefinedFunction *__thiscall Scaleform::GFx::AS3::UserDefinedFunction::`scalar deleting destructor'(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::AS3::Instances::FunctionBase::~FunctionBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
