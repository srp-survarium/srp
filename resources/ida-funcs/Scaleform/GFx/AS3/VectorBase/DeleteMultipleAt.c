void __thiscall Scaleform::GFx::AS3::VectorBase<double>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *deleted)
{
  unsigned int v4; // edi
  unsigned int v5; // eax
  bool v6; // zf
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v12; // esi
  double *v13; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v15; // esi
  const Scaleform::MemoryHeap *v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-1Ch]
  unsigned int i; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::VectorBase<double> *v19; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v20; // [esp+18h] [ebp-10h] BYREF
  double v21; // [esp+20h] [ebp-8h]

  v4 = count;
  v5 = 0;
  v19 = this;
  i = 0;
  if ( count )
  {
    v17 = pos;
    do
    {
      if ( pos + v5 >= this->ValueA.Data.Size )
        break;
      v6 = !deleted->V.Fixed;
      v21 = this->ValueA.Data.Data[v17];
      if ( v6 )
        goto LABEL_8;
      VMRef = deleted->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v20, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v8);
      pNode = v20.Message.pNode;
      --v20.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !deleted->V.Fixed )
      {
LABEL_8:
        pHeap = deleted->V.ValueA.Data.pHeap;
        p_ValueA = &deleted->V.ValueA;
        v12 = deleted->V.ValueA.Data.Size + 1;
        if ( v12 >= deleted->V.ValueA.Data.Size )
        {
          if ( v12 >= deleted->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v12 + (v12 >> 2));
        }
        else if ( v12 < deleted->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
            pHeap,
            deleted->V.ValueA.Data.Size + 1);
        }
        v13 = &p_ValueA->Data.Data[v12 - 1];
        deleted->V.ValueA.Data.Size = v12;
        v4 = count;
        if ( v13 )
          *v13 = v21;
      }
      ++v17;
      this = v19;
      v5 = i + 1;
      i = v5;
    }
    while ( v5 < v4 );
  }
  Size = this->ValueA.Data.Size;
  v15 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  if ( Size != v4 )
  {
    memmove((unsigned __int8 *)&v15->Data[pos], (unsigned __int8 *)&v15->Data[pos + v4], 8 * (Size - pos - v4));
    v15->Size -= v4;
    return;
  }
  v16 = this->ValueA.Data.pHeap;
  if ( !Size )
  {
    if ( !v15->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v15,
        v16,
        0);
    goto LABEL_24;
  }
  if ( (v15->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_24:
    v15->Size = 0;
    return;
  }
  if ( v15->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15->Data);
    v15->Data = 0;
  }
  v15->Policy.Capacity = 0;
  v15->Size = 0;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *deleted)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  Scaleform::GFx::AS3::Value *v7; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int i; // [esp+Ch] [ebp-10h]
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v15; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+14h] [ebp-8h] BYREF
  unsigned int counta; // [esp+24h] [ebp+8h]

  v5 = 0;
  v15 = this;
  i = 0;
  if ( count )
  {
    v6 = 16 * pos;
    counta = 16 * pos;
    do
    {
      if ( pos + v5 >= this->ValueA.Data.Size )
        break;
      v7 = (Scaleform::GFx::AS3::Value *)((char *)this->ValueA.Data.Data + v6);
      if ( !deleted->V.Fixed )
        goto LABEL_8;
      VMRef = deleted->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v9);
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !deleted->V.Fixed )
LABEL_8:
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &deleted->V.ValueA.Data,
          v7);
      this = v15;
      v5 = i + 1;
      v6 = counta + 16;
      i = v5;
      counta += 16;
    }
    while ( v5 < count );
  }
  Size = this->ValueA.Data.Size;
  p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  if ( Size != count )
  {
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
      (Scaleform::GFx::AS3::Value *)&p_ValueA->Data[pos],
      count);
    memmove(
      (unsigned __int8 *)&p_ValueA->Data[pos],
      (unsigned __int8 *)&p_ValueA->Data[count + pos],
      16 * (p_ValueA->Size - pos - count));
    p_ValueA->Size -= count;
    return;
  }
  pHeap = this->ValueA.Data.pHeap;
  if ( !Size )
  {
    if ( !p_ValueA->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ValueA,
        pHeap,
        0);
    goto LABEL_18;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    (Scaleform::GFx::AS3::Value *)p_ValueA->Data,
    Size);
  if ( (p_ValueA->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_18:
    p_ValueA->Size = 0;
    return;
  }
  if ( p_ValueA->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ValueA->Data);
    p_ValueA->Data = 0;
  }
  p_ValueA->Policy.Capacity = 0;
  p_ValueA->Size = 0;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *deleted)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v12; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint **v13; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v15; // esi
  const Scaleform::MemoryHeap *v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-10h]
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v18; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *deleteda; // [esp+28h] [ebp+Ch]

  v4 = count;
  v5 = 0;
  v18 = this;
  if ( count )
  {
    v17 = pos;
    do
    {
      if ( v5 + pos >= this->ValueA.Data.Size )
        break;
      deleteda = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)this->ValueA.Data.Data[v17];
      if ( !deleted->V.Fixed )
        goto LABEL_8;
      VMRef = deleted->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v8);
      pNode = v19.Message.pNode;
      --v19.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !deleted->V.Fixed )
      {
LABEL_8:
        pHeap = deleted->V.ValueA.Data.pHeap;
        p_ValueA = &deleted->V.ValueA;
        v12 = deleted->V.ValueA.Data.Size + 1;
        if ( v12 >= deleted->V.ValueA.Data.Size )
        {
          if ( v12 >= deleted->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v12 + (v12 >> 2));
        }
        else if ( v12 < deleted->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
            pHeap,
            deleted->V.ValueA.Data.Size + 1);
        }
        v13 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint **)&p_ValueA->Data.Data[v12 - 1];
        deleted->V.ValueA.Data.Size = v12;
        v4 = count;
        if ( v13 )
          *v13 = deleteda;
      }
      ++v17;
      this = v18;
      ++v5;
    }
    while ( v5 < v4 );
  }
  Size = this->ValueA.Data.Size;
  v15 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  if ( Size != v4 )
  {
    memmove((unsigned __int8 *)&v15->Data[pos], (unsigned __int8 *)&(&v15->Data[pos])[v4], 4 * (Size - pos - v4));
    v15->Size -= v4;
    return;
  }
  v16 = this->ValueA.Data.pHeap;
  if ( !Size )
  {
    if ( !v15->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v15,
        v16,
        0);
    goto LABEL_24;
  }
  if ( (v15->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_24:
    v15->Size = 0;
    return;
  }
  if ( v15->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15->Data);
    v15->Data = 0;
  }
  v15->Policy.Capacity = 0;
  v15->Size = 0;
}
