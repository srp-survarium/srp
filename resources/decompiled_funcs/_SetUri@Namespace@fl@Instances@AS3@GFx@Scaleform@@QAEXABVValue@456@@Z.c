void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v2; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // eax
  const Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v9; // eax

  v2 = value;
  VMRef = this->VMRef;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, value);
  if ( ValueTraits->TraitsType != Traits_QName || (ValueTraits->Flags & 0x20) != 0 )
  {
    Scaleform::GFx::AS3::Value::Convert2String(v2, (Scaleform::GFx::AS3::CheckResult *)&value, &this->Uri);
  }
  else
  {
    v6 = v2->value.VS._1;
    if ( v6.VInt )
    {
      v7 = *(const Scaleform::GFx::ASString **)(v6.VInt + 36);
      if ( v7 )
      {
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v7 + 7);
      }
      else
      {
        ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                        VMRef->StringManagerRef,
                        (Scaleform::GFx::ASString *)&value,
                        "*");
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, ConstString);
        v9 = (Scaleform::GFx::ASStringNode *)value;
        --value->value.VS._2.VObj;
        if ( !v9->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
    }
  }
}
