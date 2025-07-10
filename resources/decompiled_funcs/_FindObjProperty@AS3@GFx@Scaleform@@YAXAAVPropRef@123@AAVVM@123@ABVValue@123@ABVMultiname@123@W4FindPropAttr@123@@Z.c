void __cdecl Scaleform::GFx::AS3::FindObjProperty(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *scope,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        Scaleform::GFx::AS3::FindPropAttr attr)
{
  bool v5; // bl
  const Scaleform::GFx::AS3::Traits *ValueTraits; // ecx
  Scaleform::GFx::AS3::Object *VObj; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  Scaleform::GFx::AS3::GASRefCountBase *Size; // ecx
  const Scaleform::GFx::AS3::PropRef *v12; // eax
  const Scaleform::GFx::AS3::Traits *i; // esi
  Scaleform::GFx::AS3::Object *Prototype; // eax
  unsigned int slot_index; // [esp+10h] [ebp-20h] BYREF
  const Scaleform::GFx::AS3::Traits *t; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::AS3::PropRef v17; // [esp+18h] [ebp-18h] BYREF

  v5 = (scope->Flags & 0x1F) - 12 <= 2;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  VObj = 0;
  t = ValueTraits;
  slot_index = 0;
  if ( v5 )
    VObj = scope->value.VS._1.VObj;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                (const Scaleform::GFx::AS3::SlotInfo *)vm,
                ValueTraits,
                mn,
                &slot_index,
                VObj);
  if ( FixedSlot )
  {
    Scaleform::GFx::AS3::PropRef::PropRef(&v17, scope, FixedSlot, slot_index);
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v9;
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v9;
    result->pSI = *(const Scaleform::GFx::AS3::SlotInfo **)v9;
    result->SlotIndex = *(_DWORD *)(v9 + 4);
    Scaleform::GFx::AS3::Value::Assign(&result->This, (const Scaleform::GFx::AS3::Value *)(v9 + 8));
    Scaleform::GFx::AS3::PropRef::~PropRef(&v17);
    return;
  }
  pObject = vm->PublicNamespace.pObject;
  Size = (Scaleform::GFx::AS3::GASRefCountBase *)mn->Data.Size;
  if ( ((int)mn->Data.Data & 3) == 2 )
  {
    if ( !Scaleform::GFx::AS3::NamespaceSet::Contains(
            (Scaleform::GFx::AS3::NamespaceSet *)Size,
            vm->PublicNamespace.pObject) )
      return;
  }
  else if ( Size[1].pNext != (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pObject->Uri.pNode
         || ((*((_BYTE *)pObject + 20) ^ LOBYTE(Size[1].__vftable)) & 0xF) != 0 )
  {
    return;
  }
  if ( v5 && (t->Flags & 2) != 0 && (attr != FindCall || !Scaleform::GFx::AS3::IsXMLObject(scope)) )
  {
    v12 = (const Scaleform::GFx::AS3::PropRef *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::PropRef *, const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *))(*(_DWORD *)scope->value.VS._1.VInt + 60))(
                                                  scope->value.VS._1,
                                                  &v17,
                                                  mn);
    Scaleform::GFx::AS3::PropRef::operator=(result, v12);
    Scaleform::GFx::AS3::PropRef::~PropRef(&v17);
  }
  if ( ((result->This.Flags & 0x1F) == 0
     || ((int)result->pSI & 1) != 0 && ((int)result->pSI & 0xFFFFFFFE) == 0
     || ((int)result->pSI & 2) != 0 && ((int)result->pSI & 0xFFFFFFFD) == 0)
    && attr != FindSet )
  {
    for ( i = t; i; i = i->pParent.pObject )
    {
      if ( !i->pConstructor.pObject )
        i->InitOnDemand((Scaleform::GFx::AS3::Traits *)i);
      Prototype = Scaleform::GFx::AS3::Class::GetPrototype(i->pConstructor.pObject, (int)result);
      Scaleform::GFx::AS3::Object::FindProperty(Prototype, result, mn, attr);
      if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
        break;
    }
    if ( !Scaleform::GFx::AS3::PropRef::operator bool(result) && (scope->Flags & 0x1F) == 0xE )
      Scaleform::GFx::AS3::FindScopeProperty(
        result,
        vm,
        0,
        (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(scope->value.VS._1.VInt
                                                                                               + 36),
        (const Scaleform::GFx::AS3::Multiname *)mn);
  }
}
