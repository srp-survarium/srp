void __thiscall Scaleform::GFx::AMP::MessageLog::Read(Scaleform::GFx::AMP::MessageLog *this, Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v5; // edi
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Scaleform::GFx::AMP::Message::ReadString(v2, &this->LogText);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->LogCategory = (unsigned int)str;
  Scaleform::GFx::AMP::Message::ReadString(v2, &this->TimeStamp);
  if ( this->Version <= 2 )
  {
    v5 = 128;
    do
    {
      v6 = v2->Read;
      str = 0;
      v6(v2, (unsigned __int8 *)&str, 4);
      --v5;
    }
    while ( v5 );
  }
}
