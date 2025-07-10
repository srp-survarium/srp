Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::SetProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  _DWORD *v5; // ecx
  int v6; // eax
  int v7; // edx
  _DWORD *VInt; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+Ch] [ebp-18h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && ((v5 = (_DWORD *)_this->value.VS._1.VInt, v6 = v5[5], v7 = *(_DWORD *)(v6 + 60), (*(_BYTE *)(v6 + 56) & 1) != 0)
     || (v7 == 13 || v7 == 14) && (*(_DWORD *)(v6 + 56) & 0x20) == 0) )
  {
    (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::CheckResult *, Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *, const Scaleform::GFx::AS3::Value *))(*v5 + 12))(
      v5,
      result,
      prop_name,
      value);
    return result;
  }
  else
  {
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::FindObjProperty(&prop, vm, _this, prop_name, FindSet);
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      Scaleform::GFx::AS3::PropRef::SetSlotValue(&prop, result, vm, value);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    else if ( (_this->Flags & 0x1F) - 12 <= 3
           && (VInt = (_DWORD *)_this->value.VS._1.VInt, (*(_DWORD *)(VInt[5] + 56) & 2) != 0)
           && Scaleform::GFx::AS3::Multiname::ContainsNamespace(
                (Scaleform::GFx::AS3::Multiname *)prop_name,
                vm->PublicNamespace.pObject) )
    {
      (*(void (__thiscall **)(_DWORD *, Scaleform::ArrayDefaultPolicy *, const Scaleform::GFx::AS3::Value *, _DWORD))(*VInt + 44))(
        VInt,
        &prop_name->Data.Policy,
        value,
        0);
      result->Result = 1;
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eWriteSealedError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v10,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v12.Message.pNode;
      --v12.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->Result = 0;
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
  }
}
