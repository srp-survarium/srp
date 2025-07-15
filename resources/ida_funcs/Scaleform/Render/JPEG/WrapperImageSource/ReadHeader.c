char __thiscall Scaleform::Render::JPEG::WrapperImageSource::ReadHeader(
        Scaleform::Render::JPEG::WrapperImageSource *this)
{
  Scaleform::Render::MemoryBufferImage *v2; // eax
  _DWORD *v3; // esi
  Scaleform::Render::JPEG::Input *SwfJpeg2HeaderOnly; // eax
  int v5; // ecx
  _DWORD v7[2]; // [esp+8h] [ebp-8h] BYREF

  v2 = this->pDelegate.pObject->GetAsMemoryImage(this->pDelegate.pObject);
  v3 = &v2->__vftable;
  if ( !v2 )
    return 0;
  SwfJpeg2HeaderOnly = Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
                         &Scaleform::Render::JPEG::FileReader::Instance,
                         v2->FileData.Data.Data,
                         v2->FileData.Data.Size);
  this->pOriginalInput = SwfJpeg2HeaderOnly;
  if ( !SwfJpeg2HeaderOnly )
    return 0;
  SwfJpeg2HeaderOnly->StartImage(SwfJpeg2HeaderOnly);
  this->pOriginalInput->GetSize(this->pOriginalInput, (Scaleform::Render::Size<unsigned long> *)v7);
  v5 = v7[1];
  v3[6] = v7[0];
  v3[7] = v5;
  if ( !(*(int (__thiscall **)(_DWORD *))(*v3 + 16))(v3) )
    v3[5] = 3;
  return 1;
}
