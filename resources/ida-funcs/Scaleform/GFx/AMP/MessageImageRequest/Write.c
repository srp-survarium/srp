void __thiscall Scaleform::GFx::AMP::MessageImageRequest::Write(
        Scaleform::GFx::AMP::MessageFontRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->FontId;
  Write(v2, (const unsigned __int8 *)&str, 4);
}
