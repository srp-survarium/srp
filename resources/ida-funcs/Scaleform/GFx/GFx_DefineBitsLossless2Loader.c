void __stdcall Scaleform::GFx::GFx_DefineBitsLossless2Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::ImageSource *tagInfo)
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
  char *v25; // ebp
  Scaleform::GFx::ZlibImageSource *v26; // edi
  Scaleform::GFx::Resource *v27; // eax
  Scaleform::Render::ImageSource *v28; // eax
  Scaleform::GFx::ZlibImageSource *v29; // edi
  Scaleform::GFx::Resource *v30; // eax
  Scaleform::GFx::ZlibImageSource *v31; // edi
  Scaleform::GFx::Resource *v32; // eax
  Scaleform::GFx::SWFProcessInfo *v33; // eax
  char *v34; // ebp
  Scaleform::GFx::ZlibImageSource *v35; // edi
  Scaleform::GFx::Resource *UnderlyingFile; // eax
  Scaleform::GFx::ZlibImageSource *v37; // edi
  Scaleform::GFx::Resource *v38; // eax
  Scaleform::GFx::ZlibImageSource *v39; // edi
  Scaleform::GFx::Resource *v40; // eax
  Scaleform::Render::ImageSource_vtbl *v41; // [esp-14h] [ebp-5Ch]
  unsigned __int16 zlib; // [esp+10h] [ebp-38h]
  Scaleform::GFx::ZlibSupportBase *zliba; // [esp+10h] [ebp-38h]
  Scaleform::Render::Size<unsigned long> v44; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::ResourceId v45; // [esp+1Ch] [ebp-2Ch]
  Scaleform::Render::Size<unsigned long> size; // [esp+20h] [ebp-28h] BYREF
  Scaleform::Render::Size<unsigned long> v47; // [esp+28h] [ebp-20h] BYREF
  Scaleform::Render::Size<unsigned long> v48; // [esp+30h] [ebp-18h] BYREF
  Scaleform::Render::Size<unsigned long> v49; // [esp+38h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> v50; // [esp+40h] [ebp-8h] BYREF
  unsigned __int8 v51; // [esp+4Ch] [ebp+4h]
  unsigned __int16 v52; // [esp+4Ch] [ebp+4h]
  Scaleform::GFx::LoadProcess *v53; // [esp+4Ch] [ebp+4h]
  Scaleform::GFx::LoadProcess *v54; // [esp+4Ch] [ebp+4h]
  unsigned __int16 v55; // [esp+4Ch] [ebp+4h]
  Scaleform::GFx::LoadProcess *v56; // [esp+4Ch] [ebp+4h]
  Scaleform::GFx::LoadProcess *v57; // [esp+4Ch] [ebp+4h]
  Scaleform::Render::ImageSource *pimage; // [esp+50h] [ebp+8h]

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
  zlib = (unsigned __int16)pBuffer | (v7 << 8);
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
  v51 = v11;
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
  v45.Id = zlib;
  v41 = tagInfo->__vftable;
  v44.Width = v18;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  DefBitsLossless2: tagInfo.TagType = %d, id = %d, fmt = %d, w = %d, h = %d\n",
    v41,
    zlib,
    v51,
    v18,
    v21);
  pimage = 0;
  zliba = p->pLoadStates.pObject->pZlibSupport.pObject;
  if ( !zliba )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Error: GFxZlibState is not set - can't load zipped image data\n");
    goto LABEL_44;
  }
  if ( tagInfo->__vftable != (Scaleform::Render::ImageSource_vtbl *)20 )
  {
    switch ( v51 )
    {
      case 3u:
        v55 = Scaleform::GFx::LoadProcess::ReadU8(p) + 1;
        v33 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v33 )
          v33 = &p->ProcessInfo;
        v34 = (char *)tagInfo[1].__vftable
            + tagInfo[1].RefCount
            + v33->Stream.DataSize
            - v33->Stream.FilePos
            - v33->Stream.Pos;
        v35 = (Scaleform::GFx::ZlibImageSource *)((int (__stdcall *)(int, _DWORD))Scaleform::Memory::pGlobalHeap->Alloc)(
                                                   72,
                                                   0);
        if ( v35 )
        {
          v48.Width = v44.Width;
          v48.Height = v21;
          UnderlyingFile = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v35,
            (Scaleform::GFx::Resource *)zliba,
            UnderlyingFile,
            &v48,
            ColorMappedRGBA,
            Image_R8G8B8A8,
            v55,
            (int)v34);
          goto LABEL_43;
        }
        break;
      case 4u:
        v56 = (Scaleform::GFx::LoadProcess *)((char *)tagInfo[1].__vftable
                                            + tagInfo[1].RefCount
                                            - Scaleform::GFx::LoadProcess::Tell(p));
        v37 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x48u);
        if ( v37 )
        {
          v49.Width = v18;
          v49.Height = v21;
          v38 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v37,
            (Scaleform::GFx::Resource *)zliba,
            v38,
            &v49,
            RGB16,
            Image_R8G8B8A8,
            0,
            (int)v56);
          goto LABEL_43;
        }
        break;
      case 5u:
        v57 = (Scaleform::GFx::LoadProcess *)((char *)tagInfo[1].__vftable
                                            + tagInfo[1].RefCount
                                            - Scaleform::GFx::LoadProcess::Tell(p));
        v39 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x48u);
        if ( v39 )
        {
          v50.Width = v18;
          v50.Height = v21;
          v40 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::GFx::ZlibImageSource::ZlibImageSource(
            v39,
            (Scaleform::GFx::Resource *)zliba,
            v40,
            &v50,
            RGBA,
            Image_R8G8B8A8,
            0,
            (int)v57);
          goto LABEL_43;
        }
        break;
      default:
        goto LABEL_44;
    }
    goto LABEL_42;
  }
  if ( v51 != 3 )
  {
    if ( v51 == 4 )
    {
      v53 = (Scaleform::GFx::LoadProcess *)((char *)tagInfo[1].__vftable
                                          + tagInfo[1].RefCount
                                          - Scaleform::GFx::LoadProcess::Tell(p));
      v29 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x48u);
      if ( v29 )
      {
        v44.Width = v18;
        v44.Height = v21;
        v30 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
        Scaleform::GFx::ZlibImageSource::ZlibImageSource(
          v29,
          (Scaleform::GFx::Resource *)zliba,
          v30,
          &v44,
          RGB16,
          Image_R8G8B8,
          0,
          (int)v53);
        goto LABEL_43;
      }
    }
    else
    {
      if ( v51 != 5 )
        goto LABEL_44;
      v54 = (Scaleform::GFx::LoadProcess *)((char *)tagInfo[1].__vftable
                                          + tagInfo[1].RefCount
                                          - Scaleform::GFx::LoadProcess::Tell(p));
      v31 = (Scaleform::GFx::ZlibImageSource *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x48u);
      if ( v31 )
      {
        v47.Width = v18;
        v47.Height = v21;
        v32 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
        Scaleform::GFx::ZlibImageSource::ZlibImageSource(
          v31,
          (Scaleform::GFx::Resource *)zliba,
          v32,
          &v47,
          RGB24,
          Image_R8G8B8,
          0,
          (int)v54);
        goto LABEL_43;
      }
    }
LABEL_42:
    v28 = 0;
    goto LABEL_43;
  }
  U8 = Scaleform::GFx::LoadProcess::ReadU8(p);
  v24 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v52 = U8 + 1;
  if ( !v24 )
    v24 = &p->ProcessInfo;
  v25 = (char *)tagInfo[1].__vftable
      + tagInfo[1].RefCount
      + v24->Stream.DataSize
      - v24->Stream.FilePos
      - v24->Stream.Pos;
  v26 = (Scaleform::GFx::ZlibImageSource *)((int (__stdcall *)(int, _DWORD))Scaleform::Memory::pGlobalHeap->Alloc)(
                                             72,
                                             0);
  if ( !v26 )
    goto LABEL_42;
  size.Width = v44.Width;
  size.Height = v21;
  v27 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
  Scaleform::GFx::ZlibImageSource::ZlibImageSource(
    v26,
    (Scaleform::GFx::Resource *)zliba,
    v27,
    &size,
    ColorMappedRGB,
    Image_R8G8B8,
    v52,
    (int)v25);
LABEL_43:
  pimage = v28;
LABEL_44:
  Scaleform::GFx::LoadProcess::AddImageResource(p, v45, pimage);
  if ( pimage )
    pimage->Release(pimage);
}
