Scaleform::Render::ImageSource *__cdecl Scaleform::GFx::LoaderImpl::LoadBuiltinImage(
        Scaleform::File *pfile,
        Scaleform::GFx::FileTypeConstants::FileFormatType format,
        Scaleform::GFx::Resource::ResourceUse __formal,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::Log *plog,
        Scaleform::MemoryHeap *pimageHeap)
{
  const char *v7; // ecx
  Scaleform::Render::ImageFileFormat v8; // esi
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // ebp
  Scaleform::Render::ImageFileReader *Reader; // eax
  Scaleform::Render::ImageSource *(__thiscall *ReadImageSource)(Scaleform::Render::ImageFileReader *, Scaleform::File *, const Scaleform::Render::ImageCreateArgs *); // edx
  Scaleform::Render::ImageSource *pimageSrc; // [esp+Ch] [ebp-18h]
  Scaleform::Render::ImageCreateArgs args; // [esp+10h] [ebp-14h] BYREF
  const char *pfilePath; // [esp+28h] [ebp+4h]

  pimageSrc = 0;
  pfilePath = pfile->GetFilePath(pfile);
  v8 = Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(format);
  if ( v8 == ImageFile_Unknown )
  {
    if ( plog )
      Scaleform::Log::LogMessage(plog, "Default image loader failed to load '%s'", v7);
    return 0;
  }
  else
  {
    pObject = pls->pImageFileHandlerRegistry.pObject;
    if ( pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pls->pImageFileHandlerRegistry.pObject);
      Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
                 &pObject->Scaleform::Render::ImageFileHandlerRegistry,
                 v8);
      if ( Reader )
      {
        ReadImageSource = Reader->ReadImageSource;
        args.pHeap = pimageHeap;
        args.Use = 0;
        memset(&args.pManager, 0, 12);
        pimageSrc = ReadImageSource(Reader, pfile, &args);
      }
      else if ( plog )
      {
        Scaleform::Log::LogError(plog, "Can't load image %s - appropriate reader is not installed.", pfilePath);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
        return 0;
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
    }
    else if ( plog )
    {
      Scaleform::Log::LogError(plog, "Image file handler registry is not installed - can't load image data");
      return 0;
    }
    return pimageSrc;
  }
}
