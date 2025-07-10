void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::toString(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *v3; // edx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const char *(__thiscall *GetEventName)(Scaleform::GFx::AS3::Instances::fl_events::Event *); // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  char *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Value *v13; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::Event *v17; // [esp+14h] [ebp-64h]
  Scaleform::GFx::AS3::Value res; // [esp+18h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value params[5]; // [esp+28h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+78h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  v3 = this->__vftable;
  res.Flags = 0;
  res.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  GetEventName = v3->GetEventName;
  StringManagerRef = pVM->StringManagerRef;
  v17 = this;
  v7 = (char *)((int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *))GetEventName)(this);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, v7, strlen(v7), 0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(params, &v);
  pNode = v.pNode;
  --v.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "type", 4u, 0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[1], &v);
  v9 = v.pNode;
  --v.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "bubbles",
              7u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[2], &v);
  v10 = v.pNode;
  --v.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "cancelable",
              0xAu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[3], &v);
  v11 = v.pNode;
  --v.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pVM->StringManagerRef->pStringManager,
              "eventPhase",
              0xAu,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[4], &v);
  v12 = v.pNode;
  --v.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(v17, &res, 5u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&res, (Scaleform::GFx::AS3::CheckResult *)&result, result);
  v13 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 4; i >= 0; --i )
  {
    Flags = v13[-1].Flags;
    --v13;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v13);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
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
