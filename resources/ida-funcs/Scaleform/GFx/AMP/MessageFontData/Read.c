void __thiscall Scaleform::GFx::AMP::MessageFontData::Read(
        Scaleform::GFx::AMP::MessageFontData *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::GFx::AMP::AmpStream *FontDataStream; // ecx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  FontDataStream = this->FontDataStream;
  this->FontId = (unsigned int)str;
  Scaleform::GFx::AMP::AmpStream::Read(FontDataStream, v2);
}
