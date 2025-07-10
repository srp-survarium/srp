void __thiscall Scaleform::GFx::AS2::ArrayObject::Finalize_GC(Scaleform::GFx::AS2::ArrayObject *this)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS2::Value *v4; // ecx
  unsigned __int8 Type; // al
  volatile LONG *v6; // esi

  Size = this->Elements.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    v4 = this->Elements.Data.Data[i];
    if ( v4 )
    {
      Type = v4->T.Type;
      if ( v4->T.Type != 8 && Type >= 5u && Type != 6 && Type != 9 )
        Scaleform::GFx::AS2::Value::DropRefs(v4);
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data[i]);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data);
  v6 = (volatile LONG *)(this->StringValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
