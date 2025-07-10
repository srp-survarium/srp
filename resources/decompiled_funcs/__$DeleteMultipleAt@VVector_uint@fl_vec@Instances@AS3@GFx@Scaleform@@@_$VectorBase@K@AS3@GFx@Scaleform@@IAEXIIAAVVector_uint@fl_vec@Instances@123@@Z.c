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
