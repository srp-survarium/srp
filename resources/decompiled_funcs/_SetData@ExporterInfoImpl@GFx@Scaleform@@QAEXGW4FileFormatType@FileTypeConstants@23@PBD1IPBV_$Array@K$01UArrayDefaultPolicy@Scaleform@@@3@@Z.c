void __thiscall Scaleform::GFx::ExporterInfoImpl::SetData(
        Scaleform::GFx::ExporterInfoImpl *this,
        unsigned __int16 version,
        Scaleform::GFx::FileTypeConstants::FileFormatType format,
        char *pname,
        char *pprefix,
        unsigned int flags,
        const Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *codeOffsets)
{
  char *v8; // eax
  Scaleform::String *p_Prefix; // ebx
  char *v10; // eax
  unsigned int v11; // edx
  Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_CodeOffsets; // ecx

  this->SI.Version = version;
  v8 = pprefix;
  this->SI.Format = format;
  if ( !pprefix )
    v8 = (char *)&buf;
  p_Prefix = &this->Prefix;
  Scaleform::String::operator=(&this->Prefix, v8);
  v10 = pname;
  if ( !pname )
    v10 = (char *)&buf;
  Scaleform::String::operator=(&this->SWFName, v10);
  v11 = this->SWFName.HeapTypeBits & 0xFFFFFFFC;
  this->SI.pPrefix = (const char *)((p_Prefix->HeapTypeBits & 0xFFFFFFFC) + 8);
  this->SI.ExportFlags = flags;
  this->SI.pSWFName = (const char *)(v11 + 8);
  p_CodeOffsets = &this->CodeOffsets;
  if ( codeOffsets )
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      p_CodeOffsets,
      codeOffsets);
  else
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Clear(p_CodeOffsets);
}
