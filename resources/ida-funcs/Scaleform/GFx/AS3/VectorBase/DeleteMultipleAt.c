void __thiscall Scaleform::GFx::AS3::VectorBase<double>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *deleted)
{
  unsigned int v4; // edi
  unsigned int v5; // eax
  Scaleform::GFx::AS3::VectorBase<double> *v6; // esi
  bool v7; // zf
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v12; // esi
  long double *Data; // eax
  double *v14; // esi
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v16; // esi
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-30h]
  unsigned int v18; // [esp+Ch] [ebp-1Ch]
  unsigned int i; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v21; // [esp+18h] [ebp-10h] BYREF
  double v22; // [esp+20h] [ebp-8h]

  v4 = count;
  v5 = 0;
  v6 = this;
  i = 0;
  if ( count )
  {
    v18 = pos;
    do
    {
      if ( pos + v5 >= v6->ValueA.Data.Size )
        break;
      v7 = !deleted->V.Fixed;
      v22 = v6->ValueA.Data.Data[v18];
      if ( v7 )
        goto LABEL_8;
      v17.pStr = "Vector";
      v17.Size = 6;
      Scaleform::GFx::AS3::VM::Error::Error(&v21, eVectorFixedError, (Scaleform::String)deleted->V.VMRef, v17);
      Scaleform::GFx::AS3::VM::ThrowRangeError(deleted->V.VMRef, v8);
      pNode = v21.Message.pNode;
      --v21.Message.pNode->RefCount;
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
        Data = p_ValueA->Data.Data;
        deleted->V.ValueA.Data.Size = v12;
        v4 = count;
        v14 = &Data[v12 - 1];
        if ( v14 )
          *v14 = v22;
        v6 = this;
      }
      ++v18;
      v5 = i + 1;
      i = v5;
    }
    while ( v5 < v4 );
  }
  Size = v6->ValueA.Data.Size;
  v16 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v6->ValueA;
  if ( Size != v4 )
  {
    memmove((int)&v16->Data[pos], (const __m128i *)&v16->Data[pos + v4], 8 * (Size - pos - v4));
    v16->Size -= v4;
    return;
  }
  if ( !Size )
  {
    if ( !v16->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v16,
        v16[1].Data,
        0);
    goto LABEL_25;
  }
  if ( (v16->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_25:
    v16->Size = 0;
    return;
  }
  if ( v16->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16->Data);
    v16->Data = 0;
  }
  v16->Policy.Capacity = 0;
  v16->Size = 0;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *deleted)
{
  unsigned int v4; // edi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v5; // esi
  unsigned int v6; // ebx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v12; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint **v13; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v15; // esi
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-28h]
  unsigned int v17; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *deleteda; // [esp+2Ch] [ebp+Ch]

  v4 = count;
  v5 = this;
  v6 = 0;
  if ( count )
  {
    v17 = pos;
    do
    {
      if ( v6 + pos >= v5->ValueA.Data.Size )
        break;
      deleteda = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v5->ValueA.Data.Data[v17];
      if ( !deleted->V.Fixed )
        goto LABEL_8;
      v16.pStr = "Vector";
      v16.Size = 6;
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eVectorFixedError, (Scaleform::String)deleted->V.VMRef, v16);
      Scaleform::GFx::AS3::VM::ThrowRangeError(deleted->V.VMRef, v8);
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
        v5 = this;
        if ( v13 )
          *v13 = deleteda;
      }
      ++v17;
      ++v6;
    }
    while ( v6 < v4 );
  }
  Size = v5->ValueA.Data.Size;
  v15 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v5->ValueA;
  if ( Size != v4 )
  {
    memmove((int)&v15->Data[pos], (const __m128i *)&(&v15->Data[pos])[v4], 4 * (Size - pos - v4));
    v15->Size -= v4;
    return;
  }
  if ( !Size )
  {
    if ( !v15->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v15,
        v15[1].Data,
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
