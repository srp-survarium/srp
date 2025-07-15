void __thiscall Scaleform::GFx::AMP::MessageImageData::Write(
        Scaleform::GFx::AMP::MessageImageData *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->ImageId;
  Write(v2, (const unsigned __int8 *)&str, 4);
  if ( this->Version >= 0x1A || this->PngFormat )
  {
    Scaleform::GFx::AMP::AmpStream::Write(this->ImageDataStream, v2);
  }
  else
  {
    v5 = v2->Write;
    str = 0;
    v5(v2, (const unsigned __int8 *)&str, 4);
  }
  if ( this->Version >= 0x1A )
  {
    v6 = v2->Write;
    LOBYTE(str) = this->PngFormat;
    v6(v2, (const unsigned __int8 *)&str, 1);
  }
}
