void __thiscall Scaleform::MemItemExtra::Read(
        Scaleform::MemItemExtra *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  bool v6; // cc
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v12; // [esp+28h] [ebp-4h] BYREF

  v3 = str;
  Read = str->Read;
  v12 = 0;
  Read(str, (unsigned __int8 *)&v12, 4);
  v6 = version <= 0xB;
  this->ImageId = v12;
  if ( !v6 )
  {
    v7 = v3->Read;
    str = 0;
    v7(v3, (unsigned __int8 *)&str, 4);
    this->AtlasId = (unsigned int)str;
    v8 = v3->Read;
    str = 0;
    v8(v3, (unsigned __int8 *)&str, 4);
    this->AtlasRectLeft = (int)str;
    v9 = v3->Read;
    str = 0;
    v9(v3, (unsigned __int8 *)&str, 4);
    this->AtlasRectTop = (int)str;
    v10 = v3->Read;
    str = 0;
    v10(v3, (unsigned __int8 *)&str, 4);
    this->AtlasRectRight = (int)str;
    v11 = v3->Read;
    str = 0;
    v11(v3, (unsigned __int8 *)&str, 4);
    this->AtlasRectBottom = (int)str;
  }
}
