void __thiscall Scaleform::GFx::AMP::MessageSwdRequest::Read(
        Scaleform::GFx::AMP::MessageSwdRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->Handle = (unsigned int)str;
  v5 = v2->Read;
  LOBYTE(str) = 0;
  v5(v2, (unsigned __int8 *)&str, 1);
  this->RequestContents = (_BYTE)str != 0;
}
