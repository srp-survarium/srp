Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetAppDomain(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx

  pObject = this->Script.pObject;
  if ( !pObject->Initialized )
  {
    pObject->Execute(this->Script.pObject);
    pVM = pObject->pTraits.pObject->pVM;
    if ( !pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  }
  return *(Scaleform::GFx::AS3::VMAppDomain **)(this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum + 24);
}
