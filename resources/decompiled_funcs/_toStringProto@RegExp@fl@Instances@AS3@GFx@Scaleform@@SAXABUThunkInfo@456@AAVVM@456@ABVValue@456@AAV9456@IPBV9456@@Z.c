void __cdecl Scaleform::GFx::AS3::Instances::fl::RegExp::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::ASString *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  v4 = Scaleform::GFx::AS3::Instances::fl::RegExp::ToString(
         (Scaleform::GFx::AS3::Instances::fl::RegExp *)_this->pLower,
         (Scaleform::GFx::ASString *)&_this);
  Scaleform::GFx::AS3::Value::Assign(result, v4);
  v5 = _this;
  --_this->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
