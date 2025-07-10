Scaleform::Render::JPEG::Input *__thiscall Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
        Scaleform::Render::JPEG::FileReader *this,
        const unsigned __int8 *pbuffer,
        unsigned int bufSize)
{
  Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *v3; // eax
  _BYTE *v4; // eax
  void (__thiscall ***v5)(_DWORD, int); // esi

  v3 = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           800,
                                                           0);
  if ( v3 )
  {
    Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JPEGInputImpl_jpeglib(v3, SWF_JPEG2_HEADER_ONLY, pbuffer, bufSize);
    v5 = (void (__thiscall ***)(_DWORD, int))v4;
    if ( v4 )
    {
      if ( (v4[792] & 4) != 0 && !(*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 40))(v4) )
        return (Scaleform::Render::JPEG::Input *)v5;
      (**v5)(v5, 1);
    }
  }
  return 0;
}
