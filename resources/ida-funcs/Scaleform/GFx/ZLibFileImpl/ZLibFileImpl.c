void __thiscall Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(
        Scaleform::GFx::ZLibFileImpl *this,
        Scaleform::GFx::Resource *pin)
{
  this->pIn.pObject = 0;
  if ( pin )
  {
    Scaleform::RefCountImpl::AddRef(pin);
    if ( this->pIn.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pIn.pObject);
  }
  this->pIn.pObject = (Scaleform::File *)pin;
  this->InitialStreamPos = ((int (__thiscall *)(Scaleform::GFx::Resource *))pin->__vftable[1].~Scaleform::GFx::Resource)(pin);
  this->LogicalStreamPos = 0;
  this->AtEofFlag = 0;
  this->ErrorCode = 0;
  this->ZStream.zalloc = Scaleform::GFx::AMP::ZLibAllocFunc_AMP;
  this->ZStream.zfree = Scaleform::GFx::AMP::ZLibFreeFunc_AMP;
  this->ZStream.opaque = this;
  this->ZStream.next_in = 0;
  this->ZStream.avail_in = 0;
  this->ZStream.next_out = 0;
  this->ZStream.avail_out = 0;
  this->ZStream.data_type = 0;
  this->ZStream.adler = 0;
  this->ZStream.reserved = 0;
  if ( inflateInit_(&this->ZStream, "1.2.7", 56) )
  {
    this->ErrorCode = 1;
  }
  else
  {
    this->BacktrackSize = 0;
    this->BacktrackTail = 0;
    this->UserPos = 0;
  }
}
