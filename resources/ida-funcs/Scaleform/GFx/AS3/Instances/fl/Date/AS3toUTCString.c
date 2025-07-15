void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3toUTCString(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int v3; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  char out[128]; // [esp+20h] [ebp-80h] BYREF

  v3 = Scaleform::GFx::AS3::Instances::fl::Date::formatDateTimeString(out, 0x80u, this->TimeValue, 0, 1, 1, 1);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (__m128i *)out,
                 v3);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v6 = StringNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
