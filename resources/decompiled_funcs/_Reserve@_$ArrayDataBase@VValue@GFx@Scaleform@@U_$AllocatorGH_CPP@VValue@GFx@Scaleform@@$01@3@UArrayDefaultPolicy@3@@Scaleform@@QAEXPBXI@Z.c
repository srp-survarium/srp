void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  int v3; // ebx
  unsigned int v5; // esi
  unsigned int Size; // eax
  unsigned int v7; // ebp
  Scaleform::GFx::Value *v8; // esi
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  Scaleform::GFx::Value *v11; // esi
  Scaleform::GFx::Value *v12; // eax
  unsigned int s; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::Value *newData; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  if ( newCapacity )
  {
    v5 = 4 * ((newCapacity + 3) >> 2);
    newCapacity = v5;
    if ( this->Data )
    {
      v15 = 2;
      newData = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           24 * v5,
                                           &v15);
      Size = this->Size;
      if ( Size >= v5 )
      {
        s = v5;
        Size = v5;
      }
      else
      {
        s = this->Size;
      }
      if ( Size )
      {
        v7 = Size;
        do
        {
          if ( &newData[v3] )
          {
            Scaleform::GFx::Value::Value(&newData[v3], &this->Data[v3]);
            Size = s;
          }
          v8 = &this->Data[v3];
          if ( (v8->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v8->pObjectInterface->ObjectRelease)(
              v8,
              v8->mValue.IValue);
            Size = s;
            v8->pObjectInterface = 0;
          }
          ++v3;
          --v7;
          v8->Type = VT_Undefined;
        }
        while ( v7 );
        v5 = newCapacity;
      }
      v9 = Size;
      if ( Size < this->Size )
      {
        v10 = Size;
        do
        {
          v11 = &this->Data[v10];
          if ( (v11->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v11->pObjectInterface->ObjectRelease)(
              v11,
              v11->mValue.IValue);
            v11->pObjectInterface = 0;
          }
          ++v9;
          v11->Type = VT_Undefined;
          ++v10;
        }
        while ( v9 < this->Size );
        v5 = newCapacity;
      }
      if ( this->Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Policy.Capacity = v5;
      this->Data = newData;
    }
    else
    {
      newCapacity = 2;
      v12 = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       24 * v5,
                                       &newCapacity);
      this->Policy.Capacity = v5;
      this->Data = v12;
    }
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}
