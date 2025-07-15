void __thiscall Scaleform::GFx::AMP::MessageSourceFile::Write(
        Scaleform::GFx::AMP::MessageSourceFile *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int FileHandle_high; // ecx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // ebx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  _DWORD v9[2]; // [esp+Ch] [ebp-8h] BYREF

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  FileHandle_high = HIDWORD(this->FileHandle);
  Write = v2->Write;
  v9[0] = this->FileHandle;
  v9[1] = FileHandle_high;
  Write(v2, (const unsigned __int8 *)v9, 8);
  v6 = v2->Write;
  str = (Scaleform::File *)this->FileData.Data.Size;
  v6(v2, (const unsigned __int8 *)&str, 4);
  for ( i = 0; i < this->FileData.Data.Size; ++i )
  {
    v8 = v2->Write;
    LOBYTE(str) = this->FileData.Data.Data[i];
    v8(v2, (const unsigned __int8 *)&str, 1);
  }
  Scaleform::GFx::AMP::writeString(v2, &this->Filename);
}
