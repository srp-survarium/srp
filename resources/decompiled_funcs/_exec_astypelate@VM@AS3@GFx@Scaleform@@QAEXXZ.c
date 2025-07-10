void __thiscall Scaleform::GFx::AS3::VM::exec_astypelate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::Extra v3; // ecx
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V2U v5; // edi
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  int v7; // eax
  bool v8; // al
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v11; // edi
  Scaleform::GFx::AS3::VM::Error v12; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value vclass; // [esp+10h] [ebp-10h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pCurrent->Bonus;
  Flags = pCurrent->Flags;
  --pCurrent;
  v5.VObj = (Scaleform::GFx::AS3::Object *)pCurrent[1].value.VS._2;
  vclass.Bonus = v3;
  v6 = pCurrent[1].value.VS._1;
  this->OpStack.pCurrent = pCurrent;
  v7 = Flags & 0x1F;
  vclass.Flags = Flags;
  *(_QWORD *)&vclass.value.VNumber = __PAIR64__((unsigned int)v5.VObj, v6.VUInt);
  if ( v7 == 13 )
  {
    v11 = this->OpStack.pCurrent;
    if ( !Scaleform::GFx::AS3::VM::IsOfType(this, v11, *(Scaleform::GFx::AS3::ClassTraits::fl::Object **)(v6.VInt + 20)) )
      Scaleform::GFx::AS3::Value::SetNull(v11);
  }
  else
  {
    if ( (Flags & 0x1F) != 0 && ((unsigned int)(v7 - 12) > 3 || v6.VInt) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eIsTypeMustBeClassError, this);
    }
    else
    {
      v8 = (unsigned int)(v7 - 12) <= 3 && v6.VInt == 0;
      Scaleform::GFx::AS3::VM::Error::Error(&v12, (Scaleform::GFx::AS3::VM::ErrorID)(!v8 + 1009), this);
    }
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS3::Value::~Value(&vclass);
      return;
    }
  }
  Scaleform::GFx::AS3::Value::~Value(&vclass);
}
