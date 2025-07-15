void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v5; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v6; // edi
  Scaleform::GFx::AS3::VectorBase<double> *p_V; // ebx
  const Scaleform::GFx::AS3::Value *j; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v11; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v14; // esi
  double *v15; // eax
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const char *v18; // eax
  const char *v19; // eax
  unsigned int v20; // eax
  const char *pData; // eax
  const Scaleform::GFx::AS3::VM::Error *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::StringDataPtr v24; // [esp-10h] [ebp-34h]
  Scaleform::StringDataPtr v25; // [esp-8h] [ebp-2Ch]
  Scaleform::StringDataPtr v26; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-10h]
  Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v30; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int i; // [esp+28h] [ebp+4h]

  v5 = currObj;
  vm = this->VMRef;
  currClassTR = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor(currObj->pTraits.pObject)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)v5->pTraits.pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  p_V = &v6->V;
  Scaleform::GFx::AS3::VectorBase<double>::Append(&v6->V, &v5->V);
  i = 0;
  if ( !argc )
    return;
  for ( j = argv; ; ++j )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, j);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(vm, j);
    if ( (ValueTraits->Flags & 1) != 0 )
      break;
    v11 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, j);
    if ( !Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(currClassTR, v11) )
    {
      pData = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v26.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v26.pStr = (const char *)&argv;
      v19 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
      v24.pStr = v19;
      if ( v19 )
        goto LABEL_22;
      goto LABEL_26;
    }
    v30 = *(Scaleform::GFx::AS3::VM::Error *)&j->value.VNumber;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(p_V, (Scaleform::GFx::AS3::CheckResult *)&currObj)->Result )
    {
      pHeap = p_V->ValueA.Data.pHeap;
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&p_V->ValueA;
      v14 = p_V->ValueA.Data.Size + 1;
      if ( v14 >= p_V->ValueA.Data.Size )
      {
        if ( v14 >= p_V->ValueA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v14 + (v14 >> 2));
      }
      else if ( v14 < p_V->ValueA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          p_V->ValueA.Data.Size + 1);
      }
      v15 = (double *)&p_ValueA->Data[v14 - 1];
      p_V->ValueA.Data.Size = v14;
      if ( v15 )
        *v15 = *(double *)&v30;
    }
LABEL_16:
    if ( ++i >= (unsigned int)argc )
      return;
  }
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(vm->TraitsArray.pObject, ClassTraits) )
  {
    v25.pStr = "Vector::concat() for argument of type Array";
    v25.Size = 43;
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eNotImplementedError, (Scaleform::String)this->VMRef, v25);
    Scaleform::GFx::AS3::VM::ThrowError(this->VMRef, v16);
    pNode = v30.Message.pNode;
    goto LABEL_32;
  }
  if ( currClassTR == ClassTraits )
  {
    Scaleform::GFx::AS3::VectorBase<double>::Append(
      p_V,
      (const Scaleform::GFx::AS3::VectorBase<double> *)(j->value.VS._1.VInt + 32));
    goto LABEL_16;
  }
  v18 = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
  v26.Size = (unsigned int)v18;
  if ( v18 )
    strlen(v18);
  v26.pStr = (const char *)&argv;
  v19 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
  v24.pStr = v19;
  if ( v19 )
  {
LABEL_22:
    v20 = strlen(v19);
    goto LABEL_27;
  }
LABEL_26:
  v20 = 0;
