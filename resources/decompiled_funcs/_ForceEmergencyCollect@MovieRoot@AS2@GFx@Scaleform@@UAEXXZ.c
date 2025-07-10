void __thiscall Scaleform::GFx::AS2::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::ASRefCountCollector::ForceEmergencyCollect(this->MemContext.pObject->ASGC.pObject);
}
