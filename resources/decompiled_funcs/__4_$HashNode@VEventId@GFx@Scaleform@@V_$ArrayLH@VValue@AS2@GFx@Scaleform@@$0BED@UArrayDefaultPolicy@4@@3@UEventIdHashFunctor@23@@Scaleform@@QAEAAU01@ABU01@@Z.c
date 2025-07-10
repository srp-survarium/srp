Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *__that)
{
  this->First.Id = __that->First.Id;
  this->First.WcharCode = __that->First.WcharCode;
  this->First.KeyCode = __that->First.KeyCode;
  this->First.AsciiCode = __that->First.AsciiCode;
  this->First.RollOverCnt = __that->First.RollOverCnt;
  this->First.ControllerIndex = __that->First.ControllerIndex;
  this->First.KeysState.States = __that->First.KeysState.States;
  this->First.MouseWheelDelta = __that->First.MouseWheelDelta;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &this->Second,
    &__that->Second);
  return this;
}
