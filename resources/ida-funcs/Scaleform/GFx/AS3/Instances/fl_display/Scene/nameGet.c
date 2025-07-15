void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Scene::nameGet(
        Scaleform::GFx::AS3::Instances::fl_display::Scene *this,
        Scaleform::GFx::ASString *result)
{
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v5; // zf
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi

  SceneInfo = this->SceneInfo;
  if ( SceneInfo )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   result->pNode->pManager,
                   (char *)((SceneInfo->Name.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(SceneInfo->Name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode->RefCount;
    pNode = result->pNode;
    v5 = result->pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = StringNode;
  }
  else
  {
    pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
    pStringManager->EmptyStringNode.RefCount += 2;
    v7 = result->pNode;
    p_EmptyStringNode = &pStringManager->EmptyStringNode;
    v5 = result->pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    result->pNode = p_EmptyStringNode;
    v5 = p_EmptyStringNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  }
}
