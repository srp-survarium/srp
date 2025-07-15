void __thiscall Scaleform::MemItemExtra::Write(
        Scaleform::MemItemExtra *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int ImageId; // [esp+20h] [ebp-4h] BYREF

  v3 = str;
  Write = str->Write;
  ImageId = this->ImageId;
  Write(str, (const unsigned __int8 *)&ImageId, 4);
  if ( version > 0xB )
  {
    v6 = v3->Write;
    str = (Scaleform::File *)this->AtlasId;
    v6(v3, (const unsigned __int8 *)&str, 4);
    v7 = v3->Write;
    str = (Scaleform::File *)this->AtlasRectLeft;
    v7(v3, (const unsigned __int8 *)&str, 4);
    v8 = v3->Write;
    str = (Scaleform::File *)this->AtlasRectTop;
    v8(v3, (const unsigned __int8 *)&str, 4);
    v9 = v3->Write;
    str = (Scaleform::File *)this->AtlasRectRight;
    v9(v3, (const unsigned __int8 *)&str, 4);
    v10 = v3->Write;
    str = (Scaleform::File *)this->AtlasRectBottom;
    v10(v3, (const unsigned __int8 *)&str, 4);
  }
}
