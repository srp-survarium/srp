void __thiscall Scaleform::GFx::AMP::MessageObjectsReportRequest::Read(
        Scaleform::GFx::AMP::MessageObjectsReportRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Read = v2->Read;
  str = 0;
  Read(v2, (unsigned __int8 *)&str, 4);
  this->MovieHandle = (unsigned int)str;
  v5 = v2->Read;
  LOBYTE(str) = 0;
  v5(v2, (unsigned __int8 *)&str, 1);
  this->ShortFilenames = (_BYTE)str != 0;
  v6 = v2->Read;
  LOBYTE(str) = 0;
  v6(v2, (unsigned __int8 *)&str, 1);
  this->NoCircularReferences = (_BYTE)str != 0;
  v7 = v2->Read;
  LOBYTE(str) = 0;
  v7(v2, (unsigned __int8 *)&str, 1);
  this->SuppressOverallStats = (_BYTE)str != 0;
  v8 = v2->Read;
  LOBYTE(str) = 0;
  v8(v2, (unsigned __int8 *)&str, 1);
  this->AddressesForAnonymObjsOnly = (_BYTE)str != 0;
  v9 = v2->Read;
  LOBYTE(str) = 0;
  v9(v2, (unsigned __int8 *)&str, 1);
  this->SuppressMovieDefsStats = (_BYTE)str != 0;
  v10 = v2->Read;
  LOBYTE(str) = 0;
  v10(v2, (unsigned __int8 *)&str, 1);
  this->NoEllipsis = (_BYTE)str != 0;
}
