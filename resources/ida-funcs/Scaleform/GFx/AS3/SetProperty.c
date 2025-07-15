Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::SetProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // edx
  const Scaleform::GFx::AS3::Multiname *v10; // ebx
  _DWORD *VInt; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v14; // eax
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::StringDataPtr v18; // [esp-8h] [ebp-38h]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+18h] [ebp-18h] BYREF

  v5 = _this;
  if ( (_this->Flags & 0x1F) - 12 <= 3
    && ((v6 = (_DWORD *)_this->value.VS._1.VInt, v7 = v6[5], v8 = *(_DWORD *)(v7 + 60), (*(_BYTE *)(v7 + 56) & 1) != 0)
     || (v8 == 13 || v8 == 14) && (*(_DWORD *)(v7 + 56) & 0x20) == 0) )
  {
    (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *, Scaleform::GFx::AS3::Value *))(*v6 + 24))(
      v6,
      result,
      prop_name,
      value);
    return result;
  }
  else
  {
    v10 = (const Scaleform::GFx::AS3::Multiname *)prop_name;
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::FindObjProperty(&prop, vm, _this, prop_name, FindSet);
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      Scaleform::GFx::AS3::PropRef::SetSlotValue(&prop, result, (Scaleform::GFx::ASStringNode *)vm, value);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    else if ( (v5->Flags & 0x1F) - 12 <= 3
           && (VInt = (_DWORD *)v5->value.VS._1.VInt, (*(_DWORD *)(VInt[5] + 56) & 2) != 0)
           && Scaleform::GFx::AS3::Multiname::ContainsNamespace(v10, vm->PublicNamespace.pObject) )
    {
      (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _DWORD))(*VInt + 56))(
        VInt,
        &v10->Name,
        value,
        0);
      result->Result = 1;
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    else
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v5);
      pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&_this)->pNode->pData;
      v18.pStr = pData;
      if ( pData )
        v14 = strlen(pData);
      else
        v14 = 0;
      v18.Size = v14;
      Scaleform::GFx::AS3::VM::Error::Error(
        &v19,
        (Scaleform::GFx::AS3::VM_vtbl *)0x420,
        (Scaleform::GFx::ASStringNode *)vm,
        &v10->Name,
        v18);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v15,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v19.Message.pNode;
      --v19.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v17 = (Scaleform::GFx::ASStringNode *)_this;
      --_this->value.VS._2.VObj;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      result->Result = 0;
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
  }
}
