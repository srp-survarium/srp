void __thiscall Scaleform::Render::JPEG::TablesHeader::TablesHeader(
        Scaleform::Render::JPEG::TablesHeader *this,
        Scaleform::MemoryHeap *heap,
        unsigned int sz)
{
  this->__vftable = (Scaleform::Render::JPEG::TablesHeader_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Size = sz;
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::JPEG::TablesHeader_vtbl *)&Scaleform::Render::JPEG::ExtraData::`vftable';
  this->Data = (unsigned __int8 *)heap->Alloc(heap, sz, 0);
  this->__vftable = (Scaleform::Render::JPEG::TablesHeader_vtbl *)&Scaleform::Render::JPEG::TablesHeader::`vftable';
}
