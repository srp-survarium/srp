void __thiscall Scaleform::GFx::AS3::TR::State::State(Scaleform::GFx::AS3::TR::State *this, int tr, unsigned int cp)
{
  Scaleform::GFx::AS3::Tracer *v3; // eax
  unsigned int v5; // ecx
  const Scaleform::MemoryHeap *Heap; // ecx
  const Scaleform::MemoryHeap *v7; // ecx
  const Scaleform::MemoryHeap *v8; // ecx
  unsigned int local_reg_count; // ecx
  Scaleform::MemoryHeap *v10; // eax
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  unsigned int v12; // edi
  unsigned __int8 *v13; // eax

  v3 = (Scaleform::GFx::AS3::Tracer *)tr;
  v5 = cp;
  this->BCP = cp;
  this->OpcodeCP = v5;
  this->pTracer = v3;
  Heap = v3->Heap;
  this->Registers.Data.Data = 0;
  this->Registers.Data.Size = 0;
  this->Registers.Data.Policy.Capacity = 0;
  this->Registers.Data.pHeap = Heap;
  v7 = v3->Heap;
  this->OpStack.Data.Data = 0;
  this->OpStack.Data.Size = 0;
  this->OpStack.Data.Policy.Capacity = 0;
  this->OpStack.Data.pHeap = v7;
  v8 = v3->Heap;
  this->ScopeStack.Data.Data = 0;
  this->ScopeStack.Data.Size = 0;
  this->ScopeStack.Data.Policy.Capacity = 0;
  this->ScopeStack.Data.pHeap = v8;
  local_reg_count = v3->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[v3->CF->MBIIndex.Ind]->local_reg_count;
  v10 = v3->Heap;
  this->RegistersAlive.BitsCount = local_reg_count;
  Alloc = v10->Alloc;
  v12 = (local_reg_count + 7) >> 3;
  tr = 341;
  v13 = (unsigned __int8 *)Alloc(v10, v12, (const Scaleform::AllocInfo *)&tr);
  this->RegistersAlive.pData = v13;
  memset((int)v13, 0, v12);
}


void __thiscall Scaleform::GFx::AS3::TR::State::State(
        Scaleform::GFx::AS3::TR::State *this,
        const Scaleform::GFx::AS3::TR::State *__that)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Registers; // edi
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int Size; // edx
  unsigned int v7; // ebp
  const Scaleform::MemoryHeap *v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ebp
  const Scaleform::MemoryHeap *v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebp
  unsigned int count; // [esp+10h] [ebp-4h]
  unsigned int counta; // [esp+10h] [ebp-4h]
  unsigned int countb; // [esp+10h] [ebp-4h]
  Scaleform::GFx::AS3::Value *__thata; // [esp+18h] [ebp+4h]
  Scaleform::GFx::AS3::Value *__thatb; // [esp+18h] [ebp+4h]
  Scaleform::GFx::AS3::Value *__thatc; // [esp+18h] [ebp+4h]

  this->pTracer = __that->pTracer;
  this->BCP = __that->BCP;
  this->OpcodeCP = __that->OpcodeCP;
  p_Registers = &this->Registers;
  this->Registers.Data.Data = 0;
  this->Registers.Data.Size = 0;
  this->Registers.Data.Policy.Capacity = 0;
  pHeap = __that->Registers.Data.pHeap;
  this->Registers.Data.pHeap = pHeap;
  Size = __that->Registers.Data.Size;
  count = Size;
  __thata = __that->Registers.Data.Data;
  if ( Size )
  {
    v7 = this->Registers.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Registers.Data,
      pHeap,
      Size + v7);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
      &p_Registers->Data.Data[v7].Flags,
      count,
      __thata);
  }
  this->OpStack.Data.Data = 0;
  this->OpStack.Data.Size = 0;
  this->OpStack.Data.Policy.Capacity = 0;
  v8 = __that->OpStack.Data.pHeap;
  this->OpStack.Data.pHeap = v8;
  v9 = __that->OpStack.Data.Size;
  counta = v9;
  __thatb = __that->OpStack.Data.Data;
  if ( v9 )
  {
    v10 = this->OpStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      v8,
      v9 + v10);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
      &this->OpStack.Data.Data[v10].Flags,
      counta,
      __thatb);
  }
  this->ScopeStack.Data.Data = 0;
  this->ScopeStack.Data.Size = 0;
  this->ScopeStack.Data.Policy.Capacity = 0;
  v11 = __that->ScopeStack.Data.pHeap;
  this->ScopeStack.Data.pHeap = v11;
  v12 = __that->ScopeStack.Data.Size;
  countb = v12;
  __thatc = __that->ScopeStack.Data.Data;
  if ( v12 )
  {
    v13 = this->ScopeStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ScopeStack.Data,
      v11,
      v12 + v13);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
      &this->ScopeStack.Data.Data[v13].Flags,
      countb,
      __thatc);
  }
  Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>(
    &this->RegistersAlive,
    (int)&__that->RegistersAlive);
}
