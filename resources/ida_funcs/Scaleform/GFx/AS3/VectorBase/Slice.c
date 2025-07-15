void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  int v5; // ebx
  int v6; // ecx
  unsigned __int8 *Size; // eax
  bool v8; // sf
  int v9; // edx
  bool v10; // zf
  Scaleform::GFx::AS3::VM *v11; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const void *v14; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v15; // edi
  unsigned int v16; // esi
  double *v17; // eax
  Scaleform::GFx::AS3::CheckResult v18; // [esp+Fh] [ebp-21h] BYREF
  int endIndex; // [esp+10h] [ebp-20h] BYREF
  int startIndex; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<double> *v21; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+20h] [ebp-10h] BYREF
  double v24; // [esp+28h] [ebp-8h]

  v21 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&i,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)currObj->pTraits.pObject);
  v5 = i;
  Scaleform::GFx::AS3::Value::Pick(result, (Scaleform::GFx::AS3::Object *)i);
  v6 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v18, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v18, (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v6 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v6 < 0 )
  {
    v8 = (signed int)(v21->ValueA.Data.Size + v6) < 0;
    v6 += v21->ValueA.Data.Size;
    startIndex = v6;
    if ( v8 )
    {
      v6 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += v21->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)v21->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)v21->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  v9 = v6;
  i = v6;
  if ( v6 < (int)Size )
  {
    do
    {
      v10 = *(_BYTE *)(v5 + 36) == 0;
      v24 = v21->ValueA.Data.Data[v9];
      if ( v10 )
        goto LABEL_19;
      v11 = *(Scaleform::GFx::AS3::VM **)(v5 + 40);
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, v11);
      Scaleform::GFx::AS3::VM::ThrowRangeError(v11, v12);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !*(_BYTE *)(v5 + 36) )
      {
LABEL_19:
        v14 = *(const void **)(v5 + 56);
        v15 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)(v5 + 44);
        v16 = *(_DWORD *)(v5 + 48) + 1;
        if ( v16 >= *(_DWORD *)(v5 + 48) )
        {
          if ( v16 >= *(_DWORD *)(v5 + 52) )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v15,
              v14,
              v16 + (v16 >> 2));
        }
        else if ( v16 < *(_DWORD *)(v5 + 52) >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v15,
            v14,
            *(_DWORD *)(v5 + 48) + 1);
        }
        v17 = (double *)&v15->Data[v16 - 1];
        *(_DWORD *)(v5 + 48) = v16;
        if ( v17 )
          *v17 = v24;
      }
      v9 = ++i;
    }
    while ( i < endIndex );
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v6; // ebx
  int v7; // ecx
  unsigned __int8 *Size; // eax
  bool v9; // sf
  int v10; // ebp
  bool v11; // zf
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v17; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v18; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<long> *v22; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v23; // [esp+1Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject;
  v22 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v7 < 0 )
  {
    v9 = (signed int)(this->ValueA.Data.Size + v7) < 0;
    v7 += this->ValueA.Data.Size;
    startIndex = v7;
    if ( v9 )
    {
      v7 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)this->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  v10 = v7;
  if ( v7 < (int)Size )
  {
    do
    {
      v11 = !v6->V.Fixed;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v22->ValueA.Data.Data[v10];
      if ( v11 )
        goto LABEL_19;
      VMRef = v6->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v13);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
      {
LABEL_19:
        pHeap = v6->V.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v6->V.ValueA;
        v17 = v6->V.ValueA.Data.Size + 1;
        if ( v17 >= v6->V.ValueA.Data.Size )
        {
          if ( v17 >= v6->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v17 + (v17 >> 2));
        }
        else if ( v17 < v6->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v6->V.ValueA.Data.Size + 1);
        }
        v18 = &p_ValueA->Data[v17 - 1];
        v6->V.ValueA.Data.Size = v17;
        if ( v18 )
          *v18 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)currObj;
      }
      ++v10;
    }
    while ( v10 < endIndex );
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *currObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v5; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v6; // ebx
  int v7; // eax
  unsigned __int8 *Size; // ecx
  bool v9; // sf
  int v10; // ebp
  Scaleform::GFx::AS3::Value *v11; // edi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v18; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+1Ch] [ebp-8h] BYREF

  v5 = this;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)currObj->pTraits.pObject;
  v18 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v7 < 0 )
  {
    v9 = (signed int)(v5->ValueA.Data.Size + v7) < 0;
    v7 += v5->ValueA.Data.Size;
    startIndex = v7;
    if ( v9 )
    {
      v7 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += v5->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)v5->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)v5->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v7;
  if ( v7 < (int)Size )
  {
    v10 = v7;
    while ( 1 )
    {
      v11 = &v5->ValueA.Data.Data[v10];
      if ( !v6->V.Fixed )
        goto LABEL_21;
      VMRef = v6->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v13);
      pNode = v19.Message.pNode;
      --v19.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
LABEL_21:
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &v6->V.ValueA.Data,
          v11);
      ++v10;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)currObj + 1);
      if ( (int)currObj >= endIndex )
        break;
      v5 = v18;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v6; // ebx
  int v7; // ecx
  unsigned __int8 *Size; // eax
  bool v9; // sf
  int v10; // ebp
  bool v11; // zf
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v17; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v18; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v22; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v23; // [esp+1Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject;
  v22 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v7 < 0 )
  {
    v9 = (signed int)(this->ValueA.Data.Size + v7) < 0;
    v7 += this->ValueA.Data.Size;
    startIndex = v7;
    if ( v9 )
    {
      v7 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)this->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  v10 = v7;
  if ( v7 < (int)Size )
  {
    do
    {
      v11 = !v6->V.Fixed;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v22->ValueA.Data.Data[v10];
      if ( v11 )
        goto LABEL_19;
      VMRef = v6->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v13);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
      {
LABEL_19:
        pHeap = v6->V.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v6->V.ValueA;
        v17 = v6->V.ValueA.Data.Size + 1;
        if ( v17 >= v6->V.ValueA.Data.Size )
        {
          if ( v17 >= v6->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v17 + (v17 >> 2));
        }
        else if ( v17 < v6->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v6->V.ValueA.Data.Size + 1);
        }
        v18 = &p_ValueA->Data[v17 - 1];
        v6->V.ValueA.Data.Size = v17;
        if ( v18 )
          *v18 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)currObj;
      }
      ++v10;
    }
    while ( v10 < endIndex );
  }
}
