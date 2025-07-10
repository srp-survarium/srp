void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *pV; // edi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *p_V; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v18; // esi
  const Scaleform::GFx::AS3::Value **v19; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  Scaleform::GFx::AS3::VM *v22; // esi
  const Scaleform::GFx::AS3::VM::Error *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-Ch]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> r; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [esp+18h] [ebp-4h]
  unsigned int i; // [esp+20h] [ebp+4h]
  const Scaleform::GFx::AS3::Value *argva; // [esp+28h] [ebp+Ch]
  Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+2Ch] [ebp+10h]

  vm = this->VMRef;
  currClassTR = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)currObj->FirstOwnSlotNum)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    &r,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->FirstOwnSlotNum);
  pV = r.pV;
  Scaleform::GFx::AS3::Value::Pick(result, r.pV);
  p_V = (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&pV->V;
  Scaleform::GFx::AS3::VectorBase<long>::Append(
    (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&pV->V,
    (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)&currObj->VArray.Data.Size);
  i = 0;
  if ( !argc )
    return;
  while ( 1 )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, argv);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(vm, argv);
    v11 = ClassTraits;
    if ( (ValueTraits->Flags & 1) == 0 )
      break;
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(vm->TraitsArray.pObject, ClassTraits) )
    {
      VMRef = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eNotImplementedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowError(VMRef, v21);
      goto LABEL_24;
    }
    if ( currClassTR != v11 )
    {
      v22 = this->VMRef;
      goto LABEL_23;
    }
    Scaleform::GFx::AS3::VectorBase<long>::Append(
      p_V,
      (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)(argv->value.VS._1.VInt + 32));
LABEL_18:
    ++argv;
    if ( ++i >= argc )
      return;
  }
  v12 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, argv);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(currClassTR, v12) )
  {
    argva = (const Scaleform::GFx::AS3::Value *)argv->value.VS._1.VInt;
    if ( !p_V->Fixed )
      goto LABEL_11;
    v13 = p_V->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eVectorFixedError, v13);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v13, v14);
    v15 = v28;
    --v28->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    if ( !p_V->Fixed )
    {
LABEL_11:
      pHeap = p_V->ValueA.Data.pHeap;
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&p_V->ValueA;
      v18 = p_V->ValueA.Data.Size + 1;
      if ( v18 >= p_V->ValueA.Data.Size )
      {
        if ( v18 >= p_V->ValueA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v18 + (v18 >> 2));
      }
      else if ( v18 < p_V->ValueA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          p_V->ValueA.Data.Size + 1);
      }
      v19 = (const Scaleform::GFx::AS3::Value **)&p_ValueA->Data[v18 - 1];
      p_V->ValueA.Data.Size = v18;
      if ( v19 )
        *v19 = argva;
    }
    goto LABEL_18;
  }
  v22 = this->VMRef;
LABEL_23:
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eCheckTypeFailedError, v22);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v22, v23);
LABEL_24:
  v24 = v28;
  --v28->RefCount;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
}
