void __thiscall Scaleform::GFx::AS3::InstanceTraits::Function::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *v4; // eax
  Scaleform::GFx::AS3::Value::V1U v5; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Value::V2U v8; // [esp+Ch] [ebp-4h]

  v4 = (Scaleform::GFx::AS3::Instances::FunctionBase *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v4, this);
    v6 = v5;
  }
  else
  {
    v6.VInt = 0;
  }
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v7 = result->Flags & 0xFFFFFFEE;
  result->value.VS._1 = v6;
  result->Flags = v7 | 0xE;
  result->value.VS._2 = v8;
}
