void __thiscall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  unsigned int Size; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *p_NewOpcodePos; // edi
  unsigned int v6; // esi
  Scaleform::GFx::AS3::TR::State **Data; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v9; // esi
  int *v10; // eax

  Size = this->WCode->Data.Size;
  pHeap = this->NewOpcodePos.Data.pHeap;
  p_NewOpcodePos = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->NewOpcodePos;
  v6 = this->NewOpcodePos.Data.Size + 1;
  if ( v6 >= this->NewOpcodePos.Data.Size )
  {
    if ( v6 >= this->NewOpcodePos.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_NewOpcodePos,
        pHeap,
        v6 + (v6 >> 2));
  }
  else if ( v6 < this->NewOpcodePos.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_NewOpcodePos,
      pHeap,
      v6);
  }
  Data = p_NewOpcodePos->Data;
  p_NewOpcodePos->Size = v6;
  Data[v6 - 1] = (Scaleform::GFx::AS3::TR::State *)Size;
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v9 = WCode->Size + 1;
  if ( v9 >= WCode->Size )
  {
    if ( v9 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v9 + (v9 >> 2));
  }
  else if ( v9 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  v10 = WCode->Data;
  WCode->Size = v9;
  v10[v9 - 1] = opcode;
}
