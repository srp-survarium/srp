void __thiscall Scaleform::HeapPT::Starter::Starter(
        Scaleform::HeapPT::Starter *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned int granularity,
        unsigned int headerPageSize)
{
  Scaleform::HeapPT::Granulator::Granulator(&this->Allocator, sysAlloc, 0x100u, granularity, headerPageSize);
}
