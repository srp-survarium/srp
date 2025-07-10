Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::ASString *prop_name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  int p_NullStringNode; // ecx
  void *pWeakProxy; // eax
  __int16 Flags; // cx
  Scaleform::GFx::AS3::CheckResult *SlotValueUnsafe; // eax
  bool v12; // al
  Scaleform::GFx::AS3::WeakProxy *v13; // eax
  Scaleform::GFx::AS3::Value nameVal; // [esp+8h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value scope; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+28h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+40h] [ebp-18h] BYREF

  nameVal.Flags = 0;
  pNode = prop_name->pNode;
  memset(&prop, 0, 16);
  p_NullStringNode = (int)&pNode->pManager->NullStringNode;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)pNode;
  if ( pNode == (Scaleform::GFx::ASStringNode *)p_NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)nameVal.Bonus.pWeakProxy;
    nameVal.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  mn.Kind = MN_QName;
  mn.Obj.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, &nameVal);
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0;
  scope.value.VS._1.VInt = (int)this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::FindObjProperty(
    &prop,
    this->pTraits.pObject->pVM,
    &scope,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&mn,
    FindGet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      if ( nameVal.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  Flags = prop.This.Flags;
  v12 = 0;
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
  {
    SlotValueUnsafe = Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
                        &prop,
                        (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                        this->pTraits.pObject->pVM,
                        value,
                        valGet);
    Flags = prop.This.Flags;
    if ( SlotValueUnsafe->Result )
      v12 = 1;
  }
  result->Result = v12;
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v13 = prop.This.Bonus.pWeakProxy;
      --prop.This.Bonus.pWeakProxy->RefCount;
      if ( !v13->RefCount )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
        return result;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
    }
  }
  return result;
}
