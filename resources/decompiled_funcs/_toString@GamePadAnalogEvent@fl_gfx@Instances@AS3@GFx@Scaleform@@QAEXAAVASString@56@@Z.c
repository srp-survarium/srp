void __thiscall Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *this,
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
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-A8h] BYREF
  Scaleform::GFx::AS3::CheckResult v18; // [esp+17h] [ebp-A1h] BYREF
  Scaleform::GFx::AS3::Value res; // [esp+18h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value params[9]; // [esp+28h] [ebp-90h] BYREF
  _UNKNOWN *retaddr; // [esp+B8h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  res.Flags = 0;
  res.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "GamePadAnalogEvent",
              0x12u,
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
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "code", 4u, 0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[5], &v);
  v10 = v.pNode;
  --v.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "controllerIdx",
              0xDu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[6], &v);
  v11 = v.pNode;
  --v.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "xvalue",
              6u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[7], &v);
  v12 = v.pNode;
  --v.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "yvalue",
              6u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[8], &v);
  v13 = v.pNode;
  --v.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &res, 9u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&res, &v18, result);
  v14 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 8; i >= 0; --i )
  {
    Flags = v14[-1].Flags;
    --v14;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v14);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v14);
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
