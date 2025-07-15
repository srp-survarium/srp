void __thiscall Scaleform::GFx::AMP::MessageSwdRequest::Write(
        Scaleform::GFx::AMP::MessageSwdRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->Handle;
  Write(v2, (const unsigned __int8 *)&str, 4);
  v5 = v2->Write;
  LOBYTE(str) = this->RequestContents;
  v5(v2, (const unsigned __int8 *)&str, 1);
}
