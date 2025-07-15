void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3toDateString(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::ASString *result)
{
  int LocalTZA; // eax
  unsigned int v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  char out[128]; // [esp+20h] [ebp-80h] BYREF

  LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
  v4 = Scaleform::GFx::AS3::Instances::fl::Date::formatDateTimeString(out, 0x80u, this->TimeValue, LocalTZA, 1, 0, 0);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (__m128i *)out,
                 v4);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v7 = StringNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
