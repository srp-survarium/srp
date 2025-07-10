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
