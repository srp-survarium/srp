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
