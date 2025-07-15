void __thiscall Scaleform::GFx::AS3::TR::State::SetRegister(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::Assign(&this->Registers.Data.Data[index.Index], v);
  this->RegistersAlive.pData[(unsigned int)index.Index >> 3] |= 1 << (index.Index & 7);
}
