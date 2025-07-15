void __thiscall Scaleform::GFx::AMP::MessageAppControl::Write(
        Scaleform::GFx::AMP::MessageAppControl *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(&this->Scaleform::GFx::AMP::Message, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->OptionBits;
  Write(v2, (const unsigned __int8 *)&str, 4);
  Scaleform::GFx::AMP::writeString(v2, &this->LoadMovieFile);
  if ( this->Version >= 0x14 )
  {
    v5 = v2->Write;
    str = (Scaleform::File *)this->ProfileLevel;
    v5(v2, (const unsigned __int8 *)&str, 4);
  }
}
