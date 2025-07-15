void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::antiAliasTypeGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result)
{
  char *v2; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v5; // zf

  v2 = "advanced";
  if ( (BYTE1(this->pDispObj.pObject[1].pRenNode.pObject[9].pNative) & 0x40) == 0 )
    v2 = "normal";
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      v2,
                      strlen(v2),
                      0);
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v5 = result->pNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = ConstStringNode;
  v5 = ConstStringNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
