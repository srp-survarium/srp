void __thiscall Scaleform::GFx::AS3::Object::FindProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::PropRef *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        Scaleform::GFx::AS3::FindPropAttr attr)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Traits *v8; // eax
  Scaleform::GFx::AS3::PropRef *v9; // eax
  Scaleform::GFx::AS3::Traits *i; // edi
  Scaleform::GFx::AS3::Object *Prototype; // eax
  unsigned int slot_index; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::PropRef v13; // [esp+10h] [ebp-18h] BYREF

  pObject = this->pTraits.pObject;
  slot_index = 0;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                (const Scaleform::GFx::AS3::SlotInfo *)pObject->pVM,
                pObject,
                mn,
                &slot_index,
                this);
  if ( FixedSlot )
  {
    v7 = slot_index;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    result->SlotIndex = v7;
    v13.SlotIndex = v7;
    result->pSI = FixedSlot;
    v13.pSI = FixedSlot;
    v13.This.Flags = 12;
    v13.This.Bonus.pWeakProxy = 0;
    v13.This.value.VS._1.VInt = (int)this;
    Scaleform::GFx::AS3::Value::Assign(&result->This, &v13.This);
    Scaleform::GFx::AS3::PropRef::~PropRef(&v13);
  }
  else
  {
    v8 = this->pTraits.pObject;
    if ( (v8->Flags & 2) != 0 && (attr != FindCall || v8->TraitsType != Traits_XML || (v8->Flags & 0x20) != 0) )
    {
      v9 = this->FindDynamicSlot(this, &v13, mn);
      result->pSI = v9->pSI;
      result->pSI = v9->pSI;
      result->pSI = v9->pSI;
      result->SlotIndex = v9->SlotIndex;
      Scaleform::GFx::AS3::Value::Assign(&result->This, &v9->This);
      Scaleform::GFx::AS3::PropRef::~PropRef(&v13);
    }
    if ( ((result->This.Flags & 0x1F) == 0
       || ((int)result->pSI & 1) != 0 && ((int)result->pSI & 0xFFFFFFFE) == 0
       || ((int)result->pSI & 2) != 0 && ((int)result->pSI & 0xFFFFFFFD) == 0)
      && attr != FindSet )
    {
      for ( i = this->pTraits.pObject; i; i = (Scaleform::GFx::AS3::Traits *)i->pParent.pObject )
      {
        if ( !i->pConstructor.pObject )
          i->InitOnDemand(i);
        Prototype = Scaleform::GFx::AS3::Class::GetPrototype(i->pConstructor.pObject, (int)i);
        if ( Prototype == this )
          break;
        Scaleform::GFx::AS3::Object::FindProperty(Prototype, result, (const Scaleform::GFx::AS3::Multiname *)mn, attr);
        if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
          break;
      }
    }
  }
}
