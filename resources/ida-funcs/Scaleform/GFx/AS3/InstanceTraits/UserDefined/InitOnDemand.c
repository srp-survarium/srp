void __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::InitOnDemand(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v4; // esi
  Scaleform::GFx::AS3::VM *v5; // ecx

  pObject = this->Script.pObject;
  if ( !pObject->Initialized )
  {
    pObject->Execute(this->Script.pObject);
    pVM = pObject->pTraits.pObject->pVM;
    if ( !pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  }
  v4 = this->Script.pObject;
  if ( !v4->Initialized )
  {
    v4->Execute(this->Script.pObject);
    v5 = v4->pTraits.pObject->pVM;
    if ( !v5->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v5, 1u);
  }
}
