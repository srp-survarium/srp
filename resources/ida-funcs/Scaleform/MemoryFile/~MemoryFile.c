void __thiscall Scaleform::MemoryFile::~MemoryFile(Scaleform::MemoryFile *this)
{
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(this->FilePath.HeapTypeBits & 0xFFFFFFFC));
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
