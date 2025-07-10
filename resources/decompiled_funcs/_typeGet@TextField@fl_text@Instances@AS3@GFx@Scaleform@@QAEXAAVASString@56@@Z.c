void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::typeGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result)
{
  char Only; // al
  char *v4; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf

  Only = Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj.pObject);
  v4 = "dynamic";
  if ( !Only )
    v4 = "input";
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      v4,
                      strlen(v4),
                      0);
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = ConstStringNode;
  v7 = ConstStringNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
