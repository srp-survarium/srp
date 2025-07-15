void __thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v4; // zf

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)((this->Pattern.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(this->Pattern.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v4 = result->pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v4 = StringNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(this, result);
  return result;
}
