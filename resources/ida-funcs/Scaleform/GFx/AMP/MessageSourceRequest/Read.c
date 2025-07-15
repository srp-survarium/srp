void __thiscall Scaleform::GFx::AMP::MessageSourceRequest::Read(
        Scaleform::GFx::AMP::MessageSourceRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v5; // ecx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  v7 = 0;
  v8 = 0;
  Read(v2, (unsigned __int8 *)&v7, 8);
  v5 = v8;
  LODWORD(this->FileHandle) = v7;
  HIDWORD(this->FileHandle) = v5;
  v6 = v2->Read;
  LOBYTE(str) = 0;
  v6(v2, (unsigned __int8 *)&str, 1);
  this->RequestContents = (_BYTE)str != 0;
}
