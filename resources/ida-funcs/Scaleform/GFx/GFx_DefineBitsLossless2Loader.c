void __stdcall Scaleform::GFx::GFx_DefineBitsLossless2Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v7; // dx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // edi
  int v9; // eax
  unsigned int v10; // eax
  unsigned __int8 v11; // dl
  Scaleform::GFx::SWFProcessInfo *v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  unsigned __int8 *v15; // ecx
  __int16 v16; // dx
  Scaleform::GFx::SWFProcessInfo *v17; // edi
  unsigned __int16 v18; // bp
  int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // ebx
  __int16 U8; // cx
  Scaleform::GFx::SWFProcessInfo *v24; // eax
  int v25; // ebp
  Scaleform::GFx::ZlibImageSource *v26; // edi
  Scaleform::File *v27; // eax
  Scaleform::Render::ImageSource *v28; // eax
  Scaleform::GFx::ZlibImageSource *v29; // edi
  Scaleform::File *v30; // eax
  Scaleform::GFx::ZlibImageSource *v31; // edi
  Scaleform::File *v32; // eax
  Scaleform::GFx::SWFProcessInfo *v33; // eax
  int v34; // ebp
  Scaleform::GFx::ZlibImageSource *v35; // edi
  Scaleform::File *UnderlyingFile; // eax
  Scaleform::GFx::ZlibImageSource *v37; // edi
  Scaleform::File *v38; // eax
  Scaleform::GFx::ZlibImageSource *v39; // edi
  Scaleform::File *v40; // eax
  unsigned __int16 pzlib; // [esp+10h] [ebp-38h]
  Scaleform::GFx::ZlibSupportBase *pzliba; // [esp+10h] [ebp-38h]
  Scaleform::Render::Size<unsigned long> v43; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::ResourceId v44; // [esp+1Ch] [ebp-2Ch]
  Scaleform::Render::Size<unsigned long> size; // [esp+20h] [ebp-28h] BYREF
  Scaleform::Render::Size<unsigned long> v46; // [esp+28h] [ebp-20h] BYREF
  Scaleform::Render::Size<unsigned long> v47; // [esp+30h] [ebp-18h] BYREF
  Scaleform::Render::Size<unsigned long> v48; // [esp+38h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> v49; // [esp+40h] [ebp-8h] BYREF
  unsigned __int8 bufferBytes; // [esp+4Ch] [ebp+4h]
  unsigned __int16 bufferBytesa; // [esp+4Ch] [ebp+4h]
  int bufferBytesb; // [esp+4Ch] [ebp+4h]
  int bufferBytesc; // [esp+4Ch] [ebp+4h]
  unsigned __int16 bufferBytesd; // [esp+4Ch] [ebp+4h]
  int bufferBytese; // [esp+4Ch] [ebp+4h]
  int bufferBytesf; // [esp+4Ch] [ebp+4h]
  Scaleform::Render::ImageSource *pimageSrc; // [esp+50h] [ebp+8h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v7 = pBuffer[Pos + 1];
  LOWORD(pBuffer) = pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  pzlib = (unsigned __int16)pBuffer | (v7 << 8);
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v9 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v9 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
  v10 = p_ProcessInfo->Stream.Pos;
  v11 = p_ProcessInfo->Stream.pBuffer[v10];
  p_ProcessInfo->Stream.Pos = v10 + 1;
  v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  bufferBytes = v11;
  if ( !v12 )
    v12 = &p->ProcessInfo;
  v13 = v12->Stream.DataSize - v12->Stream.Pos;
  v12->Stream.UnusedBits = 0;
  if ( v13 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v12->Stream, 2);
  v14 = v12->Stream.Pos;
  v15 = v12->Stream.pBuffer;
  v16 = v15[v14 + 1];
  LOWORD(v15) = v15[v14];
  v12->Stream.Pos = v14 + 2;
  v17 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v18 = (unsigned __int16)v15 | (v16 << 8);
  if ( !v17 )
    v17 = &p->ProcessInfo;
  v19 = v17->Stream.DataSize - v17->Stream.Pos;
  v17->Stream.UnusedBits = 0;
  if ( v19 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v17->Stream, 2);
  v20 = v17->Stream.Pos;
  v21 = *(unsigned __int16 *)&v17->Stream.pBuffer[v20];
  v17->Stream.Pos = v20 + 2;
  v44.Id = pzlib;
  v43.Width = v18;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>);
  pimageSrc = 0;
  pzliba = p->pLoadStates.pObject->pZlibSupport.pObject;
  if ( !pzliba )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Error: GFxZlibState is not set - can't load zipped image data\n");
    goto LABEL_44;
  }
  if ( tagInfo->TagType != Tag_DefineBitsLossless )
  {
    switch ( bufferBytes )
    {
      case 3u:
        bufferBytesd = Scaleform::GFx::LoadProcess::ReadU8(p) + 1;
        v33 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v33 )
          v33 = &p->ProcessInfo;
        v34 = tagInfo->TagLength + tagInfo->TagDataOffset + v33->Stream.DataSize - v33->Stream.FilePos - v33->Stream.Pos;
        v35 = (Scaleform::GFx::ZlibImageSource *)((int (__stdcall *)(int, _DWORD))Scaleform::Memory::pGlobalHeap->Alloc)(
                                                   64,
                                                   0);
        if ( v35 )
        {
          v47.Width = v43.Width;
          v47.Height = v21;
          UnderlyingFile = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v35,
            pzliba,
            UnderlyingFile,
            &v47,
            ColorMappedRGBA,
            Image_R8G8B8A8,
            bufferBytesd,
            v34);
          goto LABEL_43;
        }
        break;
      case 4u:
        bufferBytese = tagInfo->TagLength + tagInfo->TagDataOffset - Scaleform::GFx::LoadProcess::Tell(p);
        v37 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x40u);
        if ( v37 )
        {
          v48.Width = v18;
          v48.Height = v21;
          v38 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v37,
            pzliba,
            v38,
            &v48,
            RGB16,
            Image_R8G8B8A8,
            0,
            bufferBytese);
          goto LABEL_43;
        }
        break;
      case 5u:
        bufferBytesf = tagInfo->TagLength + tagInfo->TagDataOffset - Scaleform::GFx::LoadProcess::Tell(p);
        v39 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x40u);
        if ( v39 )
        {
          v49.Width = v18;
          v49.Height = v21;
          v40 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v39,
            pzliba,
            v40,
            &v49,
            RGBA,
            Image_R8G8B8A8,
            0,
            bufferBytesf);
          goto LABEL_43;
        }
        break;
      default:
        goto LABEL_44;
    }
    goto LABEL_42;
  }
  if ( bufferBytes != 3 )
  {
    if ( bufferBytes == 4 )
    {
      bufferBytesb = tagInfo->TagLength + tagInfo->TagDataOffset - Scaleform::GFx::LoadProcess::Tell(p);
      v29 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x40u);
      if ( v29 )
      {
        v43.Width = v18;
        v43.Height = v21;
        v30 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
        Scaleform::GFx::ZlibImageSource::ZlibImageSource(v29, pzliba, v30, &v43, RGB16, Image_R8G8B8, 0, bufferBytesb);
        goto LABEL_43;
      }
    }
    else
    {
      if ( bufferBytes != 5 )
        goto LABEL_44;
      bufferBytesc = tagInfo->TagLength + tagInfo->TagDataOffset - Scaleform::GFx::LoadProcess::Tell(p);
      v31 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x40u);
      if ( v31 )
      {
        v46.Width = v18;
        v46.Height = v21;
        v32 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
        Scaleform::GFx::ZlibImageSource::ZlibImageSource(v31, pzliba, v32, &v46, RGB24, Image_R8G8B8, 0, bufferBytesc);
        goto LABEL_43;
      }
    }
LABEL_42:
    v28 = 0;
    goto LABEL_43;
  }
  U8 = Scaleform::GFx::LoadProcess::ReadU8(p);
  v24 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  bufferBytesa = U8 + 1;
  if ( !v24 )
    v24 = &p->ProcessInfo;
  v25 = tagInfo->TagLength + tagInfo->TagDataOffset + v24->Stream.DataSize - v24->Stream.FilePos - v24->Stream.Pos;
  v26 = (Scaleform::GFx::ZlibImageSource *)((int (__stdcall *)(int, _DWORD))Scaleform::Memory::pGlobalHeap->Alloc)(
                                             64,
                                             0);
  if ( !v26 )
    goto LABEL_42;
  size.Width = v43.Width;
  size.Height = v21;
  v27 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
  Scaleform::GFx::ZlibImageSource::ZlibImageSource(
    v26,
    pzliba,
    v27,
    &size,
    ColorMappedRGB,
    Image_R8G8B8,
    bufferBytesa,
    v25);
LABEL_43:
  pimageSrc = v28;
LABEL_44:
  Scaleform::GFx::LoadProcess::AddImageResource(p, v44, pimageSrc);
  if ( pimageSrc )
    pimageSrc->Release(pimageSrc);
}
