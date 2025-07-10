const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::InitializeOnDemand(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this,
        const Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::ASString *__formal,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *a4,
        unsigned int *a5)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx

  if ( si )
  {
    if ( !this->Initialized )
    {
      this->Execute(this);
      pVM = this->pTraits.pObject->pVM;
      if ( !pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
    }
  }
  return si;
}
