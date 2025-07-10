void __thiscall Scaleform::GFx::AS3::Tracer::SkipDeadCode(Scaleform::GFx::AS3::Tracer *this, unsigned int *bcp)
{
  unsigned int *v3; // edi
  unsigned int v4; // eax
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // ebp
  unsigned int *Data; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // [esp+4h] [ebp-4h]

  if ( (this->CurrBlock->Type & 1) != 0 )
  {
    v3 = bcp;
    while ( 1 )
    {
      v4 = *v3;
      v12 = *v3;
      if ( *v3 >= this->CodeEnd )
        return;
      this->CurrOffset = v4;
      pHeap = this->OrigOpcodePos.Data.pHeap;
      v6 = this->OrigOpcodePos.Data.Size + 1;
      if ( v6 >= this->OrigOpcodePos.Data.Size )
      {
        if ( v6 >= this->OrigOpcodePos.Data.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->OrigOpcodePos,
            pHeap,
            v6 + (v6 >> 2));
          goto LABEL_9;
        }
      }
      else if ( v6 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->OrigOpcodePos,
          pHeap,
          this->OrigOpcodePos.Data.Size + 1);
LABEL_9:
        v4 = v12;
      }
      Data = this->OrigOpcodePos.Data.Data;
      this->OrigOpcodePos.Data.Size = v6;
      Data[v6 - 1] = v4;
      this->Orig2newPosMap.Data.Data[v4] = this->WCode->Data.Size;
      v8 = this->pCode[*v3];
      v9 = *v3 + 1;
      *v3 = v9;
      switch ( v8 )
      {
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
          Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, v3);
          goto LABEL_22;
        case 27:
          Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, v3);
          v10 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, v3);
          if ( v10 >= 0 )
          {
            v11 = v10 + 1;
            do
            {
              Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, v3);
              --v11;
            }
            while ( v11 );
          }
          goto LABEL_22;
        case 36:
          *v3 = v9 + 1;
          goto LABEL_22;
        case 239:
          *v3 = v9 + 1;
          Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, v3);
          ++*v3;
          Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, v3);
          goto LABEL_22;
        default:
          if ( (char)(32 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v8]) >> 5 == 1 )
            goto LABEL_21;
          if ( (char)(32 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v8]) >> 5 == 2 )
          {
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, v3);
LABEL_21:
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, v3);
          }
LABEL_22:
          if ( !Scaleform::GFx::AS3::Tracer::UpdateBlock(this, (Scaleform::GFx::AS3::CheckResult *)&bcp, *v3)->Result
            || (this->CurrBlock->Type & 1) == 0 )
          {
            return;
          }
          break;
      }
    }
  }
}
