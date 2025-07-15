void __thiscall Scaleform::FILEFile::init(Scaleform::FILEFile *this)
{
  int OpenFlags; // eax
  char *v3; // ebp
  int v4; // ebx
  int Length; // eax
  wchar_t *v6; // esi
  _iobuf **p_fs; // ebp
  bool v8; // al
  UINT uMode; // [esp+14h] [ebp-24h]
  wchar_t mode[16]; // [esp+18h] [ebp-20h] BYREF

  OpenFlags = this->OpenFlags;
  v3 = "rb";
  if ( (OpenFlags & 4) != 0 )
  {
    if ( (OpenFlags & 1) != 0 )
      v3 = "w+b";
    else
      v3 = "wb";
  }
  else if ( (OpenFlags & 8) != 0 )
  {
    if ( (OpenFlags & 1) != 0 )
      v3 = "a+b";
    else
      v3 = "ab";
  }
  else if ( (OpenFlags & 2) != 0 )
  {
    v3 = "r+b";
  }
  if ( (this->FileName.HeapTypeBits & 0xFFFFFFFC) != 0xFFFFFFF8
    && *(_BYTE *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8)
    && *(_BYTE *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 9) == 58 )
  {
    v4 = 1;
    uMode = SetErrorMode(1u);
  }
  else
  {
    v4 = 0;
  }
  Length = Scaleform::UTF8Util::GetLength((char *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8), -1);
  v6 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * Length + 2, 0);
  Scaleform::UTF8Util::DecodeString(v6, (char *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8), -1);
  Scaleform::UTF8Util::DecodeString(mode, v3, -1);
  p_fs = &this->fs;
  _wfopen_s(&this->fs, v6, mode);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( this->fs )
    rewind(*p_fs);
  v8 = *p_fs != 0;
  this->Opened = v8;
  if ( v8 )
  {
    this->ErrorCode = 0;
  }
  else if ( *_errno() == 2 )
  {
    this->ErrorCode = 4097;
  }
  else if ( *_errno() == 13 || *_errno() == 1 )
  {
    this->ErrorCode = 4098;
  }
  else
  {
    this->ErrorCode = (*_errno() == 28) + 4099;
  }
  this->LastOp = 0;
  if ( v4 )
    SetErrorMode(uMode);
}
