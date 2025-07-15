void __thiscall Scaleform::GFx::AS3::Classes::fl::String::Construct(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString r; // [esp+0h] [ebp-4h] BYREF

  r.pNode = (Scaleform::GFx::ASStringNode *)this;
  r.pNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++r.pNode->RefCount;
  if ( !argc || Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &r)->Result )
    Scaleform::GFx::AS3::Value::Assign(result, &r);
  pNode = r.pNode;
  --r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
