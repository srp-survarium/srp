void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::phaseGet(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::PhaseType Phase; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v5; // zf
  Scaleform::GFx::ASStringManager *pManager; // esi
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi

  Phase = this->Phase;
  if ( phases[Phase] )
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                        (char *)phases[Phase],
                        strlen(phases[Phase]),
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
  else
  {
    pManager = result->pNode->pManager;
    ++pManager->NullStringNode.RefCount;
    v7 = result->pNode;
    p_NullStringNode = &pManager->NullStringNode;
    v5 = result->pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    result->pNode = p_NullStringNode;
  }
}
