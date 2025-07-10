char __thiscall Scaleform::GFx::SWFProcessInfo::Initialize(
        Scaleform::GFx::SWFProcessInfo *this,
        Scaleform::GFx::Resource *pin,
        Scaleform::GFx::LogState *plog,
        Scaleform::GFx::ZlibSupportBase *zlib,
        Scaleform::GFx::ParseControl *pparseControl,
        int parseMsg)
{
  Scaleform::GFx::Resource *v6; // edi
  unsigned int (__thiscall *GetResourceTypeCode)(Scaleform::GFx::Resource *); // edx
  unsigned int (__thiscall *v9)(Scaleform::GFx::Resource *); // edx
  Scaleform::File *v10; // ebp
  unsigned int v11; // eax
  int v12; // edx
  bool v13; // zf
  bool v14; // bl
  char *v15; // ecx
  Scaleform::File *v17; // ebp
  Scaleform::GFx::ZlibSupportBase *v18; // ebp
  Scaleform::GFx::LogState *v19; // edi
  Scaleform::Log *pObject; // eax
  signed int v21; // eax
  unsigned int Pos; // eax
  unsigned int DataSize; // ecx
  double v24; // st7
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int v27; // eax
  unsigned int v28; // edi
  signed int v29; // ecx
  unsigned int v30; // eax
  unsigned __int16 v31; // dx
  signed int v32; // ecx
  unsigned int v33; // eax
  unsigned __int16 v34; // dx
  int TagOffset; // [esp-4h] [ebp-28h]
  unsigned int v36; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::TagInfo tagInfo; // [esp+14h] [ebp-10h] BYREF

  v6 = pin;
  this->FileStartPos = ((int (__thiscall *)(Scaleform::GFx::Resource *))pin->__vftable[1].~Scaleform::GFx::Resource)(pin);
  GetResourceTypeCode = v6->__vftable[2].GetResourceTypeCode;
  v36 = 0;
  ((void (__thiscall *)(Scaleform::GFx::Resource *, unsigned int *, int))GetResourceTypeCode)(v6, &v36, 4);
  v9 = v6->__vftable[2].GetResourceTypeCode;
  pin = 0;
  ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::Resource **, int))v9)(v6, &pin, 4);
  v10 = (Scaleform::File *)pin;
  this->FileEndPos = (unsigned int)pin + this->FileStartPos;
  v11 = v36;
  v12 = HIBYTE(v36);
  v13 = (_BYTE)v36 == 67;
  this->NextActionBlock = 0;
  this->Header.SWFFlags = 0;
  v14 = v13;
  this->FileAttributes = 0;
  v15 = (char *)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & v11);
  this->Header.FileLength = (unsigned int)v10;
  this->Header.Version = v12;
  if ( (_UNKNOWN *)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & v11) != &loc_535746
    && v15 != (char *)&loc_535741 + 2
    && v15 != (_BYTE *)&loc_584645 + 2
    && v15 != (_BYTE *)vostok::physics::parallelComponent + 3 )
  {
    if ( plog )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Loader read failed - file does not start with a SWF header");
    return 0;
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & v11) == 0x580000 )
    this->Header.SWFFlags = 16;
  if ( v13 )
    this->Header.SWFFlags |= 1u;
  if ( plog && pparseControl && (pparseControl->ParseFlags & 1) != 0 )
  {
    if ( (_BYTE)parseMsg )
      Scaleform::GFx::LogState::LogMessageByType(
        plog,
        (Scaleform::LogMessageId)20480,
        "SWF File version = %d, File length = %d\n",
        v12,
        v10);
  }
  else
  {
    LOBYTE(parseMsg) = 0;
  }
  Scaleform::RefCountImpl::AddRef(v6);
  v17 = (Scaleform::File *)v6;
  if ( v14 )
  {
    v18 = zlib;
    if ( !zlib )
    {
      if ( plog )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Loader - unable to read compressed SWF data; GFxZlibState is not set.");
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
      return 0;
    }
    if ( (_BYTE)parseMsg )
      Scaleform::GFx::LogState::LogMessageByType(plog, (Scaleform::LogMessageId)20480, "SWF file is compressed.\n");
    v17 = v18->CreateZlibFile(v18, (Scaleform::File *)v6);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    this->FileEndPos = this->Header.FileLength - 8;
  }
  v19 = plog;
  pObject = plog->pLog.pObject;
  if ( !pObject )
    pObject = Scaleform::Log::GetGlobalLog();
  Scaleform::GFx::Stream::Initialize(&this->Stream, v17, pObject, pparseControl);
  Scaleform::GFx::Stream::ReadRect(&this->Stream, &this->Header.FrameRect);
  v21 = this->Stream.DataSize - this->Stream.Pos;
  this->Stream.UnusedBits = 0;
  if ( v21 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
  Pos = this->Stream.Pos;
  DataSize = this->Stream.DataSize;
  parseMsg = *(unsigned __int16 *)&this->Stream.pBuffer[Pos];
  Pos += 2;
  v24 = (double)parseMsg;
  this->Stream.Pos = Pos;
  this->Stream.UnusedBits = 0;
  this->Header.FPS = v24 * 0.00390625;
  if ( (int)(DataSize - Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
  v25 = this->Stream.Pos;
  v26 = *(unsigned __int16 *)&this->Stream.pBuffer[v25];
  v27 = v25 + 2;
  v13 = (this->Header.SWFFlags & 0x10) == 0;
  this->Stream.Pos = v27;
  this->Header.FrameCount = v26;
  if ( v13 )
  {
    if ( this->Header.Version < 9 || v27 + this->Stream.FilePos - this->Stream.DataSize >= this->FileEndPos )
      goto LABEL_56;
    if ( Scaleform::GFx::Stream::OpenTag(&this->Stream, &tagInfo) == Tag_FileAttributes )
    {
      v32 = this->Stream.DataSize - this->Stream.Pos;
      this->Stream.UnusedBits = 0;
      if ( v32 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
      v33 = this->Stream.Pos;
      v34 = *(_WORD *)&this->Stream.pBuffer[v33];
      this->Stream.Pos = v33 + 2;
      this->FileAttributes = v34;
    }
    Scaleform::GFx::Stream::CloseTag(&this->Stream);
    TagOffset = tagInfo.TagOffset;
    goto LABEL_55;
  }
  if ( this->Stream.FilePos + v27 - this->Stream.DataSize >= this->FileEndPos )
  {
LABEL_36:
    if ( this->Header.Version < 9 )
      goto LABEL_56;
    v28 = this->Stream.FilePos - this->Stream.DataSize + this->Stream.Pos;
    if ( v28 >= this->FileEndPos )
      goto LABEL_56;
    while ( Scaleform::GFx::Stream::OpenTag(&this->Stream, &tagInfo) >= Tag_ExporterInfo )
      Scaleform::GFx::Stream::CloseTag(&this->Stream);
    if ( tagInfo.TagType == Tag_FileAttributes )
    {
      v29 = this->Stream.DataSize - this->Stream.Pos;
      this->Stream.UnusedBits = 0;
      if ( v29 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
      v30 = this->Stream.Pos;
      v31 = *(_WORD *)&this->Stream.pBuffer[v30];
      this->Stream.Pos = v30 + 2;
      this->FileAttributes = v31;
    }
    Scaleform::GFx::Stream::CloseTag(&this->Stream);
    TagOffset = v28;
LABEL_55:
    Scaleform::GFx::Stream::SetPosition(&this->Stream, TagOffset);
LABEL_56:
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
    return 1;
  }
  if ( Scaleform::GFx::Stream::OpenTag(&this->Stream) == Tag_ExporterInfo )
  {
    Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(
      &this->Header.mExporterInfo,
      (Scaleform::String)this,
      Tag_ExporterInfo);
    Scaleform::GFx::Stream::CloseTag(&this->Stream);
    goto LABEL_36;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
    &v19->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
    "Loader read failed - no mExporterInfo tag in GFX file header");
  if ( v17 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
  return 0;
}
