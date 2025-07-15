void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3localName(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v6, "localName")->Result )
  {
    pNode = this->List.Data.Data->pObject->Text.pNode;
    ++pNode->RefCount;
    v4 = result->pNode;
    if ( result->pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    result->pNode = pNode;
  }
}
