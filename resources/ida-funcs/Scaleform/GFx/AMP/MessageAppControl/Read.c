void __thiscall Scaleform::GFx::AMP::MessageAppControl::Read(
        Scaleform::GFx::AMP::MessageAppControl *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(&this->Scaleform::GFx::AMP::Message, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->OptionBits = (unsigned int)str;
  Scaleform::GFx::AMP::Message::ReadString(v2, &this->LoadMovieFile);
  if ( this->Version >= 0x14 )
  {
    v5 = v2->Read;
    str = 0;
    v5(v2, (unsigned __int8 *)&str, 4);
    this->ProfileLevel = (int)str;
  }
}
