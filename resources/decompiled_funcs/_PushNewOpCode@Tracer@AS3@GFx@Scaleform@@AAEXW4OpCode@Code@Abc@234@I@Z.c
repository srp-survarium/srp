void __thiscall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned int arg1)
{
  unsigned int Size; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *p_NewOpcodePos; // edi
  unsigned int v7; // esi
  Scaleform::GFx::AS3::TR::State **Data; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v10; // esi
  int *v11; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v12; // edi
  unsigned int v13; // esi
  int *v14; // ecx

  Size = this->WCode->Data.Size;
  pHeap = this->NewOpcodePos.Data.pHeap;
  p_NewOpcodePos = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->NewOpcodePos;
  v7 = this->NewOpcodePos.Data.Size + 1;
  if ( v7 >= this->NewOpcodePos.Data.Size )
  {
    if ( v7 >= this->NewOpcodePos.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_NewOpcodePos,
        pHeap,
        v7 + (v7 >> 2));
  }
  else if ( v7 < this->NewOpcodePos.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_NewOpcodePos,
      pHeap,
      v7);
  }
  Data = p_NewOpcodePos->Data;
  p_NewOpcodePos->Size = v7;
  Data[v7 - 1] = (Scaleform::GFx::AS3::TR::State *)Size;
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v10 = WCode->Size + 1;
  if ( v10 >= WCode->Size )
  {
    if ( v10 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v10 + (v10 >> 2));
  }
  else if ( v10 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  v11 = WCode->Data;
  WCode->Size = v10;
  v11[v10 - 1] = opcode;
  v12 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v13 = v12->Size + 1;
  if ( v13 >= v12->Size )
  {
    if ( v13 >= v12->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v12,
        v12,
        v13 + (v13 >> 2));
  }
  else if ( v13 < v12->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v12,
      v12,
      v12->Size + 1);
  }
  v14 = v12->Data;
  v12->Size = v13;
  v14[v13 - 1] = arg1;
}
