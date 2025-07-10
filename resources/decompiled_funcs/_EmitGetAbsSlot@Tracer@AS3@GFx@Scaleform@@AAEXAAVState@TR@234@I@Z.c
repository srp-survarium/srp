void __thiscall Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        unsigned int index)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, index + 1);
}
