void __thiscall Scaleform::GFx::Stream::Stream(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::Resource *pinput,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::Stream::`vftable';
  this->pInput.pObject = 0;
  Scaleform::StringDH::StringDH(&this->FileName, pheap);
  this->pBuffer = this->BuiltinBuffer;
  this->BufferSize = 512;
  Scaleform::GFx::Stream::Initialize(this, pinput, plog, pparseControl);
}
