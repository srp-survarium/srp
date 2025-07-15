void __thiscall Scaleform::GFx::AMP::AmpStream::Append(
        Scaleform::GFx::AMP::AmpStream *this,
        unsigned __int8 *buffer,
        unsigned int bufferSize)
{
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Append(
    &this->Data.Data,
    buffer,
    bufferSize);
  this->SeekToBegin(this);
}
