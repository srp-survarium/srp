void __cdecl Scaleform::GFx::AS3::Instances::fl::Array::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::ASStringNode *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::ASString *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  v4 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(
         (Scaleform::GFx::AS3::Instances::fl::Array *)_this->value.VS._1.VInt,
         (Scaleform::GFx::ASString *)&vm,
         (const Scaleform::GFx::ASString *)(vm->RefCount + 56));
  Scaleform::GFx::AS3::Value::Assign(result, v4);
  v5 = vm;
  --vm->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
