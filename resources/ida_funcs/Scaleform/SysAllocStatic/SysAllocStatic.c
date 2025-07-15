void __thiscall Scaleform::SysAllocStatic::SysAllocStatic(
        Scaleform::SysAllocStatic *this,
        void *mem1,
        unsigned int size1,
        void *mem2,
        unsigned int size2,
        void *mem3,
        unsigned int size3,
        void *mem4,
        unsigned int size4)
{
  Scaleform::HeapPT::AllocLite *PrivateData; // ecx
  Scaleform::HeapPT::AllocLite *v11; // eax

  PrivateData = (Scaleform::HeapPT::AllocLite *)this->PrivateData;
  this->__vftable = (Scaleform::SysAllocStatic_vtbl *)&Scaleform::SysAllocStatic::`vftable';
  this->MinSize = 4096;
  this->NumSegments = 0;
  this->pAllocator = 0;
  this->TotalSpace = 0;
  if ( PrivateData )
    Scaleform::HeapPT::AllocLite::AllocLite(PrivateData, 0x1000u);
  else
    v11 = 0;
  this->pAllocator = v11;
  if ( mem1 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem1, size1);
  if ( mem2 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem2, size2);
  if ( mem3 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem3, size3);
  if ( mem4 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem4, size4);
}
