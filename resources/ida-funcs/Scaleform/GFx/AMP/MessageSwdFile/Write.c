void __thiscall Scaleform::GFx::AMP::MessageSwdFile::Write(
        Scaleform::GFx::AMP::MessageSwdFile *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // ebx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->Handle;
  Write(v2, (const unsigned __int8 *)&str, 4);
  v5 = v2->Write;
  str = (Scaleform::File *)this->FileData.Data.Size;
  v5(v2, (const unsigned __int8 *)&str, 4);
  for ( i = 0; i < this->FileData.Data.Size; ++i )
  {
    v7 = v2->Write;
    LOBYTE(str) = this->FileData.Data.Data[i];
    v7(v2, (const unsigned __int8 *)&str, 1);
  }
  Scaleform::GFx::AMP::writeString(v2, &this->Filename);
}
