void __thiscall Scaleform::GFx::AS3::Classes::fl::Date::parse(
        Scaleform::GFx::AS3::Classes::fl::Date *this,
        long double *result,
        Scaleform::GFx::AS3::Value *s)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString str; // [esp+0h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl::Date::Parser parsedDate; // [esp+4h] [ebp-28h] BYREF

  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(s, (Scaleform::GFx::AS3::CheckResult *)&s, &str)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::Date::Parser::Parser(&parsedDate, (int)str.pNode->pData);
    *result = Scaleform::GFx::AS3::Instances::fl::Date::Parser::MakeDate(&parsedDate, 0);
  }
  pNode = str.pNode;
  --str.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
