void __thiscall Scaleform::GFx::AS3::Tracer::TraceBlock(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int bcp,
        const Scaleform::GFx::AS3::TR::Block *initBlock)
{
  Scaleform::GFx::AS3::TR::Block *pPrev; // eax
  unsigned int i; // ecx
  unsigned int v6; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v8; // edi
  unsigned int *Data; // edx
  unsigned __int8 v10; // cl
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode v12; // edi

  pPrev = this->Blocks.Root.pPrev;
  for ( i = bcp; pPrev; pPrev = pPrev->pPrev )
  {
    if ( bcp >= pPrev->From )
      break;
  }
  this->CurrBlock = pPrev;
  if ( (*((_BYTE *)pPrev + 8) & 1) != 0 )
  {
    if ( pPrev == initBlock )
      goto LABEL_10;
    if ( !Scaleform::GFx::AS3::Tracer::MergeBlock(
            this,
            (Scaleform::GFx::AS3::CheckResult *)&initBlock,
            pPrev,
            initBlock)->Result )
      return;
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::InitializeBlock(this, pPrev, initBlock);
  }
  i = bcp;
LABEL_10:
  if ( i < this->CodeEnd )
  {
    do
    {
      if ( this->CF->pFile->VMRef->HandleException )
        break;
      if ( !Scaleform::GFx::AS3::Tracer::UpdateBlock(this, (Scaleform::GFx::AS3::CheckResult *)&initBlock, i)->Result )
        break;
      Scaleform::GFx::AS3::Tracer::SkipDeadCode(this, &bcp);
      v6 = bcp;
      if ( bcp >= this->CodeEnd )
        break;
      this->CurrOffset = bcp;
      pHeap = this->OrigOpcodePos.Data.pHeap;
      v8 = this->OrigOpcodePos.Data.Size + 1;
      if ( v8 >= this->OrigOpcodePos.Data.Size )
      {
        if ( v8 >= this->OrigOpcodePos.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->OrigOpcodePos,
            pHeap,
            v8 + (v8 >> 2));
      }
      else if ( v8 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->OrigOpcodePos,
          pHeap,
          this->OrigOpcodePos.Data.Size + 1);
      }
      Data = this->OrigOpcodePos.Data.Data;
      this->OrigOpcodePos.Data.Size = v8;
      Data[v8 - 1] = v6;
      this->Orig2newPosMap.Data.Data[v6] = this->WCode->Data.Size;
      v10 = this->pCode[bcp];
      CurrBlock = this->CurrBlock;
      ++bcp;
      v12 = v10;
      if ( !Scaleform::GFx::AS3::Tracer::SubstituteOpCode(this, (Scaleform::GFx::AS3::VM *)v10, &bcp, CurrBlock->State) )
      {
        if ( this->CF->pFile->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::TR::State::exec_opcode(this->CurrBlock->State, v12, &bcp);
      }
      i = bcp;
    }
    while ( bcp < this->CodeEnd );
  }
}
