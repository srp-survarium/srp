Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v4; // edi
  Scaleform::GFx::AS3::CheckResult *VectorInd; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::ASStringNode *pVM; // esi
  const char *v11; // eax
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-20h]
  unsigned int ind; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [esp+10h] [ebp-8h] BYREF

  v4 = prop_name;
  VectorInd = Scaleform::GFx::AS3::GetVectorInd(
                (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                prop_name,
                (Scaleform::GFx::AS3::Value::V1U *)&ind);
  pObject = this->pTraits.pObject;
  if ( VectorInd->Result )
  {
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Set(
      &this->V,
      result,
      ind,
      value,
      (Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject[1]._pRCC);
    return result;
  }
  else
  {
    pVM = (Scaleform::GFx::ASStringNode *)pObject->pVM;
    v11 = **(const char ***)((int (__stdcall *)(const Scaleform::GFx::AS3::Multiname **))pObject->GetName)(&prop_name);
    v16.pStr = v11;
    if ( v11 )
      v12 = strlen(v11);
    else
      v12 = 0;
    v16.Size = v12;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, (Scaleform::GFx::AS3::VM_vtbl *)0x420, pVM, &v4->Name, v16);
    Scaleform::GFx::AS3::VM::ThrowReferenceError((Scaleform::GFx::AS3::VM *)pVM, v13);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v15 = (Scaleform::GFx::ASStringNode *)prop_name;
    --prop_name->Name.Bonus.pWeakProxy;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v9 = result;
    result->Result = 0;
  }
  return v9;
}