LABEL_27:
  v24.Size = v20;
  Scaleform::GFx::AS3::VM::Error::Error(&v30, eCheckTypeFailedError, (Scaleform::String)this->VMRef, v24, v26);
  Scaleform::GFx::AS3::VM::ThrowTypeError(this->VMRef, v22);
  v23 = v30.Message.pNode;
  --v30.Message.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( !--argc->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(argc);
  pNode = (Scaleform::GFx::ASStringNode *)currObj;
LABEL_32:
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v5; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v7; // edi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *p_V; // ebx
  const Scaleform::GFx::AS3::Value *j; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v15; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v16; // eax
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  unsigned int v21; // eax
  const char *pData; // eax
  const Scaleform::GFx::AS3::VM::Error *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::StringDataPtr v25; // [esp-10h] [ebp-30h]
  Scaleform::StringDataPtr v26; // [esp-8h] [ebp-28h]
  Scaleform::StringDataPtr v27; // [esp-8h] [ebp-28h]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *pObject; // [esp-4h] [ebp-24h]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-Ch]
  const Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [esp+1Ch] [ebp-4h]
  unsigned int i; // [esp+24h] [ebp+4h]

  v5 = currObj;
  vm = this->VMRef;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(currObj->pTraits.pObject);
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)v5->pTraits.pObject;
  currClassTR = (const Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&currObj,
    pObject);
  v7 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  p_V = (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v7->V;
  Scaleform::GFx::AS3::VectorBase<long>::Append(
    (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v7->V,
    (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)&v5->V);
  i = 0;
  if ( !argc )
    return;
  for ( j = argv; ; ++j )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, j);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(vm, j);
    if ( (ValueTraits->Flags & 1) != 0 )
      break;
    v12 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, j);
    if ( !Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
            (Scaleform::GFx::AS3::ClassTraits::Traits *)currClassTR,
            v12) )
    {
      pData = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v27.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v27.pStr = (const char *)&argv;
      v20 = **(const char ***)((int (__thiscall *)(const Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
      v25.pStr = v20;
      if ( v20 )
        goto LABEL_22;
      goto LABEL_26;
    }
    argv = (const Scaleform::GFx::AS3::Value *const)j->value.VS._1.VInt;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(p_V, (Scaleform::GFx::AS3::CheckResult *)&currObj)->Result )
    {
      pHeap = p_V->ValueA.Data.pHeap;
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&p_V->ValueA;
      v15 = p_V->ValueA.Data.Size + 1;
      if ( v15 >= p_V->ValueA.Data.Size )
      {
        if ( v15 >= p_V->ValueA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v15 + (v15 >> 2));
      }
      else if ( v15 < p_V->ValueA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          p_V->ValueA.Data.Size + 1);
      }
      v16 = &p_ValueA->Data[v15 - 1];
      p_V->ValueA.Data.Size = v15;
      if ( v16 )
        *v16 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)argv;
    }
