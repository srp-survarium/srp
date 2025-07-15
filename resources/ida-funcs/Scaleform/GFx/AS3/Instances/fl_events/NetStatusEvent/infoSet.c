void __thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoSet(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::AS3::Value::V1U pLower; // ebp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  unsigned int v10; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v11; // ecx
  Scaleform::GFx::AS3::Value prop; // [esp+18h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Multiname mnLevel; // [esp+38h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mnCode; // [esp+50h] [ebp-18h] BYREF

  pLower = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  value = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, (__m128i *)"code");
  ++value->RefCount;
  Scaleform::GFx::AS3::Value::Value(&name, (const Scaleform::GFx::ASString *)&value);
  Scaleform::GFx::AS3::Multiname::Multiname(&mnCode, this->pTraits.pObject->pVM->PublicNamespace.pObject, &name);
  if ( (name.Flags & 0x1F) > 9 )
  {
    if ( (name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
  }
  v6 = value;
  --value->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  value = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, (__m128i *)"level");
  ++value->RefCount;
  Scaleform::GFx::AS3::Value::Value(&name, (const Scaleform::GFx::ASString *)&value);
  Scaleform::GFx::AS3::Multiname::Multiname(&mnLevel, this->pTraits.pObject->pVM->PublicNamespace.pObject, &name);
  if ( (name.Flags & 0x1F) > 9 )
  {
    if ( (name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
  }
  v7 = value;
  --value->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  prop.Flags = 0;
  prop.Bonus.pWeakProxy = 0;
  if ( *(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)pLower.VInt + 28))(
                   pLower,
                   &value,
                   &mnCode,
                   &prop) )
    Scaleform::GFx::AS3::Value::Convert2String(&prop, (Scaleform::GFx::AS3::CheckResult *)&value, &this->Code);
  if ( *(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)pLower.VInt + 28))(
                   pLower,
                   &value,
                   &mnLevel,
                   &prop) )
    Scaleform::GFx::AS3::Value::Convert2String(&prop, (Scaleform::GFx::AS3::CheckResult *)&value, &this->Level);
  if ( (prop.Flags & 0x1F) > 9 )
  {
    if ( (prop.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop);
  }
  if ( (mnLevel.Name.Flags & 0x1F) > 9 )
  {
    if ( (mnLevel.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mnLevel.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mnLevel.Name);
  }
  if ( mnLevel.Obj.pObject )
  {
    if ( ((int)mnLevel.Obj.pObject & 1) != 0 )
    {
      --mnLevel.Obj.pObject;
    }
    else
    {
      RefCount = mnLevel.Obj.pObject->RefCount;
      pObject = mnLevel.Obj.pObject;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mnLevel.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (mnCode.Name.Flags & 0x1F) > 9 )
  {
    if ( (mnCode.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mnCode.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mnCode.Name);
  }
  if ( mnCode.Obj.pObject && ((int)mnCode.Obj.pObject & 1) == 0 )
  {
    v10 = mnCode.Obj.pObject->RefCount;
    v11 = mnCode.Obj.pObject;
    if ( (v10 & 0x3FFFFF) != 0 )
    {
      mnCode.Obj.pObject->RefCount = v10 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
    }
  }
}
