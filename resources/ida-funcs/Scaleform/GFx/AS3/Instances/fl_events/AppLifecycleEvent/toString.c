void __thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS3::Value *v10; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::Value res; // [esp+14h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value params[5]; // [esp+24h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+74h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  res.Flags = 0;
  res.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "AppLifecycleEvent",
              0x11u,
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
              "status",
              6u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[4], &v);
  v9 = v.pNode;
  --v.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &res, 5u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&res, (Scaleform::GFx::AS3::CheckResult *)&result, result);
  v10 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 4; i >= 0; --i )
  {
    Flags = v10[-1].Flags;
    --v10;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v10);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v10);
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
