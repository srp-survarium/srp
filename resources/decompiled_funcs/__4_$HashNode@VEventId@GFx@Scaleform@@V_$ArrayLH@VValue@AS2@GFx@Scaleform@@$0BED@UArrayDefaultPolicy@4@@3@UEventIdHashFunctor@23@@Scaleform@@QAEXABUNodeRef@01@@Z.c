void __thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::EventId *pFirst; // eax

  pFirst = src->pFirst;
  this->First.Id = src->pFirst->Id;
  this->First.WcharCode = pFirst->WcharCode;
  this->First.KeyCode = pFirst->KeyCode;
  this->First.AsciiCode = pFirst->AsciiCode;
  this->First.RollOverCnt = pFirst->RollOverCnt;
  this->First.ControllerIndex = pFirst->ControllerIndex;
  this->First.KeysState.States = pFirst->KeysState.States;
  this->First.MouseWheelDelta = pFirst->MouseWheelDelta;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &this->Second,
    src->pSecond);
}
