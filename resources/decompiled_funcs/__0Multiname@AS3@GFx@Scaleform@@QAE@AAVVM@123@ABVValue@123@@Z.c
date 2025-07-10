void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM *v3; // ebx
  const Scaleform::GFx::AS3::Value *v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // edx
  int v8; // edx
  Scaleform::GFx::AS3::VM *v9; // edi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+10h] [ebp-8h] BYREF

  v3 = vm;
  v5 = v;
  this->Kind = MN_QName;
  this->Obj.pObject = 0;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  v6 = v5->Flags & 0x1F;
  if ( (unsigned int)(v6 - 2) <= 2 || v6 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v5);
  }
  else
  {
    if ( (unsigned int)(v6 - 12) <= 3 )
    {
      v7 = v5->value.VS._1;
      if ( v7.VInt )
      {
        v8 = *(_DWORD *)(v7.VInt + 20);
        if ( *(_DWORD *)(v8 + 60) == 12 && (*(_DWORD *)(v8 + 56) & 0x20) == 0 )
        {
          Scaleform::GFx::AS3::Multiname::SetFromQName(this, v5);
          return;
        }
      }
    }
    if ( (unsigned int)(v6 - 12) > 3 )
    {
      v9 = vm;
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvalidArgumentError, vm);
LABEL_11:
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v9,
        v10,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v12.Message.pNode;
      --v12.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    if ( !v5->value.VS._1.VInt )
    {
      v9 = vm;
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eNotImplementedError, vm);
      goto LABEL_11;
    }
    Scaleform::GFx::AS3::Value::operator=(&this->Name, v5);
    if ( !Scaleform::GFx::AS3::Value::ToStringValue(
            &this->Name,
            (Scaleform::GFx::AS3::CheckResult *)&vm,
            (Scaleform::GFx::ASStringNode *)v3->StringManagerRef)->Result )
      return;
  }
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->PublicNamespace.pObject);
}
