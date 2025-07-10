unsigned int __thiscall Scaleform::HeapPT::SysAllocGranulator::GetFootprint(
        Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint + this->pGranulator->Footprint;
}
