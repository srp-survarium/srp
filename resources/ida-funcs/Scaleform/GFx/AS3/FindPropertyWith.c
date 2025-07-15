void __cdecl Scaleform::GFx::AS3::FindPropertyWith(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *scope,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        Scaleform::GFx::AS3::FindPropAttr attr)
{
  Scaleform::GFx::AS3::Value *v5; // ebp
  bool v6; // bl
  Scaleform::GFx::AS3::Traits *ValueTraits; // esi
  Scaleform::GFx::AS3::Object *VObj; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  int v10; // eax
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v11; // ebx
  const Scaleform::GFx::AS3::PropRef *v12; // eax
  Scaleform::GFx::AS3::Object *Prototype; // eax
  const Scaleform::GFx::AS3::PropRef *v14; // eax
  Scaleform::GFx::AS3::PropRef r; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::PropRef v16; // [esp+28h] [ebp-18h] BYREF

  v5 = scope;
  v6 = (scope->Flags & 0x1F) - 12 <= 2;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  VObj = 0;
  scope = 0;
  if ( v6 )
    VObj = v5->value.VS._1.VObj;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                (const Scaleform::GFx::AS3::SlotInfo *)vm,
                ValueTraits,
                mn,
                (unsigned int *)&scope,
                VObj);
  if ( FixedSlot )
  {
    Scaleform::GFx::AS3::PropRef::PropRef(&r, v5, FixedSlot, (unsigned int)scope);
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v10;
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v10;
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v10;
    result->SlotIndex = *(_DWORD *)(v10 + 4);
    Scaleform::GFx::AS3::Value::Assign(&result->This, (const Scaleform::GFx::AS3::Value *)(v10 + 8));
    Scaleform::GFx::AS3::PropRef::~PropRef(&r);
  }
  else if ( ValueTraits->IsGlobal(ValueTraits) || (v5->Flags & 0x100) != 0 )
  {
    if ( !v6 || (ValueTraits->Flags & 2) == 0 || attr == FindCall && Scaleform::GFx::AS3::IsXMLObject(v5) )
    {
      v11 = mn;
    }
    else
    {
      v11 = mn;
      v12 = (const Scaleform::GFx::AS3::PropRef *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::PropRef *, const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *))(*(_DWORD *)v5->value.VS._1.VInt + 72))(
                                                    v5->value.VS._1,
                                                    &r,
                                                    mn);
      Scaleform::GFx::AS3::PropRef::operator=(result, v12);
      Scaleform::GFx::AS3::PropRef::~PropRef(&r);
    }
    if ( ((result->This.Flags & 0x1F) == 0
       || ((int)result->pSI & 1) != 0 && ((int)result->pSI & 0xFFFFFFFE) == 0
       || ((int)result->pSI & 2) != 0 && ((int)result->pSI & 0xFFFFFFFD) == 0)
      && attr != FindSet )
    {
      memset(&r, 0, 16);
      while ( 1 )
      {
        if ( !ValueTraits->pConstructor.pObject )
          ValueTraits->InitOnDemand(ValueTraits);
        Prototype = Scaleform::GFx::AS3::Class::GetPrototype(ValueTraits->pConstructor.pObject, (int)result);
        Scaleform::GFx::AS3::Object::FindProperty(Prototype, &r, v11, attr);
        if ( (r.This.Flags & 0x1F) != 0
          && (((int)r.pSI & 1) == 0 || ((int)r.pSI & 0xFFFFFFFE) != 0)
          && (((int)r.pSI & 2) == 0 || ((int)r.pSI & 0xFFFFFFFD) != 0) )
        {
          break;
        }
        ValueTraits = ValueTraits->pParent.pObject;
        if ( !ValueTraits )
          goto LABEL_30;
      }
      Scaleform::GFx::AS3::PropRef::PropRef(&v16, v5, 0, 0);
      Scaleform::GFx::AS3::PropRef::operator=(result, v14);
      Scaleform::GFx::AS3::PropRef::~PropRef(&v16);
LABEL_30:
      Scaleform::GFx::AS3::PropRef::~PropRef(&r);
      if ( !Scaleform::GFx::AS3::PropRef::operator bool(result) && (v5->Flags & 0x1F) == 0xE )
        Scaleform::GFx::AS3::FindScopeProperty(
          result,
          vm,
          0,
          (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(v5->value.VS._1.VInt
                                                                                                 + 36),
          (const Scaleform::GFx::AS3::Multiname *)v11);
    }
  }
}
