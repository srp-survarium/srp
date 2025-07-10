void __thiscall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *prop_name,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-4h] BYREF

  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  name.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(prop_name, (Scaleform::GFx::AS3::CheckResult *)&prop_name, &name)->Result )
    Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(this, &name, v, a);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
