void __thiscall Scaleform::GFx::AMP::ServerState::Write(
        Scaleform::GFx::AMP::ServerState *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v6; // ebp
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::File_vtbl *v8; // eax
  unsigned int i; // ebx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::File_vtbl *v11; // eax
  Scaleform::File_vtbl *v12; // eax
  Scaleform::File_vtbl *v13; // eax
  int CurrentFileId_high; // ecx
  int (__thiscall *v15)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v16)(Scaleform::File *, const unsigned __int8 *, int); // edx
  _DWORD v17[2]; // [esp+38h] [ebp-8h] BYREF

  v3 = str;
  Write = str->Write;
  v17[0] = this->StateFlags;
  Write(str, (const unsigned __int8 *)v17, 4);
  v6 = version;
  if ( version >= 0x14 )
  {
    v7 = v3->Write;
    str = (Scaleform::File *)this->ProfileLevel;
    v7(v3, (const unsigned __int8 *)&str, 4);
  }
  Scaleform::GFx::AMP::writeString(v3, &this->ConnectedApp);
  if ( v6 >= 5 )
    Scaleform::GFx::AMP::writeString(v3, &this->ConnectedFile);
  Scaleform::GFx::AMP::writeString(v3, &this->AaMode);
  Scaleform::GFx::AMP::writeString(v3, &this->StrokeType);
  Scaleform::GFx::AMP::writeString(v3, &this->CurrentLocale);
  v8 = v3->__vftable;
  str = (Scaleform::File *)this->Locales.Data.Size;
  v8->Write(v3, (const unsigned __int8 *)&str, 4);
  for ( i = 0; i < this->Locales.Data.Size; ++i )
    Scaleform::GFx::AMP::writeString(v3, &this->Locales.Data.Data[i]);
  v10 = v3->Write;
  str = (Scaleform::File *)LODWORD(this->CurveTolerance);
  v10(v3, (const unsigned __int8 *)&str, 4);
  v11 = v3->__vftable;
  str = (Scaleform::File *)LODWORD(this->CurveToleranceMin);
  v11->Write(v3, (const unsigned __int8 *)&str, 4);
  v12 = v3->__vftable;
  str = (Scaleform::File *)LODWORD(this->CurveToleranceMax);
  v12->Write(v3, (const unsigned __int8 *)&str, 4);
  v13 = v3->__vftable;
  str = (Scaleform::File *)LODWORD(this->CurveToleranceStep);
  v13->Write(v3, (const unsigned __int8 *)&str, 4);
  if ( v6 >= 0xA )
  {
    CurrentFileId_high = HIDWORD(this->CurrentFileId);
    v15 = v3->Write;
    v17[0] = this->CurrentFileId;
    v17[1] = CurrentFileId_high;
    v15(v3, (const unsigned __int8 *)v17, 8);
    v16 = v3->Write;
    str = (Scaleform::File *)this->CurrentLineNumber;
    v16(v3, (const unsigned __int8 *)&str, 4);
  }
}
