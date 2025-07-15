void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  int v5; // ebx
  int v6; // ecx
  int Size; // eax
  bool v8; // sf
  int v9; // edx
  bool v10; // zf
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const void *v13; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v14; // edi
  unsigned int v15; // esi
  double *v16; // eax
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-38h]
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
  Size = 0xFFFFFF;
  startIndex = 0;
  endIndex = 0xFFFFFF;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v18, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
    Size = endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v18, (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v6 = startIndex;
    Size = endIndex;
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
  if ( Size < 0 )
  {
    Size += v21->ValueA.Data.Size;
    endIndex = Size;
  }
  if ( (signed int)v21->ValueA.Data.Size < Size )
  {
    Size = v21->ValueA.Data.Size;
    endIndex = Size;
  }
  v9 = v6;
  i = v6;
  if ( v6 < Size )
  {
    do
    {
      v10 = *(_BYTE *)(v5 + 36) == 0;
      v24 = v21->ValueA.Data.Data[v9];
      if ( v10 )
        goto LABEL_19;
      v17.pStr = "Vector";
      v17.Size = 6;
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, *(Scaleform::String *)(v5 + 40), v17);
      Scaleform::GFx::AS3::VM::ThrowRangeError(*(Scaleform::GFx::AS3::VM **)(v5 + 40), v11);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !*(_BYTE *)(v5 + 36) )
      {
LABEL_19:
        v13 = *(const void **)(v5 + 56);
        v14 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)(v5 + 44);
        v15 = *(_DWORD *)(v5 + 48) + 1;
        if ( v15 >= *(_DWORD *)(v5 + 48) )
        {
          if ( v15 >= *(_DWORD *)(v5 + 52) )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v14,
              v13,
              v15 + (v15 >> 2));
        }
        else if ( v15 < *(_DWORD *)(v5 + 52) >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v14,
            v13,
            *(_DWORD *)(v5 + 48) + 1);
        }
        v16 = (double *)&v14->Data[v15 - 1];
        *(_DWORD *)(v5 + 48) = v15;
        if ( v16 )
          *v16 = v24;
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
  int Size; // eax
  bool v9; // sf
  int v10; // ebp
  bool v11; // zf
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v16; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v18; // esi
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<long> *v23; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v24; // [esp+1Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject;
  v23 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = 0xFFFFFF;
  startIndex = 0;
  endIndex = 0xFFFFFF;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = endIndex;
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
  if ( Size < 0 )
  {
    Size += this->ValueA.Data.Size;
    endIndex = Size;
  }
  if ( (signed int)this->ValueA.Data.Size < Size )
  {
    Size = this->ValueA.Data.Size;
    endIndex = Size;
  }
  v10 = v7;
  if ( v7 < Size )
  {
    do
    {
      v11 = !v6->V.Fixed;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v23->ValueA.Data.Data[v10];
      if ( v11 )
        goto LABEL_19;
      v19.pStr = "Vector";
      v19.Size = 6;
      Scaleform::GFx::AS3::VM::Error::Error(&v24, eVectorFixedError, (Scaleform::String)v6->V.VMRef, v19);
      Scaleform::GFx::AS3::VM::ThrowRangeError(v6->V.VMRef, v12);
      pNode = v24.Message.pNode;
      --v24.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
      {
LABEL_19:
        pHeap = v6->V.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v6->V.ValueA;
        v16 = v6->V.ValueA.Data.Size + 1;
        if ( v16 >= v6->V.ValueA.Data.Size )
        {
          if ( v16 >= v6->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v16 + (v16 >> 2));
        }
        else if ( v16 < v6->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v6->V.ValueA.Data.Size + 1);
        }
        Data = p_ValueA->Data;
        v6->V.ValueA.Data.Size = v16;
        v18 = &Data[v16 - 1];
        if ( v18 )
          *v18 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)currObj;
      }
      ++v10;
    }
    while ( v10 < endIndex );
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
  int Size; // eax
  bool v9; // sf
  int v10; // ebp
  bool v11; // zf
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v16; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v18; // esi
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v23; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v24; // [esp+1Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject;
  v23 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = 0xFFFFFF;
  startIndex = 0;
  endIndex = 0xFFFFFF;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = endIndex;
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
  if ( Size < 0 )
  {
    Size += this->ValueA.Data.Size;
    endIndex = Size;
  }
  if ( (signed int)this->ValueA.Data.Size < Size )
  {
    Size = this->ValueA.Data.Size;
    endIndex = Size;
  }
  v10 = v7;
  if ( v7 < Size )
  {
    do
    {
      v11 = !v6->V.Fixed;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v23->ValueA.Data.Data[v10];
      if ( v11 )
        goto LABEL_19;
      v19.pStr = "Vector";
      v19.Size = 6;
      Scaleform::GFx::AS3::VM::Error::Error(&v24, eVectorFixedError, (Scaleform::String)v6->V.VMRef, v19);
      Scaleform::GFx::AS3::VM::ThrowRangeError(v6->V.VMRef, v12);
      pNode = v24.Message.pNode;
      --v24.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
      {
LABEL_19:
        pHeap = v6->V.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v6->V.ValueA;
        v16 = v6->V.ValueA.Data.Size + 1;
        if ( v16 >= v6->V.ValueA.Data.Size )
        {
          if ( v16 >= v6->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v16 + (v16 >> 2));
        }
        else if ( v16 < v6->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v6->V.ValueA.Data.Size + 1);
        }
        Data = p_ValueA->Data;
        v6->V.ValueA.Data.Size = v16;
        v18 = &Data[v16 - 1];
        if ( v18 )
          *v18 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)currObj;
      }
      ++v10;
    }
    while ( v10 < endIndex );
  }
}
