Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetScript(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx

  pObject = this->Script.pObject;
  if ( pObject->Initialized )
    return this->Script.pObject;
  pObject->Execute(this->Script.pObject);
  pVM = pObject->pTraits.pObject->pVM;
  if ( !pVM->HandleException )
    Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  return this->Script.pObject;
}
