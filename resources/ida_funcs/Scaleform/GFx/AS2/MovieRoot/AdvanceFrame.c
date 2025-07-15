void __thiscall Scaleform::GFx::AS2::MovieRoot::AdvanceFrame(Scaleform::GFx::AS2::MovieRoot *this, bool nextFrame)
{
  if ( nextFrame )
    Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(
      this->MemContext.pObject->ASGC.pObject,
      &this->NumAdvancesSinceCollection,
      &this->LastCollectionFrame);
}
