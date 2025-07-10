void __thiscall Scaleform::GFx::AS2::Value::ConvertToStringVersioned(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *pEnv,
        Scaleform::GFx::ASStringNode *version)
{
  Scaleform::GFx::ASStringNode *v4; // ecx
  bool v5; // zf

  Scaleform::GFx::AS2::Value::ToStringVersioned(this, (Scaleform::GFx::ASString *)&version, pEnv, (unsigned int)version);
  Scaleform::GFx::AS2::Value::DropRefs(this);
  v4 = version;
  this->T.Type = 5;
  this->NV.Int32Value = (int)v4;
  v5 = ++v4->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}
