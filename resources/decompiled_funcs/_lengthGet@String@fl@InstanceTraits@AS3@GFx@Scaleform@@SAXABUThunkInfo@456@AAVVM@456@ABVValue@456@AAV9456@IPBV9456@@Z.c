void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::lengthGet(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int Length; // eax
  Scaleform::GFx::AS3::Value *v5; // esi
  unsigned int v6; // edi
  unsigned int Flags; // edx
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS3::Value::V2U v9; // [esp+Ch] [ebp-4h]

  _this = _this->pLower;
  ++_this->RefCount;
  Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&_this);
  v5 = result;
  v6 = Length;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  Flags = v5->Flags;
  v5->value.VS._2 = v9;
  v8 = _this;
  v5->value.VS._1.VInt = v6;
  v5->Flags = Flags & 0xFFFFFFE0 | 2;
  if ( !--v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
