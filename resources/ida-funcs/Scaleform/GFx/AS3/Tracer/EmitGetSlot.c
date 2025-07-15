char __thiscall Scaleform::GFx::AS3::Tracer::EmitGetSlot(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        const Scaleform::GFx::AS3::Value *value,
        unsigned int index,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *objOnStack)
{
  unsigned int v5; // eax
  char result; // al
  double VNumber; // [esp+8h] [ebp-8h]

  v5 = value->Flags & 0x1F;
  if ( v5 == 8 || v5 == 9 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, index + 1);
    return 1;
  }
  else
  {
    switch ( v5 )
    {
      case 0u:
        if ( (_BYTE)objOnStack )
          Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pushundefined);
        result = 1;
        break;
      case 1u:
        if ( (_BYTE)objOnStack )
          Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(
          this,
          (Scaleform::GFx::AS3::Abc::Code::OpCode)(!value->value.VS._1.VBool + 38));
        result = 1;
        break;
      case 4u:
        VNumber = value->value.VNumber;
        if ( (HIDWORD(VNumber) & 0x7FF00000) != 0x7FF00000
          || !((unsigned int)&loc_FFFFF & HIDWORD(VNumber) | LODWORD(VNumber)) )
        {
          goto LABEL_17;
        }
        if ( (_BYTE)objOnStack )
          Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pushnan);
        result = 1;
        break;
      case 0xCu:
      case 0xDu:
        result = Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, value, objOnStack);
        break;
      default:
LABEL_17:
        result = 0;
        break;
    }
  }
  return result;
}
