void __thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  const char *(__thiscall *GetEventName)(struct Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *); // edx
  char *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::CheckResult v14; // [esp+13h] [ebp-79h] BYREF
  Scaleform::GFx::ASString v15; // [esp+14h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::Event *v16; // [esp+18h] [ebp-74h]
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-70h] BYREF
  Scaleform::GFx::AS3::Value params[6]; // [esp+2Ch] [ebp-60h] BYREF
  _UNKNOWN *retaddr; // [esp+8Ch] [ebp+0h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  GetEventName = this->GetEventName;
  v16 = this;
  v4 = (char *)((int (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *))GetEventName)(this);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                v4,
                strlen(v4),
                0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(params, &v15);
  pNode = v15.pNode;
  --v15.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "type", 4u, 0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[1], &v15);
  v6 = v15.pNode;
  --v15.pNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "bubbles", 7u, 0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[2], &v15);
  v7 = v15.pNode;
  --v15.pNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                "cancelable",
                0xAu,
                0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[3], &v15);
  v8 = v15.pNode;
  --v15.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "info", 4u, 0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[4], &v15);
  v9 = v15.pNode;
  --v15.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v15.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "target", 6u, 0);
  ++v15.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&params[5], &v15);
  v10 = v15.pNode;
  --v15.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(v16, &v, 6u, params);
  Scaleform::GFx::AS3::Value::Convert2String(&v, &v14, result);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  v11 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 5; i >= 0; --i )
  {
    Flags = v11[-1].Flags;
    --v11;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
    }
  }
}
