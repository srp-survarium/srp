void __thiscall Scaleform::GFx::AS3::VM::exec_instanceof(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::Extra v3; // ecx
  Scaleform::GFx::AS3::Value::V1U v4; // edx
  Scaleform::GFx::AS3::Value::V2U v5; // ecx
  Scaleform::GFx::AS3::Value *v6; // eax
  int v7; // ebx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v10; // ebp
  int v11; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Traits *v14; // edi
  Scaleform::GFx::AS3::Object *i; // edi
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value type; // [esp+18h] [ebp-10h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pCurrent->Bonus;
  v4 = pCurrent->value.VS._1;
  type.Flags = pCurrent->Flags;
  type.Bonus = v3;
  v5.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
  v6 = pCurrent - 1;
  v7 = type.Flags & 0x1F;
  *(_QWORD *)&type.value.VNumber = __PAIR64__((unsigned int)v5.VObj, v4.VUInt);
  this->OpStack.pCurrent = v6;
  if ( v7 == 14 || v7 == 13 )
  {
    v10 = v6;
    v11 = v6->Flags & 0x1F;
    if ( v11 && ((unsigned int)(v11 - 12) > 3 || v10->value.VS._1.VInt) )
    {
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, v10);
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &type);
      v14 = ValueTraits;
      if ( v7 == 13 )
      {
        if ( ClassTraits )
        {
          while ( ClassTraits != (const Scaleform::GFx::AS3::ClassTraits::Traits *)ValueTraits )
          {
            ClassTraits = (const Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits->pParent.pObject;
            if ( !ClassTraits )
              goto LABEL_21;
          }
LABEL_13:
          Scaleform::GFx::AS3::Value::SetBool(v10, 1);
          goto LABEL_22;
        }
      }
      else
      {
        if ( !ValueTraits->pConstructor.pObject )
          ValueTraits->InitOnDemand(ValueTraits);
        for ( i = v14->pConstructor.pObject;
              ClassTraits;
              ClassTraits = (const Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits->pParent.pObject )
        {
          if ( !ClassTraits->pConstructor.pObject )
            ClassTraits->InitOnDemand(&ClassTraits->Scaleform::GFx::AS3::Traits);
          if ( Scaleform::GFx::AS3::Class::GetPrototype(ClassTraits->pConstructor.pObject, (int)i) == i )
            goto LABEL_13;
        }
      }
    }
LABEL_21:
    Scaleform::GFx::AS3::Value::SetBool(v10, 0);
    goto LABEL_22;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v16, eCantUseInstanceofOnNonObjectError, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v8,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v16.Message.pNode;
  --v16.Message.pNode->RefCount;
  if ( !pNode->RefCount )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::GFx::AS3::Value::~Value(&type);
    return;
  }
LABEL_22:
  Scaleform::GFx::AS3::Value::~Value(&type);
}
