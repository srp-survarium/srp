char __thiscall Scaleform::GFx::AS3::Tracer::EmitSetProperty(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Traits *opcode,
        const Scaleform::GFx::AS3::TR::ReadValueMnObject *args,
        int mn_index)
{
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *p_ArgMN; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // ebp
  const Scaleform::GFx::AS3::Traits *v9; // ecx
  int v10; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  const Scaleform::GFx::AS3::SlotInfo *v12; // ebp
  int v13; // eax
  Scaleform::GFx::AS3::VM *VMRef; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS3::TR::State *st; // [esp+10h] [ebp-4h]
  const Scaleform::GFx::AS3::Traits *obj_tr; // [esp+18h] [ebp+4h]

  st = args->StateRef;
  p_ArgMN = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args->ArgMN;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(
                  this,
                  &args->ArgObject,
                  opcode == (const Scaleform::GFx::AS3::Traits *)5);
  Data = p_ArgMN->Data.Data;
  v9 = ValueTraits;
  v10 = (int)p_ArgMN->Data.Data & 3;
  obj_tr = v9;
  if ( v10 == 1 || ((unsigned __int8)Data & 4) != 0 || ((unsigned __int8)Data & 8) != 0 || !v10 && !p_ArgMN->Data.Size )
    goto LABEL_21;
  if ( !v9 )
    goto LABEL_21;
  VMRef = this->CF->pFile->VMRef;
  args = 0;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                (const Scaleform::GFx::AS3::SlotInfo *)VMRef,
                v9,
                p_ArgMN,
                (unsigned int *)&args,
                0);
  v12 = FixedSlot;
  if ( !FixedSlot )
    goto LABEL_21;
  v13 = (int)(*(_DWORD *)FixedSlot << 22) >> 27;
  if ( v13 > 10 )
  {
    if ( (*(_DWORD *)v12 & 0x4000000) == 0 && (obj_tr->Flags & 4) == 0 && v13 > 12 )
    {
      if ( ((int)p_ArgMN->Data.Data & 4) != 0 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_swap);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        this,
        (Scaleform::GFx::AS3::Abc::Code::OpCode)(opcode != (const Scaleform::GFx::AS3::Traits *)5
                                               ? op_callmethod
                                               : op_callsupermethod),
        ((32 * *(_DWORD *)v12) >> 15) + 1,
        1u);
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
      return 1;
    }
LABEL_21:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)opcode, mn_index);
    return 1;
  }
  if ( ((int)p_ArgMN->Data.Data & 4) != 0 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_swap);
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
  }
  if ( opcode == (const Scaleform::GFx::AS3::Traits *)104 )
    Scaleform::GFx::AS3::Tracer::EmitInitAbsSlot(this, st, (unsigned int)args);
  else
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_setabsslot, (unsigned int)&args->VMRef + 1);
  return 1;
}
