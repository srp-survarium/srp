void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *currObj)
{
  Scaleform::GFx::AS3::VM *VMRef; // ebx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pV; // edi
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *p_V; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // ebx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS3::VM *v16; // esi
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::AS3::VM *v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-Ch]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> r; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [esp+18h] [ebp-4h]
  unsigned int i; // [esp+20h] [ebp+4h]
  Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+2Ch] [ebp+10h]

  VMRef = this->VMRef;
  vm = VMRef;
  currClassTR = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)currObj->FirstOwnSlotNum)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
    &r,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)currObj->FirstOwnSlotNum);
  pV = r.pV;
  Scaleform::GFx::AS3::Value::Pick(result, r.pV);
  p_V = &pV->V;
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
    p_V,
    (const Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *)&currObj->VArray.Data.Size);
  i = 0;
  if ( !argc )
    return;
  while ( 1 )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, argv);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(VMRef, argv);
    if ( (ValueTraits->Flags & 1) == 0 )
      break;
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(vm->TraitsArray.pObject, ClassTraits) )
    {
      v16 = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eNotImplementedError, v16);
      Scaleform::GFx::AS3::VM::ThrowError(v16, v17);
      goto LABEL_20;
    }
    if ( currClassTR != ClassTraits )
    {
      v18 = this->VMRef;
      goto LABEL_19;
    }
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Append(
      p_V,
      (const Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *)(argv->value.VS._1.VInt + 32));
LABEL_14:
    ++argv;
    if ( ++i >= argc )
      return;
    VMRef = vm;
  }
  v12 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, argv);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(currClassTR, v12) )
  {
    if ( !p_V->Fixed )
      goto LABEL_13;
    v13 = p_V->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eVectorFixedError, v13);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v13, v14);
    v15 = v24;
    --v24->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    if ( !p_V->Fixed )
LABEL_13:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &p_V->ValueA.Data,
        argv);
    goto LABEL_14;
  }
  v18 = this->VMRef;
LABEL_19:
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eCheckTypeFailedError, v18);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v18, v19);
LABEL_20:
  v20 = v24;
  --v24->RefCount;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
}
