Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SetupSlotValues(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::Object *v3; // ebp
  const Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  const Scaleform::GFx::AS3::Abc::ClassInfo *class_info; // ebx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v8; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx

  v3 = for_obj;
  pObject = this->pParent.pObject;
  if ( !pObject || pObject->SetupSlotValues(pObject, (Scaleform::GFx::AS3::CheckResult *)&for_obj, for_obj)->Result )
  {
    class_info = this->class_info;
    v8 = this->Script.pObject;
    if ( !v8->Initialized )
    {
      v8->Execute(this->Script.pObject);
      pVM = v8->pTraits.pObject->pVM;
      if ( !pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
    }
    Scaleform::GFx::AS3::Traits::SetupSlotValues(
      this,
      result,
      (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      &class_info->inst_info,
      v3);
    return result;
  }
  else
  {
    v6 = result;
    result->Result = 0;
  }
  return v6;
}
