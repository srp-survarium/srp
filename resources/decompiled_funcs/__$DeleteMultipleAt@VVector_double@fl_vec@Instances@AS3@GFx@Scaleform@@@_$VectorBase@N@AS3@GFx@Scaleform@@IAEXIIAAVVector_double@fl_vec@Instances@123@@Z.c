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
