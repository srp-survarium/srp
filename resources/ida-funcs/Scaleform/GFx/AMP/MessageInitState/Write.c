void __thiscall Scaleform::GFx::AMP::MessageInitState::Write(
        Scaleform::GFx::AMP::MessageInitState *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->InitStateFlags;
  Write(v2, (const unsigned __int8 *)&str, 4);
  v5 = v2->Write;
  str = (Scaleform::File *)this->InitProfileLevel;
  v5(v2, (const unsigned __int8 *)&str, 4);
}
