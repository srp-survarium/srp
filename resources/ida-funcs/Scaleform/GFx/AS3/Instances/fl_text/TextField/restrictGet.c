void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::restrictGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result)
{
  const Scaleform::String *Restrict; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  Scaleform::GFx::ASStringManager *pManager; // esi
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi

  Restrict = Scaleform::GFx::TextField::GetRestrict((Scaleform::GFx::TextField *)this->pDispObj.pObject);
  if ( Restrict )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (__m128i *)((Restrict->HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(Restrict->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
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
  else
  {
    pManager = result->pNode->pManager;
    ++pManager->NullStringNode.RefCount;
    v8 = result->pNode;
    p_NullStringNode = &pManager->NullStringNode;
    v6 = result->pNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    result->pNode = p_NullStringNode;
  }
}
