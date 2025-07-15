const Scaleform::GFx::AS3::Abc::Multiname *__thiscall Scaleform::GFx::AS3::InstanceTraits::Function::GetReturnType(
        Scaleform::GFx::AS3::InstanceTraits::Function *this)
{
  int Ind; // edx
  Scaleform::GFx::AS3::Abc::File *pObject; // ecx

  Ind = this->MethodInfoInd.Ind;
  pObject = this->File.pObject->File.pObject;
  return &pObject->Const_Pool.const_multiname.Data.Data[pObject->Methods.Info.Data.Data[pObject->MethodBodies.Info.Data.Data[pObject->Methods.Info.Data.Data[Ind]->MethodBodyInfoInd]->method_info_ind]->RetTypeInd];
}
