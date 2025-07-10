void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::endianGet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::ASString *result)
{
  bool v2; // zf
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = (*((_BYTE *)this + 32) & 0x18) == 0;
  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  if ( v2 )
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "bigEndian", 9u, 0);
  else
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "littleEndian", 0xCu, 0);
  v5 = ConstStringNode;
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v2 = result->pNode->RefCount-- == 1;
  if ( v2 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = v5;
  v2 = v5->RefCount-- == 1;
  if ( v2 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
