void __thiscall Scaleform::GFx::AMP::MessageLog::Write(Scaleform::GFx::AMP::MessageLog *this, Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int v5; // edi
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Scaleform::GFx::AMP::writeString(v2, &this->LogText);
  Write = v2->Write;
  str = (Scaleform::File *)this->LogCategory;
  Write(v2, (const unsigned __int8 *)&str, 4);
  Scaleform::GFx::AMP::writeString(v2, &this->TimeStamp);
  if ( this->Version <= 2 )
  {
    v5 = 128;
    do
    {
      v6 = v2->Write;
      str = 0;
      v6(v2, (const unsigned __int8 *)&str, 4);
      --v5;
    }
    while ( v5 );
  }
}
