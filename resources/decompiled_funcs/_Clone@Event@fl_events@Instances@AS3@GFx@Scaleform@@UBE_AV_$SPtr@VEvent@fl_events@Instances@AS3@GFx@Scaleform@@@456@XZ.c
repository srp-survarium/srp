Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  char v5; // cl
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *v10; // eax
  Scaleform::GFx::AS3::Object *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::CheckResult *(__thiscall *GetProperty)(struct Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::Value *v16; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::CheckResult v20; // [esp+49h] [ebp-BDh] BYREF
  Scaleform::GFx::ASString v; // [esp+4Ah] [ebp-BCh] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+4Eh] [ebp-B8h] BYREF
  Scaleform::GFx::AS3::Value targetProp; // [esp+5Eh] [ebp-A8h] BYREF
  Scaleform::GFx::AS3::Value eventPhaseProp; // [esp+6Eh] [ebp-98h] BYREF
  Scaleform::GFx::AS3::Value currentTargetProp; // [esp+7Eh] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Multiname targetPropName; // [esp+8Eh] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Multiname eventPhasePropName; // [esp+A6h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Multiname currentTargetPropName; // [esp+BEh] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+D6h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+106h] [ebp+0h] BYREF

  v.pNode = 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  result->pObject = 0;
  Scaleform::GFx::AS3::Value::Value(params, &this->Type);
  v5 = *((_BYTE *)this + 48);
  params[2].value.VS._1.VBool = (v5 & 2) != 0;
  pObject = this->pTraits.pObject;
  params[1].value.VS._1.VBool = v5 & 1;
  params[1].Flags = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[2].Flags = 1;
  params[2].Bonus.pWeakProxy = 0;
  if ( (pObject->Flags & 0x10) != 0 )
  {
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "type", 4u, 0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&eventPhasePropName, pVM->PublicNamespace.pObject, &name);
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
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "bubbles", 7u, 0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&currentTargetPropName, pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    v8 = v.pNode;
    --v.pNode->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                "cancelable",
                0xAu,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&targetPropName, pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    v9 = v.pNode;
    --v.pNode->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v10 = this->__vftable;
    eventPhaseProp.Flags = 0;
    eventPhaseProp.Bonus.pWeakProxy = 0;
    currentTargetProp.Flags = 0;
    currentTargetProp.Bonus.pWeakProxy = 0;
    targetProp.Flags = 0;
    targetProp.Bonus.pWeakProxy = 0;
    if ( v10->GetProperty(this, &v20, &eventPhasePropName, &eventPhaseProp)->Result )
      Scaleform::GFx::AS3::Value::Assign(params, &eventPhaseProp);
    if ( this->GetProperty(this, &v20, &currentTargetPropName, &currentTargetProp)->Result )
      Scaleform::GFx::AS3::Value::Assign(&params[1], &currentTargetProp);
    if ( this->GetProperty(this, &v20, &targetPropName, &targetProp)->Result )
      Scaleform::GFx::AS3::Value::Assign(&params[2], &targetProp);
    if ( (targetProp.Flags & 0x1F) > 9 )
    {
      if ( (targetProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&targetProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&targetProp);
    }
    if ( (currentTargetProp.Flags & 0x1F) > 9 )
    {
      if ( (currentTargetProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&currentTargetProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&currentTargetProp);
    }
    if ( (eventPhaseProp.Flags & 0x1F) > 9 )
    {
      if ( (eventPhaseProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&eventPhaseProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&eventPhaseProp);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
    Scaleform::GFx::AS3::Multiname::~Multiname(&currentTargetPropName);
    Scaleform::GFx::AS3::Multiname::~Multiname(&eventPhasePropName);
  }
  v11 = this->GetEventClass(this);
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, v11, 3u, params);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&result->pObject[1].4,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->CurrentTarget);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&result->pObject[1].8,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->Target);
  LOBYTE(result->pObject[1].RefCount) ^= (LOBYTE(result->pObject[1].RefCount) ^ *((_BYTE *)this + 48)) & 4;
  LOBYTE(result->pObject[1].RefCount) ^= (LOBYTE(result->pObject[1].RefCount) ^ *((_BYTE *)this + 48)) & 8;
  LOBYTE(result->pObject[1].RefCount) ^= (*((_BYTE *)this + 48) ^ LOBYTE(result->pObject[1].RefCount)) & 0x10;
  result->pObject[1].pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->Phase;
  if ( (this->pTraits.pObject->Flags & 0x10) != 0 )
  {
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "target", 6u, 0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&targetPropName, pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    v12 = v.pNode;
    --v.pNode->RefCount;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                "currentTarget",
                0xDu,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&currentTargetPropName, pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    v13 = v.pNode;
    --v.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                "eventPhase",
                0xAu,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&eventPhasePropName, pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    v14 = v.pNode;
    --v.pNode->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    GetProperty = this->GetProperty;
    targetProp.Flags = 0;
    targetProp.Bonus.pWeakProxy = 0;
    currentTargetProp.Flags = 0;
    currentTargetProp.Bonus.pWeakProxy = 0;
    eventPhaseProp.Flags = 0;
    eventPhaseProp.Bonus.pWeakProxy = 0;
    if ( GetProperty(this, &v20, &targetPropName, &targetProp)->Result && (targetProp.Flags & 0x1F) - 12 <= 3 )
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&result->pObject[1].8,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)targetProp.value.VS._1.VInt);
    if ( this->GetProperty(this, &v20, &currentTargetPropName, &currentTargetProp)->Result
      && (currentTargetProp.Flags & 0x1F) - 12 <= 3 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&result->pObject[1].4,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)currentTargetProp.value.VS._1.VInt);
    }
    if ( this->GetProperty(this, &v20, &eventPhasePropName, &eventPhaseProp)->Result )
    {
      Scaleform::GFx::AS3::Value::ToUInt32Value(&eventPhaseProp, &v20);
      result->pObject[1].pPrev = eventPhaseProp.value.VS._1.VObj;
    }
    if ( (eventPhaseProp.Flags & 0x1F) > 9 )
    {
      if ( (eventPhaseProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&eventPhaseProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&eventPhaseProp);
    }
    if ( (currentTargetProp.Flags & 0x1F) > 9 )
    {
      if ( (currentTargetProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&currentTargetProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&currentTargetProp);
    }
    if ( (targetProp.Flags & 0x1F) > 9 )
    {
      if ( (targetProp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&targetProp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&targetProp);
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&eventPhasePropName);
    Scaleform::GFx::AS3::Multiname::~Multiname(&currentTargetPropName);
    Scaleform::GFx::AS3::Multiname::~Multiname(&targetPropName);
  }
  v16 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 2; i >= 0; --i )
  {
    Flags = v16[-1].Flags;
    --v16;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v16);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v16);
    }
  }
  return result;
}