LABEL_16:
    if ( ++i >= (unsigned int)argc )
      return;
  }
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(vm->TraitsArray.pObject, ClassTraits) )
  {
    v26.pStr = "Vector::concat() for argument of type Array";
    v26.Size = 43;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&currClassTR,
      eNotImplementedError,
      (Scaleform::String)this->VMRef,
      v26);
    Scaleform::GFx::AS3::VM::ThrowError(this->VMRef, v17);
    v18 = v32;
    goto LABEL_32;
  }
  if ( currClassTR == ClassTraits )
  {
    Scaleform::GFx::AS3::VectorBase<long>::Append(
      p_V,
      (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)(j->value.VS._1.VInt + 32));
    goto LABEL_16;
  }
  v19 = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
  v27.Size = (unsigned int)v19;
  if ( v19 )
    strlen(v19);
  v27.pStr = (const char *)&argv;
  v20 = **(const char ***)((int (__thiscall *)(const Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
  v25.pStr = v20;
  if ( v20 )
  {
LABEL_22:
    v21 = strlen(v20);
    goto LABEL_27;
  }
LABEL_26:
  v21 = 0;
LABEL_27:
  v25.Size = v21;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&currClassTR,
    eCheckTypeFailedError,
    (Scaleform::String)this->VMRef,
    v25,
    v27);
  Scaleform::GFx::AS3::VM::ThrowTypeError(this->VMRef, v23);
  v24 = v32;
  --v32->RefCount;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( !--argc->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(argc);
  v18 = (Scaleform::GFx::ASStringNode *)currObj;
LABEL_32:
  if ( !--v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v5; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v7; // edi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *p_V; // ebx
  const Scaleform::GFx::AS3::Value *j; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v15; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v16; // eax
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  unsigned int v21; // eax
  const char *pData; // eax
  const Scaleform::GFx::AS3::VM::Error *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::StringDataPtr v25; // [esp-10h] [ebp-30h]
  Scaleform::StringDataPtr v26; // [esp-8h] [ebp-28h]
  Scaleform::StringDataPtr v27; // [esp-8h] [ebp-28h]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *pObject; // [esp-4h] [ebp-24h]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-Ch]
  const Scaleform::GFx::AS3::ClassTraits::Traits *currClassTR; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [esp+1Ch] [ebp-4h]
  unsigned int i; // [esp+24h] [ebp+4h]

  v5 = currObj;
  vm = this->VMRef;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(currObj->pTraits.pObject);
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)v5->pTraits.pObject;
  currClassTR = (const Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    pObject);
  v7 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  p_V = &v7->V;
  Scaleform::GFx::AS3::VectorBase<long>::Append(&v7->V, &v5->V);
  i = 0;
  if ( !argc )
    return;
  for ( j = argv; ; ++j )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, j);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(vm, j);
    if ( (ValueTraits->Flags & 1) != 0 )
      break;
    v12 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, j);
    if ( !Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
            (Scaleform::GFx::AS3::ClassTraits::Traits *)currClassTR,
            v12) )
    {
      pData = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
      v27.Size = (unsigned int)pData;
      if ( pData )
        strlen(pData);
      v27.pStr = (const char *)&argv;
      v20 = **(const char ***)((int (__thiscall *)(const Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
      v25.pStr = v20;
      if ( v20 )
        goto LABEL_22;
      goto LABEL_26;
    }
    argv = (const Scaleform::GFx::AS3::Value *const)j->value.VS._1.VInt;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(p_V, (Scaleform::GFx::AS3::CheckResult *)&currObj)->Result )
    {
      pHeap = p_V->ValueA.Data.pHeap;
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&p_V->ValueA;
      v15 = p_V->ValueA.Data.Size + 1;
      if ( v15 >= p_V->ValueA.Data.Size )
      {
        if ( v15 >= p_V->ValueA.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v15 + (v15 >> 2));
      }
      else if ( v15 < p_V->ValueA.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ValueA,
          pHeap,
          p_V->ValueA.Data.Size + 1);
      }
      v16 = &p_ValueA->Data[v15 - 1];
      p_V->ValueA.Data.Size = v15;
      if ( v16 )
        *v16 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)argv;
    }
LABEL_16:
    if ( ++i >= (unsigned int)argc )
      return;
  }
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(vm->TraitsArray.pObject, ClassTraits) )
  {
    v26.pStr = "Vector::concat() for argument of type Array";
    v26.Size = 43;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&currClassTR,
      eNotImplementedError,
      (Scaleform::String)this->VMRef,
      v26);
    Scaleform::GFx::AS3::VM::ThrowError(this->VMRef, v17);
    v18 = v32;
    goto LABEL_32;
  }
  if ( currClassTR == ClassTraits )
  {
    Scaleform::GFx::AS3::VectorBase<long>::Append(
      p_V,
      (const Scaleform::GFx::AS3::VectorBase<unsigned long> *)(j->value.VS._1.VInt + 32));
    goto LABEL_16;
  }
  v19 = ClassTraits->GetName(ClassTraits, (Scaleform::GFx::ASString *)&currObj)->pNode->pData;
  v27.Size = (unsigned int)v19;
  if ( v19 )
    strlen(v19);
  v27.pStr = (const char *)&argv;
  v20 = **(const char ***)((int (__thiscall *)(const Scaleform::GFx::AS3::ClassTraits::Traits *))currClassTR->GetName)(currClassTR);
  v25.pStr = v20;
  if ( v20 )
  {
LABEL_22:
    v21 = strlen(v20);
    goto LABEL_27;
  }
LABEL_26:
  v21 = 0;
LABEL_27:
  v25.Size = v21;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&currClassTR,
    eCheckTypeFailedError,
    (Scaleform::String)this->VMRef,
    v25,
    v27);
  Scaleform::GFx::AS3::VM::ThrowTypeError(this->VMRef, v23);
  v24 = v32;
  --v32->RefCount;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( !--argc->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(argc);
  v18 = (Scaleform::GFx::ASStringNode *)currObj;
LABEL_32:
  if ( !--v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}
