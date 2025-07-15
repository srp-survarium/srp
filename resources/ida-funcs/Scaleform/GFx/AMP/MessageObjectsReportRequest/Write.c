void __thiscall Scaleform::GFx::AMP::MessageObjectsReportRequest::Write(
        Scaleform::GFx::AMP::MessageObjectsReportRequest *this,
        Scaleform::File *str)
{
  Scaleform::File *v2; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v5)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Write = v2->Write;
  str = (Scaleform::File *)this->MovieHandle;
  Write(v2, (const unsigned __int8 *)&str, 4);
  v5 = v2->Write;
  LOBYTE(str) = this->ShortFilenames;
  v5(v2, (const unsigned __int8 *)&str, 1);
  v6 = v2->Write;
  LOBYTE(str) = this->NoCircularReferences;
  v6(v2, (const unsigned __int8 *)&str, 1);
  v7 = v2->Write;
  LOBYTE(str) = this->SuppressOverallStats;
  v7(v2, (const unsigned __int8 *)&str, 1);
  v8 = v2->Write;
  LOBYTE(str) = this->AddressesForAnonymObjsOnly;
  v8(v2, (const unsigned __int8 *)&str, 1);
  v9 = v2->Write;
  LOBYTE(str) = this->SuppressMovieDefsStats;
  v9(v2, (const unsigned __int8 *)&str, 1);
  v10 = v2->Write;
  LOBYTE(str) = this->NoEllipsis;
  v10(v2, (const unsigned __int8 *)&str, 1);
}
