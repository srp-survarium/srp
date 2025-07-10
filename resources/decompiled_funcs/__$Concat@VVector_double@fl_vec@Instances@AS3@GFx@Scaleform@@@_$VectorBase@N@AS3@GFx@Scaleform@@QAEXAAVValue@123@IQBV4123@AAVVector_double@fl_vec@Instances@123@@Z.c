void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::VectorBase<double> *v8; // ebx
  const Scaleform::GFx::AS3::Value *v9; // edi
  Scaleform::GFx::AS3::VM *v10; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  bool v12; // zf
  const Scaleform::GFx::AS3::ClassTraits::Traits *v13; // eax
  Scaleform::GFx::AS3::VM *v14; // esi
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v19; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *Data; // eax
  double *v21; // esi
  Scaleform::GFx::AS3::VM *v22; // esi
  const Scaleform::GFx::AS3::VM::Error *v23; // eax
  Scaleform::GFx::AS3::VM *v24; // esi
  const Scaleform::GFx::AS3::VM::Error *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  const Scaleform::GFx::AS3::Value *v27; // [esp+10h] [ebp-28h]
  Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+20h] [ebp-18h]
  const Scaleform::GFx::AS3::Traits *argTraits; // [esp+24h] [ebp-14h]
  double argClassTR; // [esp+28h] [ebp-10h]
  Scaleform::GFx::AS3::VM::Error v34; // [esp+30h] [ebp-8h] BYREF

  VMRef = this->VMRef;
  pObject = currObj->pTraits.pObject;
  vm = VMRef;
  currClassTR = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor(pObject)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&i,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)currObj->pTraits.pObject);
  v7 = i;
  Scaleform::GFx::AS3::Value::Pick(result, (Scaleform::GFx::AS3::Object *)i);
  v8 = (Scaleform::GFx::AS3::VectorBase<double> *)(v7 + 32);
  Scaleform::GFx::AS3::VectorBase<double>::Append(v8, &currObj->V);
  i = 0;
  if ( !argc )
    return;
  v9 = argv;
  v27 = argv;
  while ( 1 )
  {
    v10 = vm;
    argTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, v9);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(v10, v9);
    v12 = (argTraits->Flags & 1) == 0;
    LODWORD(argClassTR) = ClassTraits;
    if ( v12 )
      break;
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(v10->TraitsArray.pObject, ClassTraits) )
    {
      v22 = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v34, eNotImplementedError, v22);
      Scaleform::GFx::AS3::VM::ThrowError(v22, v23);
      goto LABEL_25;
    }
    if ( currClassTR != (Scaleform::GFx::AS3::ClassTraits::Traits *)LODWORD(argClassTR) )
    {
      v24 = this->VMRef;
      goto LABEL_24;
    }
    Scaleform::GFx::AS3::VectorBase<double>::Append(
      v8,
      (const Scaleform::GFx::AS3::VectorBase<double> *)(v9->value.VS._1.VInt + 32));
LABEL_19:
    ++v9;
    ++i;
    v27 = v9;
    if ( i >= argc )
      return;
  }
  v13 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, v9);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(currClassTR, v13) )
  {
    v12 = !v8->Fixed;
    argClassTR = v9->value.VNumber;
    if ( v12 )
      goto LABEL_12;
    v14 = v8->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v34, eVectorFixedError, v14);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v14, v15);
    pNode = v34.Message.pNode;
    --v34.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !v8->Fixed )
    {
LABEL_12:
      pHeap = v8->ValueA.Data.pHeap;
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v8->ValueA;
      v19 = v8->ValueA.Data.Size + 1;
      if ( v19 >= v8->ValueA.Data.Size )
      {
        if ( v19 >= v8->ValueA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v19 + (v19 >> 2));
      }
      else if ( v19 < v8->ValueA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          v8->ValueA.Data.Size + 1);
      }
      Data = p_ValueA->Data;
      v8->ValueA.Data.Size = v19;
      v9 = v27;
      v21 = (double *)&Data[v19 - 1];
      if ( v21 )
        *v21 = argClassTR;
    }
    goto LABEL_19;
  }
  v24 = this->VMRef;
LABEL_24:
  Scaleform::GFx::AS3::VM::Error::Error(&v34, eCheckTypeFailedError, v24);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v24, v25);
LABEL_25:
  v26 = v34.Message.pNode;
  --v34.Message.pNode->RefCount;
  if ( !v26->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
}
