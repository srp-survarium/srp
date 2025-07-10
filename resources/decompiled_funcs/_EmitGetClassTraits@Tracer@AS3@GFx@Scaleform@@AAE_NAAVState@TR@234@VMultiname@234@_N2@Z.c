char __thiscall Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::Multiname as3_mn,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *objOnStack,
        bool altered)
{
  Scaleform::GFx::ASString *ClassTraits; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // ebp
  Scaleform::GFx::AS3::Value::V1U *pNode; // esi
  Scaleform::GFx::AS3::Value::V1U v10; // esi
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *Script; // eax
  const Scaleform::GFx::AS3::CallFrame *CF; // edx
  Scaleform::GFx::AS3::Object *v13; // esi
  const Scaleform::GFx::AS3::Value *v14; // eax
  Scaleform::GFx::AS3::Value type; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v16; // [esp+18h] [ebp-10h] BYREF

  ClassTraits = Scaleform::GFx::AS3::FindClassTraits(
                  this->CF->pFile->VMRef,
                  &as3_mn,
                  (Scaleform::GFx::ASStringNode *)this->CF->pFile->AppDomain);
  v7.VInt = (int)ClassTraits;
  if ( !ClassTraits )
  {
    Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
    return 0;
  }
  pNode = (Scaleform::GFx::AS3::Value::V1U *)ClassTraits[25].pNode;
  if ( !pNode )
    goto LABEL_12;
  if ( !pNode[17].VInt )
  {
    if ( (pNode[14].VInt & 0x10) != 0 )
    {
      Script = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetScript((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)ClassTraits[25].pNode);
      CF = this->CF;
      objOnStack = 0;
      v13 = Script;
      if ( Scaleform::GFx::AS3::FindFixedSlot(
             (const Scaleform::GFx::AS3::SlotInfo *)CF->pFile->VMRef,
             Script->pTraits.pObject,
             (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&as3_mn,
             (unsigned int *)&objOnStack,
             Script) )
      {
        type.Bonus.pWeakProxy = 0;
        type.value.VS._1 = v7;
        type.Flags = 73;
        if ( altered )
          type.Flags = 1097;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &type);
        Scaleform::GFx::AS3::Value::Value(&v16, v13);
        Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, v14, 0);
        Scaleform::GFx::AS3::Value::~Value(&v16);
        Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, (unsigned int)objOnStack);
        goto LABEL_18;
      }
    }
LABEL_12:
    Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
    return 0;
  }
  v10 = pNode[17];
  type.Flags = 13;
  type.Bonus.pWeakProxy = 0;
  type.value.VS._1 = v10;
  if ( v10.VInt )
    *(_DWORD *)(v10.VInt + 16) = (*(_DWORD *)(v10.VInt + 16) + 1) & 0x8FBFFFFF;
  if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &type, objOnStack) )
  {
    Scaleform::GFx::AS3::Value::~Value(&type);
    goto LABEL_12;
  }
  if ( altered )
    type.Flags = 1037;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &st->OpStack.Data,
    &type);
LABEL_18:
  Scaleform::GFx::AS3::Value::~Value(&type);
  Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
  return 1;
}
