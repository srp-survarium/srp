void __thiscall Scaleform::MemoryHeap::RootHeapDesc::RootHeapDesc(Scaleform::MemoryHeap::RootHeapDesc *this)
{
  this->Flags = 0;
  this->MinAlign = 16;
  this->Granularity = 0x4000;
  this->Reserve = 0x4000;
  this->Threshold = (unsigned int)&loc_3FFFF + 1;
  this->Limit = 0;
  this->HeapId = 1;
  this->Arena = 0;
}
