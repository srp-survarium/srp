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


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pV; // edi
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
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> r; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [esp+18h] [ebp-4h]
  unsigned int i; // [esp+20h] [ebp+4h]
  const Scaleform::GFx::AS3::Value *argva; // [esp+28h] [ebp+Ch]
  Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+2Ch] [ebp+10h]

  vm = this->VMRef;
  currClassTR = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)currObj->FirstOwnSlotNum)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    &r,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->FirstOwnSlotNum);
  pV = r.pV;
  Scaleform::GFx::AS3::Value::Pick(result, r.pV);
  p_V = &pV->V;
  Scaleform::GFx::AS3::VectorBase<long>::Append(
    &pV->V,
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
