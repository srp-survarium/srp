void __thiscall survarium::vostok_file_opener::OpenFile(
        survarium::vostok_file_opener *this,
        char *purl,
        int flags,
        int mode)
{
  Scaleform::MemoryFile *v5; // eax

  if ( this->cached_file.raw_data )
  {
    v5 = (Scaleform::MemoryFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 28, 0);
    if ( v5 )
      Scaleform::MemoryFile::MemoryFile(
        v5,
        purl,
        (const unsigned __int8 *)this->cached_file.raw_data,
        this->cached_file.raw_data_size);
  }
  else
  {
    Scaleform::GFx::FileOpener::OpenFile(this, purl, flags, mode);
  }
}
