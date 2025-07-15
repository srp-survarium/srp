char __thiscall Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int *bcp,
        unsigned int ccp,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::BuiltinTraitsType src_reg_num)
{
  unsigned int v5; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH_POD<unsigned int,328,Scaleform::ArrayDefaultPolicy> *p_OrigOpcodePos; // edi
  unsigned int v9; // esi
  unsigned int v10; // ecx
  unsigned int *Data; // eax
  const unsigned __int8 *pCode; // eax
  int v13; // edx
  unsigned int v14; // esi
  int v15; // eax
  int v16; // eax
  int TraitsType; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  const Scaleform::GFx::AS3::Value *reg; // [esp+10h] [ebp-8h]
  __int32 v22; // [esp+14h] [ebp-4h]

  v5 = src_reg_num;
  reg = &st->Registers.Data.Data[src_reg_num];
  src_reg_num = this->pCode[ccp++];
  v22 = src_reg_num - 145;
  switch ( src_reg_num )
  {
    case 145:
    case 147:
    case 192:
    case 193:
      pHeap = this->OrigOpcodePos.Data.pHeap;
      p_OrigOpcodePos = &this->OrigOpcodePos;
      v9 = this->OrigOpcodePos.Data.Size + 1;
      if ( v9 >= this->OrigOpcodePos.Data.Size )
      {
        if ( v9 >= this->OrigOpcodePos.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)p_OrigOpcodePos,
            pHeap,
            v9 + (v9 >> 2));
      }
      else if ( v9 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)p_OrigOpcodePos,
          pHeap,
          this->OrigOpcodePos.Data.Size + 1);
      }
      v10 = ccp;
      Data = p_OrigOpcodePos->Data.Data;
      this->OrigOpcodePos.Data.Size = v9;
      Data[v9 - 1] = v10;
      pCode = this->pCode;
      v13 = pCode[ccp++];
      v14 = 1;
      switch ( v13 )
      {
        case 's':
          src_reg_num = Traits_SInt;
          goto LABEL_11;
        case 't':
          src_reg_num = Traits_UInt;
          goto LABEL_11;
        case 'u':
          src_reg_num = Traits_Number;
LABEL_11:
          Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            &this->OrigOpcodePos,
            &ccp);
          pCode = this->pCode;
          v13 = pCode[ccp];
          v14 = 2;
          ++ccp;
          goto LABEL_12;
      }
      if ( src_reg_num < 192 || src_reg_num > 193 )
        src_reg_num = Traits_Number;
      else
        src_reg_num = Traits_SInt;
LABEL_12:
      switch ( v13 )
      {
        case 99:
          v15 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, &ccp);
          goto LABEL_24;
        case 212:
          v15 = 0;
          goto LABEL_24;
        case 213:
          v15 = 1;
          goto LABEL_24;
        case 214:
          v15 = 2;
          goto LABEL_24;
        case 215:
          v15 = 3;
LABEL_24:
          if ( v15 != v5 )
            goto LABEL_58;
          v16 = reg->Flags & 0x1F;
          TraitsType = 4;
          if ( v16 )
          {
            if ( (unsigned int)(v16 - 8) < 2 )
              ITr = reg->value.VS._1.ITr;
            else
              ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                     this->CF->pFile->VMRef,
                                                                     reg);
          }
          else
          {
            ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
          }
          if ( ITr )
          {
            VMRef = this->CF->pFile->VMRef;
            if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
              ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
            if ( ITr && (ITr->Flags & 0x20) == 0 )
              TraitsType = ITr->TraitsType;
          }
          break;
        default:
LABEL_58:
          Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PopBack(
            &this->OrigOpcodePos,
            v14);
          return 0;
      }
      break;
    default:
      return 0;
  }
  switch ( v22 )
  {
    case 0:
    case 47:
      if ( TraitsType != src_reg_num )
      {
        if ( src_reg_num != Traits_SInt )
        {
LABEL_41:
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_inclocal, v5);
          Scaleform::GFx::AS3::TR::State::exec_convert_reg_d(st, v5);
          goto LABEL_42;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_inclocal_i, v5);
        goto LABEL_47;
      }
      if ( TraitsType == 2 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_inclocal_ti, v5);
        goto LABEL_47;
      }
      if ( TraitsType != 3 )
      {
        if ( TraitsType != 4 )
          goto LABEL_42;
        goto LABEL_41;
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_inclocal_tu, v5);
      Scaleform::GFx::AS3::TR::State::exec_convert_reg_u(st, v5);
      goto LABEL_42;
    case 2:
    case 48:
      if ( TraitsType != src_reg_num )
      {
        if ( src_reg_num != Traits_SInt )
        {
LABEL_52:
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_declocal, v5);
          Scaleform::GFx::AS3::TR::State::exec_convert_reg_d(st, v5);
          goto LABEL_42;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_declocal_i, v5);
        goto LABEL_47;
      }
      if ( TraitsType == 2 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_declocal_ti, v5);
LABEL_47:
        Scaleform::GFx::AS3::TR::State::exec_convert_reg_i(st, v5);
        goto LABEL_42;
      }
      if ( TraitsType != 3 )
      {
        if ( TraitsType != 4 )
          goto LABEL_42;
        goto LABEL_52;
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_declocal_tu, v5);
      Scaleform::GFx::AS3::TR::State::exec_convert_reg_u(st, v5);
LABEL_42:
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
      return 1;
    default:
      return 0;
  }
}
