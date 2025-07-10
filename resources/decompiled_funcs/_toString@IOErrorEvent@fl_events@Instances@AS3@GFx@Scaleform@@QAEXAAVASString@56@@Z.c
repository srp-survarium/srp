void __thiscall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value res; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value params[4]; // [esp+24h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+64h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  res.Flags = 0;
  res.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "IOErrorEvent",
              0xCu,
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
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "text", 4u, 0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[3], &v);
  v8 = v.pNode;
  --v.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &res, 4u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&res, (Scaleform::GFx::AS3::CheckResult *)&result, result);
  v9 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 3; i >= 0; --i )
  {
    Flags = v9[-1].Flags;
    --v9;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v9);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v9);
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
