void __thiscall Scaleform::GFx::AS3::Tracer::EmitInitAbsSlot(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        unsigned int index)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_initabsslot, index + 1);
}
