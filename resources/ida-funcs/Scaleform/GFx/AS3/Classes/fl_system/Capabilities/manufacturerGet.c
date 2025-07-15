void __thiscall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::manufacturerGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASStringNode *result)
{
  Scaleform::GFx::ASString *v2; // edi
  Scaleform::GFx::ASStringNode *v4; // eax

  v2 = (Scaleform::GFx::ASString *)result;
  Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)result, (Scaleform::GFx::ASStringNode *)"Scaleform ");
  result = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++result->RefCount;
  Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&result, (Scaleform::GFx::ASStringNode *)"Windows");
  Scaleform::GFx::ASString::Append(v2, (Scaleform::GFx::ASStringNode *)&result);
  v4 = result;
  --result->RefCount;
  if ( !v4->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}
