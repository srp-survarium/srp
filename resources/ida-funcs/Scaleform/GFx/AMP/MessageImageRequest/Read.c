void __thiscall Scaleform::GFx::AMP::MessageImageRequest::Read(
        Scaleform::GFx::AMP::MessageFontRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->FontId = (unsigned int)str;
}
