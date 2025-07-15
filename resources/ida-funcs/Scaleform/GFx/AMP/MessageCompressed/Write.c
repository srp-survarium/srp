void __thiscall Scaleform::GFx::AMP::MessageCompressed::Write(
        Scaleform::GFx::AMP::MessageCompressed *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // ebx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // edi
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->CompressedData.Data.Size;
  Write(v2, (const unsigned __int8 *)&str, 4);
  for ( i = 0; i < this->CompressedData.Data.Size; ++i )
  {
    v6 = v2->Write;
    LOBYTE(str) = this->CompressedData.Data.Data[i];
    v6(v2, (const unsigned __int8 *)&str, 1);
  }
}
