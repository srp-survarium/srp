void __thiscall Scaleform::GFx::AMP::MessageImageData::Read(
        Scaleform::GFx::AMP::MessageImageData *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::GFx::AMP::AmpStream *ImageDataStream; // ecx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  ImageDataStream = this->ImageDataStream;
  this->ImageId = (unsigned int)str;
  Scaleform::GFx::AMP::AmpStream::Read(ImageDataStream, v2);
  if ( this->Version >= 0x1A )
  {
    v6 = v2->Read;
    LOBYTE(str) = 0;
    v6(v2, (unsigned __int8 *)&str, 1);
    this->PngFormat = (_BYTE)str != 0;
  }
}
