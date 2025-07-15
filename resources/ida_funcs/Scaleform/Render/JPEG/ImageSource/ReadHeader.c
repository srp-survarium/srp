char __thiscall Scaleform::Render::JPEG::ImageSource::ReadHeader(Scaleform::Render::JPEG::ImageSource *this)
{
  Scaleform::Render::JPEG::ExtraData *pObject; // ecx
  Scaleform::Render::JPEG::Input *SwfJpeg2HeaderOnly; // eax
  jpeg_decompress_struct *v5; // edi
  Scaleform::Render::JPEG::Input *v6; // eax
  Scaleform::Render::JPEG::Input *pOriginalInput; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  Scaleform::GFx::Resource *v10; // [esp-4h] [ebp-10h]
  Scaleform::Render::Size<unsigned long> v11; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pExtraData.pObject;
  if ( pObject && pObject->IsTableHeader(pObject) )
  {
    SwfJpeg2HeaderOnly = Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
                           &Scaleform::Render::JPEG::FileReader::Instance,
                           this->pExtraData.pObject->Data,
                           this->pExtraData.pObject->Size);
    this->pOriginalInput = SwfJpeg2HeaderOnly;
    if ( !SwfJpeg2HeaderOnly )
      return 0;
    v5 = (jpeg_decompress_struct *)SwfJpeg2HeaderOnly->GetCInfo(SwfJpeg2HeaderOnly);
    Scaleform::Render::JPEG::GJPEGUtil_ReplaceRwSource(v5, (Scaleform::GFx::Resource *)this->pFile.pObject);
    this->pOriginalInput->StartImage(this->pOriginalInput);
  }
  else
  {
    v10 = (Scaleform::GFx::Resource *)this->pFile.pObject;
    if ( this->WithHeaders )
    {
      v6 = Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
             &Scaleform::Render::JPEG::FileReader::Instance,
             v10);
      this->pOriginalInput = v6;
      v6->StartImage(v6);
    }
    else
    {
      this->pOriginalInput = Scaleform::Render::JPEG::FileReader::CreateInput(
                               &Scaleform::Render::JPEG::FileReader::Instance,
                               v10);
    }
  }
  pOriginalInput = this->pOriginalInput;
  if ( !pOriginalInput )
    return 0;
  v8 = (unsigned int *)pOriginalInput->GetSize(pOriginalInput, &v11);
  v9 = v8[1];
  this->Size.Width = *v8;
  this->Size.Height = v9;
  if ( this->Format == Image_None )
    this->Format = Image_R8G8B8;
  return 1;
}
