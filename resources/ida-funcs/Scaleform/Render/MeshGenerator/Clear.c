void __thiscall Scaleform::Render::MeshGenerator::Clear(Scaleform::Render::MeshGenerator *this)
{
  this->mTess.Clear(&this->mTess);
  this->mStroker.Clear(&this->mStroker);
  this->mStrokeSorter.Clear(&this->mStrokeSorter);
  this->mHairliner.Clear(&this->mHairliner);
  this->mStrokerAA.Clear(&this->mStrokerAA);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap1);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap3);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap4);
}
