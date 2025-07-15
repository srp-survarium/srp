void __thiscall Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
        Scaleform::Render::FileHeaderReaderImpl *this,
        Scaleform::File *file,
        unsigned __int8 *header,
        unsigned int headerSize,
        unsigned __int8 *tempBuffer,
        unsigned __int8 sizeNeeded)
{
  __int64 v7; // rax
  int v8; // edi
  int v9; // ebx
  int v10; // ebp
  int v12; // [esp+2Ch] [ebp+14h]

  this->pHeader = 0;
  if ( file && file->IsValid(file) )
  {
    if ( header && headerSize >= sizeNeeded )
    {
      this->pHeader = header;
    }
    else
    {
      v7 = file->LTell(file);
      v8 = sizeNeeded;
      v9 = HIDWORD(v7);
      v10 = v7;
      v12 = file->Read(file, tempBuffer, sizeNeeded);
      ((void (__thiscall *)(Scaleform::File *, int, int, _DWORD))file->LSeek)(file, v10, v9, 0);
      if ( v12 >= v8 )
        this->pHeader = tempBuffer;
    }
  }
}
