void __thiscall Scaleform::GFx::AS2::XMLPrefixQuerier::Visit(
        Scaleform::GFx::AS2::XMLPrefixQuerier *this,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::ASStringNode *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::AS2::Value *pVal; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // eax

  Scaleform::GFx::AS2::Value::ToStringImpl(
    (Scaleform::GFx::AS2::Value *)val,
    (Scaleform::GFx::ASString *)&val,
    this->pEnv,
    -1,
    0);
  if ( val == this->pKey->pNode && !strncmp(name->pNode->pData, "xmlns", 5u) )
  {
    pVal = this->pVal;
    if ( pVal->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pVal);
    pVal->T.Type = 5;
    pNode = name->pNode;
    pVal->NV.Int32Value = (int)name->pNode;
    ++pNode->RefCount;
  }
  v7 = val;
  --val->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
