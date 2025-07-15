void __thiscall Scaleform::GFx::AS2::XMLAttributeStringBuilder::Visit(
        Scaleform::GFx::AS2::XMLAttributeStringBuilder *this,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASStringNode *v5; // eax

  Scaleform::StringBuffer::AppendString(this->Dest, (char *)&stru_95AF78, 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(this->Dest, *(char **)name->pData, 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(this->Dest, "=\"", 0xFFFFFFFF);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnv, -1, 0);
  Scaleform::StringBuffer::AppendString(this->Dest, (char *)name->pData, 0xFFFFFFFF);
  v5 = name;
  --name->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  Scaleform::StringBuffer::AppendString(this->Dest, "\"", 0xFFFFFFFF);
}
