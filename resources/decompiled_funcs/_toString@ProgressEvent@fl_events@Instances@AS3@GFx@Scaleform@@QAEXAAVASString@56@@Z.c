void __thiscall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::CheckResult v16; // [esp+17h] [ebp-81h] BYREF
  Scaleform::GFx::AS3::Value res; // [esp+18h] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value params[7]; // [esp+28h] [ebp-70h] BYREF
  _UNKNOWN *retaddr; // [esp+98h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  res.Flags = 0;
  res.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "ProgressEvent",
              0xDu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(params, &v);
  pNode = v.pNode;
  --v.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "type", 4u, 0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[1], &v);
  v6 = v.pNode;
  --v.pNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "bubbles",
              7u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[2], &v);
  v7 = v.pNode;
  --v.pNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "cancelable",
              0xAu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[3], &v);
  v8 = v.pNode;
  --v.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "eventPhase",
              0xAu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[4], &v);
  v9 = v.pNode;
  --v.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "bytesLoaded",
              0xBu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[5], &v);
  v10 = v.pNode;
  --v.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "bytesTotal",
              0xAu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[6], &v);
  v11 = v.pNode;
  --v.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &res, 7u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&res, &v16, result);
  v12 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 6; i >= 0; --i )
  {
    Flags = v12[-1].Flags;
    --v12;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v12);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
    }
  }
  if ( (res.Flags & 0x1F) > 9 )
  {
    if ( (res.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&res);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&res);
  }
}
