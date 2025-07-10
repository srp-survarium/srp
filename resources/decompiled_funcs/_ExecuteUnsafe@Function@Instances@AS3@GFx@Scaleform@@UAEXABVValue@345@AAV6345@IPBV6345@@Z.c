void __thiscall Scaleform::GFx::AS3::Instances::Function::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::Function *this,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int RefCount; // eax

  this->Execute(this, _this, argc, argv, 0);
  if ( !this->pTraits.pObject->pVM->HandleException )
  {
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pTraits.pObject->pVM, 1u);
    if ( !this->pTraits.pObject->pVM->HandleException )
      Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(this, result);
    if ( ((unsigned __int8)this & 1) == 0 )
    {
      RefCount = this->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        this->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
      }
    }
  }
}
