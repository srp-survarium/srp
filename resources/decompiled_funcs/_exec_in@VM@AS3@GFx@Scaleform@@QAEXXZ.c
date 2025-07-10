void __thiscall Scaleform::GFx::AS3::VM::exec_in(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::Extra v3; // ecx
  _DWORD *VInt; // ebp
  Scaleform::GFx::AS3::Value::V2U v5; // edx
  int v6; // edi
  Scaleform::GFx::AS3::Value *v7; // ebx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  int v11; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  bool *v13; // eax
  bool v14; // al
  char v15; // [esp+13h] [ebp-59h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+24h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> stack; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+54h] [ebp-18h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pCurrent->Bonus;
  VInt = (_DWORD *)pCurrent->value.VS._1.VInt;
  v5.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
  stack._2.Flags = pCurrent->Flags;
  v6 = stack._2.Flags & 0x1F;
  v7 = pCurrent - 1;
  stack._2.Bonus = v3;
  *(_QWORD *)&stack._2.value.VNumber = __PAIR64__((unsigned int)v5.VObj, (unsigned int)VInt);
  this->OpStack.pCurrent = pCurrent - 1;
  stack._1 = pCurrent - 1;
  if ( v6 && ((unsigned int)(v6 - 12) > 3 || VInt) )
  {
    pObject = this->PublicNamespace.pObject;
    prop_name.Kind = MN_QName;
    prop_name.Obj.pObject = pObject;
    if ( pObject )
    {
      ++pObject->RefCount;
      pObject->RefCount &= 0x8FBFFFFF;
    }
    prop_name.Name.Flags = 0;
    prop_name.Name.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&prop_name, v7);
    if ( (unsigned int)(v6 - 12) <= 3
      && ((v11 = VInt[5], (*(_BYTE *)(v11 + 56) & 1) != 0)
       || *(_DWORD *)(v11 + 60) == 13 && (*(_DWORD *)(v11 + 56) & 0x20) == 0) )
    {
      Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
      value = *Undefined;
      if ( (Undefined->Flags & 0x1F) > 9 )
      {
        if ( (Undefined->Flags & 0x200) != 0 )
          ++Undefined->Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
      }
      v13 = (bool *)(*(int (__thiscall **)(_DWORD *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*VInt + 16))(
                      VInt,
                      &v15,
                      &prop_name,
                      &value);
      Scaleform::GFx::AS3::Value::SetBool(v7, *v13);
      if ( this->HandleException )
        this->HandleException = 0;
      Scaleform::GFx::AS3::Value::~Value(&value);
    }
    else
    {
      memset(&prop, 0, 16);
      Scaleform::GFx::AS3::FindObjProperty(
        &prop,
        this,
        &stack._2,
        (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&prop_name,
        FindGet);
      v14 = (prop.This.Flags & 0x1F) != 0
         && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
         && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0);
      Scaleform::GFx::AS3::Value::SetBool(v7, v14);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eConvertNullToObjectError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v8,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)value.Bonus.pWeakProxy;
    --value.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&stack);
      return;
    }
  }
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&stack);
}
