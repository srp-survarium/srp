void __thiscall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned int arg1,
        unsigned int arg2)
{
  unsigned int Size; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *p_NewOpcodePos; // edi
  unsigned int v8; // esi
  Scaleform::GFx::AS3::TR::State **Data; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v11; // esi
  int *v12; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v13; // edi
  unsigned int v14; // esi
  int *v15; // ecx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v16; // edi
  unsigned int v17; // esi
  int *v18; // edx

  Size = this->WCode->Data.Size;
  pHeap = this->NewOpcodePos.Data.pHeap;
  p_NewOpcodePos = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->NewOpcodePos;
  v8 = this->NewOpcodePos.Data.Size + 1;
  if ( v8 >= this->NewOpcodePos.Data.Size )
  {
    if ( v8 >= this->NewOpcodePos.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_NewOpcodePos,
        pHeap,
        v8 + (v8 >> 2));
  }
  else if ( v8 < this->NewOpcodePos.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_NewOpcodePos,
      pHeap,
      v8);
  }
  Data = p_NewOpcodePos->Data;
  p_NewOpcodePos->Size = v8;
  Data[v8 - 1] = (Scaleform::GFx::AS3::TR::State *)Size;
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v11 = WCode->Size + 1;
  if ( v11 >= WCode->Size )
  {
    if ( v11 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v11 + (v11 >> 2));
  }
  else if ( v11 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  v12 = WCode->Data;
  WCode->Size = v11;
  v12[v11 - 1] = opcode;
  v13 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v14 = v13->Size + 1;
  if ( v14 >= v13->Size )
  {
    if ( v14 >= v13->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v13,
        v13,
        v14 + (v14 >> 2));
  }
  else if ( v14 < v13->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v13,
      v13,
      v13->Size + 1);
  }
  v15 = v13->Data;
  v13->Size = v14;
  v15[v14 - 1] = arg1;
  v16 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  v17 = v16->Size + 1;
  if ( v17 >= v16->Size )
  {
    if ( v17 >= v16->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v16,
        v16,
        v17 + (v17 >> 2));
  }
  else if ( v17 < v16->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v16,
      v16,
      v16->Size + 1);
  }
  v18 = v16->Data;
  v16->Size = v17;
  v18[v17 - 1] = arg2;
}
