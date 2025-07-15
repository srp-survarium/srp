void __thiscall Scaleform::Render::MemoryBufferImage::MemoryBufferImage(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned int length)
{
  unsigned int Width; // eax
  unsigned int v10; // ebx
  char *v11; // eax

  this->__vftable = (Scaleform::Render::MemoryBufferImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MemoryBufferImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = sync;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::MemoryBufferImage_vtbl *)&Scaleform::Render::MemoryBufferImage::`vftable';
  this->Format = format;
  Width = size->Width;
  this->Size.Height = size->Height;
  this->Size.Width = Width;
  this->Use = use;
  this->FileData.Data.Data = 0;
  this->FileData.Data.Size = 0;
  this->FileData.Data.Policy.Capacity = 0;
  Scaleform::StringLH::StringLH(&this->FilePath);
  if ( file )
  {
    v10 = length;
    if ( !length )
      v10 = file->LGetLength(file) - filePos;
    if ( v10 >= this->FileData.Data.Size )
    {
      if ( v10 >= this->FileData.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData,
          &this->FileData,
          v10 + (v10 >> 2));
    }
    else if ( v10 < this->FileData.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData,
        &this->FileData,
        v10);
    }
    this->FileData.Data.Size = v10;
    if ( this->FileData.Data.Size == v10
      && (((void (__thiscall *)(Scaleform::File *, _DWORD, _DWORD, _DWORD))file->LSeek)(
            file,
            filePos,
            HIDWORD(filePos),
            0),
          file->Read(file, this->FileData.Data.Data, v10) >= (int)v10) )
    {
      v11 = (char *)file->GetFilePath(file);
      Scaleform::String::operator=(&this->FilePath, v11);
    }
    else
    {
      this->Format = Image_None;
    }
  }
  else
  {
    this->Format = Image_None;
  }
}
