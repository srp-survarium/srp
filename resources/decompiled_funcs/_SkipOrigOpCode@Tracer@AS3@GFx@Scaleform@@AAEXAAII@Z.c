void __thiscall Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int *opcode_cp,
        unsigned int new_cp)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH_POD<unsigned int,328,Scaleform::ArrayDefaultPolicy> *p_OrigOpcodePos; // edi
  unsigned int v6; // esi
  unsigned int *Data; // eax

  if ( *opcode_cp >= this->CodeEnd )
  {
    *opcode_cp = new_cp;
  }
  else
  {
    pHeap = this->OrigOpcodePos.Data.pHeap;
    p_OrigOpcodePos = &this->OrigOpcodePos;
    v6 = this->OrigOpcodePos.Data.Size + 1;
    if ( v6 >= this->OrigOpcodePos.Data.Size )
    {
      if ( v6 >= this->OrigOpcodePos.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)p_OrigOpcodePos,
          pHeap,
          v6 + (v6 >> 2));
    }
    else if ( v6 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)p_OrigOpcodePos,
        pHeap,
        v6);
    }
    Data = p_OrigOpcodePos->Data.Data;
    this->OrigOpcodePos.Data.Size = v6;
    Data[v6 - 1] = *opcode_cp;
    this->Orig2newPosMap.Data.Data[*opcode_cp] = this->WCode->Data.Size;
    *opcode_cp = new_cp;
  }
}
