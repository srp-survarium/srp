void __thiscall Scaleform::GFx::AS3::VTable::SetMethodName(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        const Scaleform::GFx::ASString *name)
{
  int Index; // eax
  Scaleform::GFx::ASString *v6; // esi
  Scaleform::String *v7; // eax
  void *v8; // esi
  Scaleform::GFx::ASString *v9; // esi
  Scaleform::String *v10; // eax
  void *v11; // esi
  Scaleform::GFx::ASString *Data; // ecx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASString *v14; // edi
  Scaleform::GFx::ASStringNode *v15; // ecx
  Scaleform::String result; // [esp+4h] [ebp-4h] BYREF

  Index = ind.Index;
  if ( ind.Index >= this->Names.Data.Size )
  {
    Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Names.Data,
      ind.Index + 1);
    Index = ind.Index;
  }
  switch ( dt )
  {
    case BT_Code:
      Data = this->Names.Data.Data;
      pNode = name->pNode;
      ++name->pNode->RefCount;
      v14 = &Data[Index];
      v15 = v14->pNode;
      if ( v14->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v14->pNode = pNode;
      break;
    case BT_Get:
      v9 = &this->Names.Data.Data[Index];
      v10 = Scaleform::operator+(&result, (const __m128i *)"get ", name);
      Scaleform::GFx::ASString::operator=<Scaleform::String>(v9, v10);
      v11 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      break;
    case BT_Set:
      if ( Index + 1 >= this->Names.Data.Size )
      {
        Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->Names.Data,
          Index + 2);
        Index = ind.Index;
      }
      v6 = &this->Names.Data.Data[Index + 1];
      v7 = Scaleform::operator+((Scaleform::String *)&dt, (const __m128i *)"set ", name);
      Scaleform::GFx::ASString::operator=<Scaleform::String>(v6, v7);
      v8 = (void *)(dt & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((dt & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      break;
  }
}
