void __thiscall Scaleform::GFx::AMP::MessageSourceRequest::Write(
        Scaleform::GFx::AMP::MessageSourceRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int FileHandle_high; // ecx
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  _DWORD v7[2]; // [esp+8h] [ebp-8h] BYREF

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  FileHandle_high = HIDWORD(this->FileHandle);
  Write = v2->Write;
  v7[0] = this->FileHandle;
  v7[1] = FileHandle_high;
  Write(v2, (const unsigned __int8 *)v7, 8);
  v6 = v2->Write;
  LOBYTE(str) = this->RequestContents;
  v6(v2, (const unsigned __int8 *)&str, 1);
}
