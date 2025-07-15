void __thiscall Scaleform::HeapPT::AllocEngine::GetHeapOtherStats(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::HeapPT::HeapOtherStats *otherStats)
{
  Scaleform::HeapPT::AllocEngine *i; // eax

  otherStats->Segments = 0;
  otherStats->Bookkeeping = 0;
  otherStats->DynamicGranularity = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
  otherStats->SysDirectSpace = this->SysDirectSpace;
  for ( i = (Scaleform::HeapPT::AllocEngine *)this->SegmentList.Root.pNext;
        i != (Scaleform::HeapPT::AllocEngine *)&this->SegmentList;
        i = (Scaleform::HeapPT::AllocEngine *)i->pSysAlloc )
  {
    ++otherStats->Segments;
    otherStats->Bookkeeping += (unsigned int)i->pBookkeeper;
  }
}
