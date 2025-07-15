void __thiscall Scaleform::GFx::AMP::AmpStream::AmpStream(
        Scaleform::GFx::AMP::AmpStream *this,
        unsigned __int8 *buffer,
        unsigned int bufferSize)
{
  Scaleform::ArrayLH<unsigned char,2,Scaleform::ArrayConstPolicy<0,4,1> > *p_Data; // ecx

  this->__vftable = (Scaleform::GFx::AMP::AmpStream_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  p_Data = &this->Data;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::AmpStream_vtbl *)&Scaleform::GFx::AMP::AmpStream::`vftable';
  p_Data->Data.Data = 0;
  p_Data->Data.Size = 0;
  p_Data->Data.Policy.Capacity = 0;
  this->readPosition = 0;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Append(
    &p_Data->Data,
    buffer,
    bufferSize);
  this->SeekToBegin(this);
}


void __thiscall Scaleform::GFx::AMP::AmpStream::AmpStream(Scaleform::GFx::AMP::AmpStream *this)
{
  this->__vftable = (Scaleform::GFx::AMP::AmpStream_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::AmpStream_vtbl *)&Scaleform::GFx::AMP::AmpStream::`vftable';
  this->Data.Data.Data = 0;
  this->Data.Data.Size = 0;
  this->Data.Data.Policy.Capacity = 0;
  this->readPosition = 0;
}
