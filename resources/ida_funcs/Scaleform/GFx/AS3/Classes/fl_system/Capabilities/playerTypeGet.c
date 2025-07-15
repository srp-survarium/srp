void __thiscall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::playerTypeGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v4; // zf

  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      "StandAlone",
                      0xAu,
                      0);
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v4 = result->pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = ConstStringNode;
  v4 = ConstStringNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
