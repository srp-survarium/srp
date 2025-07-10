void __thiscall Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(
        Scaleform::GFx::MovieImpl::ReturnValueHolder *this,
        Scaleform::GFx::ASStringManager *pmgr)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  bool v4; // zf

  this->CharBuffer = 0;
  this->CharBufferSize = 0;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pmgr, (const char *)&buf, 0, 0);
  ++ConstStringNode->RefCount;
  this->StringArray.Data.Data = 0;
  this->StringArray.Data.Size = 0;
  this->StringArray.Data.Policy.Capacity = 0;
  this->StringArray.Data.DefaultValue.pNode = ConstStringNode;
  v4 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  this->StringArrayPos = 0;
}
