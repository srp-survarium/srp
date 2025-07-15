char __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::NeedsCloning(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *(__thiscall *GetProperty)(struct Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *); // edx
  bool v6; // bl
  char v7; // [esp+Bh] [ebp-3Dh] BYREF
  Scaleform::GFx::ASString v; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value targetProp; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname targetPropName; // [esp+30h] [ebp-18h] BYREF

  v.pNode = 0;
  if ( (*((_BYTE *)this + 48) & 0x20) != 0 )
    return 1;
  pObject = this->pTraits.pObject;
  if ( (pObject->Flags & 0x10) == 0 )
    return 0;
  v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              pObject->pVM->StringManagerRef->pStringManager,
              "target",
              6u,
              0);
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&name, &v);
  Scaleform::GFx::AS3::Multiname::Multiname(&targetPropName, this->pTraits.pObject->pVM->PublicNamespace.pObject, &name);
  if ( (name.Flags & 0x1F) > 9 )
  {
    if ( (name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
  }
  pNode = v.pNode;
  --v.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  GetProperty = this->GetProperty;
  targetProp.Flags = 0;
  targetProp.Bonus.pWeakProxy = 0;
  if ( !GetProperty(this, (Scaleform::GFx::AS3::CheckResult *)&v7, &targetPropName, &targetProp)->Result
    || (targetProp.Flags & 0x1F) - 12 > 3 )
  {
    if ( (targetProp.Flags & 0x1F) > 9 )
    {
      if ( (targetProp.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&targetProp);
        Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
        return 0;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&targetProp);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
    return 0;
  }
  v6 = this->Target.pObject != targetProp.value.VS._1.VFunct;
  if ( (targetProp.Flags & 0x1F) > 9 )
  {
    if ( (targetProp.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&targetProp);
      Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
      return v6;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&targetProp);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
  return v6;
}
