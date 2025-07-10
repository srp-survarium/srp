void __thiscall Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st)
{
  unsigned int Size; // eax
  unsigned int v3; // eax

  Size = this->NewOpcodePos.Data.Size;
  if ( Size )
    v3 = this->WCode->Data.Data[this->NewOpcodePos.Data.Data[Size - 1]];
  else
    v3 = 2;
  switch ( v3 )
  {
    case 0x20u:
    case 0x21u:
    case 0x24u:
    case 0x25u:
    case 0x26u:
    case 0x27u:
    case 0x28u:
    case 0x2Au:
    case 0x2Cu:
    case 0x2Du:
    case 0x2Eu:
    case 0x2Fu:
    case 0x31u:
    case 0x60u:
    case 0x62u:
    case 0x64u:
    case 0x65u:
    case 0x67u:
    case 0x6Eu:
    case 0xB5u:
    case 0xD0u:
    case 0xD1u:
    case 0xD2u:
    case 0xD3u:
      Scaleform::GFx::AS3::Tracer::PopNewOpCode(this);
      break;
    default:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
      break;
  }
}
