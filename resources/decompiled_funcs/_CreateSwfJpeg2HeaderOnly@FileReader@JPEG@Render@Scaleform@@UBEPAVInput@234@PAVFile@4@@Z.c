Scaleform::Render::JPEG::Input *__thiscall Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::GFx::Resource *pin)
{
  Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *v2; // eax
  _BYTE *v3; // eax
  void (__thiscall ***v4)(_DWORD, int); // esi

  if ( pin )
  {
    if ( (unsigned __int8)pin->GetResourceTypeCode(pin) )
    {
      v2 = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               800,
                                                               0);
      if ( v2 )
      {
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JPEGInputImpl_jpeglib(v2, SWF_JPEG2_HEADER_ONLY, pin);
        v4 = (void (__thiscall ***)(_DWORD, int))v3;
        if ( v3 )
        {
          if ( (v3[792] & 4) != 0 && !(*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v3 + 40))(v3) )
            return (Scaleform::Render::JPEG::Input *)v4;
          (**v4)(v4, 1);
        }
      }
    }
  }
  return 0;
}
