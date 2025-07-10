void __thiscall Scaleform::GFx::AS3::Classes::fl::RegExp::Call(
        Scaleform::GFx::AS3::Classes::fl::RegExp *this,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax

  this->Construct(this, result, argc, argv, 0);
  v5 = Scaleform::GFx::AS3::Instances::fl::RegExp::ToString(
         (Scaleform::GFx::AS3::Instances::fl::RegExp *)result->value.VS._1.VInt,
         (Scaleform::GFx::ASString *)&argv);
  Scaleform::GFx::AS3::Value::Assign(result, v5);
  v6 = (Scaleform::GFx::ASStringNode *)argv;
  --argv->value.VS._2.VObj;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
