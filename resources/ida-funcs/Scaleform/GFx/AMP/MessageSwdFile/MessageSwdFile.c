void __thiscall Scaleform::GFx::AMP::MessageSwdFile::MessageSwdFile(
        Scaleform::GFx::AMP::MessageSwdFile *this,
        unsigned int swfHandle,
        unsigned __int8 *bufferData,
        unsigned int bufferSize,
        const __m128i *filename)
{
  Scaleform::ArrayLH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_FileData; // esi
  unsigned int v7; // eax

  this->__vftable = (Scaleform::GFx::AMP::MessageSwdFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageSwdFile_vtbl *)&Scaleform::GFx::AMP::MessageSwdFile::`vftable';
  this->Handle = swfHandle;
  p_FileData = &this->FileData;
  this->FileData.Data.Data = 0;
  this->FileData.Data.Size = 0;
  this->FileData.Data.Policy.Capacity = 0;
  Scaleform::StringLH::StringLH(&this->Filename, filename);
  if ( bufferSize >= this->FileData.Data.Size )
  {
    if ( bufferSize >= this->FileData.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData,
        &this->FileData,
        bufferSize + (bufferSize >> 2));
  }
  else if ( bufferSize < this->FileData.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData,
      &this->FileData,
      bufferSize);
  }
  v7 = 0;
  for ( this->FileData.Data.Size = bufferSize; v7 < bufferSize; ++v7 )
    p_FileData->Data.Data[v7] = bufferData[v7];
}
