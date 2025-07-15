void __stdcall Scaleform::GFx::GFx_DefineBitsJpeg2Loader(
        Scaleform::RefCountVImpl *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *RefCount; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v7; // dx
  Scaleform::RefCountVImpl *v8; // eax
  unsigned __int16 v9; // cx
  void (__thiscall *AddRef)(Scaleform::RefCountVImpl *); // ebp
  Scaleform::Render::ImageSource *v11; // esi
  Scaleform::Render::ImageFileReader *Reader; // ebp
  Scaleform::RefCountVImpl_vtbl *v13; // ecx
  Scaleform::GFx::Stream *v14; // esi
  Scaleform::GFx::ResourceId v15; // [esp+18h] [ebp-18h]
  int v16; // [esp+1Ch] [ebp-14h] BYREF
  void (__thiscall *v17)(Scaleform::RefCountVImpl *); // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  int v19; // [esp+28h] [ebp-8h]
  int v20; // [esp+2Ch] [ebp-4h]
  Scaleform::RefCountVImpl *v21; // [esp+34h] [ebp+4h]

  RefCount = (Scaleform::GFx::Stream *)p[106].RefCount;
  if ( !RefCount )
    RefCount = (Scaleform::GFx::Stream *)&p[6];
  v4 = RefCount->DataSize - RefCount->Pos;
  RefCount->UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(RefCount, 2);
  Pos = RefCount->Pos;
  pBuffer = RefCount->pBuffer;
  v7 = pBuffer[Pos + 1];
  LOWORD(pBuffer) = pBuffer[Pos];
  RefCount->Pos = Pos + 2;
  v8 = (Scaleform::RefCountVImpl *)p[106].RefCount;
  v9 = (unsigned __int16)pBuffer | (v7 << 8);
  if ( !v8 )
    v8 = p + 6;
  v15.Id = v9;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p[2].RefCount,
    "  GFx_DefineBitsJpeg2Loader: charid = %d pos = 0x%x\n",
    v9,
    v8[5].RefCount + v8[6].RefCount - (unsigned int)v8[6].__vftable);
  AddRef = p[2].__vftable[2].AddRef;
  v11 = 0;
  v21 = (Scaleform::RefCountVImpl *)AddRef;
  if ( AddRef )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)AddRef);
    Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
               (Scaleform::Render::ImageFileHandlerRegistry *)((char *)AddRef + 12),
               ImageFile_JPEG);
    if ( Reader )
    {
      v13 = p[4].__vftable;
      v14 = (Scaleform::GFx::Stream *)p[106].RefCount;
      v17 = 0;
      v16 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v17 = v13[2].AddRef;
      if ( !v14 )
        v14 = (Scaleform::GFx::Stream *)&p[6];
      Scaleform::GFx::Stream::SyncFileStream(v14);
      v14->ResyncFile = 1;
      v11 = (Scaleform::Render::ImageSource *)((int (__thiscall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *, _DWORD, int, int, int))Reader->__vftable[1].~Scaleform::Render::ImageFileReader)(
                                                Reader,
                                                v14->pInput.pObject,
                                                &v16,
                                                0,
                                                tagInfo->TagLength - 2,
                                                (tagInfo->TagLength - 2) >> 31,
                                                1);
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p[2].RefCount,
        "Jpeg System is not installed - can't load jpeg image data");
    }
    Scaleform::RefCountImpl::Release(v21);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p[2].RefCount,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  Scaleform::GFx::LoadProcess::AddImageResource((Scaleform::GFx::LoadProcess *)p, v15, v11);
  if ( v11 )
    v11->Release(v11);
}
