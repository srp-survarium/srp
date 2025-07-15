void __thiscall Scaleform::GFx::AMP::MessagePort::Write(Scaleform::GFx::AMP::MessagePort *this, Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->Port;
  Write(v2, (const unsigned __int8 *)&str, 4);
  Scaleform::GFx::AMP::writeString(v2, &this->AppName);
  if ( this->Version >= 5 )
  {
    v5 = v2->Write;
    str = (Scaleform::File *)this->Platform;
    v5(v2, (const unsigned __int8 *)&str, 4);
    Scaleform::GFx::AMP::writeString(v2, &this->FileName);
  }
}
