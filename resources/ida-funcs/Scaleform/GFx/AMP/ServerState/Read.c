void __thiscall Scaleform::GFx::AMP::ServerState::Read(
        Scaleform::GFx::AMP::ServerState *this,
        float str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  void (__thiscall *v4)(_DWORD, unsigned int *, int); // edx
  unsigned int v6; // ebx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // ebp
  Scaleform::ArrayLH<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *p_Locales; // ebx
  Scaleform::String *v11; // ecx
  unsigned int v12; // ebp
  unsigned int v13; // ebp
  int (__thiscall *v14)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v15)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v16)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v17)(Scaleform::File *, unsigned __int8 *, int); // edx
  bool v18; // cf
  int (__thiscall *v19)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v20; // ecx
  int (__thiscall *v21)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v22; // [esp+40h] [ebp-8h] BYREF
  int v23; // [esp+44h] [ebp-4h]

  v3 = (Scaleform::File *)LODWORD(str);
  v4 = *(void (__thiscall **)(_DWORD, unsigned int *, int))(*(_DWORD *)LODWORD(str) + 40);
  v22 = 0;
  v4(LODWORD(str), &v22, 4);
  v6 = version;
  this->StateFlags = v22;
  if ( v6 >= 0x14 )
  {
    Read = v3->Read;
    str = 0.0;
    Read(v3, (unsigned __int8 *)&str, 4);
    *(float *)&this->ProfileLevel = str;
  }
  Scaleform::GFx::AMP::readString(v3, &this->ConnectedApp);
  if ( v6 >= 5 )
    Scaleform::GFx::AMP::readString(v3, &this->ConnectedFile);
  Scaleform::GFx::AMP::readString(v3, &this->AaMode);
  Scaleform::GFx::AMP::readString(v3, &this->StrokeType);
  Scaleform::GFx::AMP::readString(v3, &this->CurrentLocale);
  v8 = v3->Read;
  str = 0.0;
  v8(v3, (unsigned __int8 *)&str, 4);
  Size = this->Locales.Data.Size;
  p_Locales = &this->Locales;
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorLH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Locales.Data,
    &this->Locales,
    LODWORD(str));
  if ( LODWORD(str) > Size )
  {
    v11 = &p_Locales->Data.Data[Size];
    v22 = (unsigned int)v11;
    if ( LODWORD(str) != Size )
    {
      v12 = LODWORD(str) - Size;
      do
      {
        if ( v11 )
        {
          Scaleform::String::String(v11);
          v11 = (Scaleform::String *)v22;
        }
        ++v11;
        --v12;
        v22 = (unsigned int)v11;
      }
      while ( v12 );
    }
  }
  v13 = 0;
  if ( str != 0.0 )
  {
    do
      Scaleform::GFx::AMP::readString(v3, &p_Locales->Data.Data[v13++]);
    while ( v13 < LODWORD(str) );
  }
  v14 = v3->Read;
  str = 0.0;
  v14(v3, (unsigned __int8 *)&str, 4);
  this->CurveTolerance = str;
  v15 = v3->Read;
  str = 0.0;
  v15(v3, (unsigned __int8 *)&str, 4);
  this->CurveToleranceMin = str;
  v16 = v3->Read;
  str = 0.0;
  v16(v3, (unsigned __int8 *)&str, 4);
  this->CurveToleranceMax = str;
  v17 = v3->Read;
  str = 0.0;
  v17(v3, (unsigned __int8 *)&str, 4);
  v18 = version < 0xA;
  this->CurveToleranceStep = str;
  if ( !v18 )
  {
    v19 = v3->Read;
    v22 = 0;
    v23 = 0;
    v19(v3, (unsigned __int8 *)&v22, 8);
    v20 = v23;
    LODWORD(this->CurrentFileId) = v22;
    HIDWORD(this->CurrentFileId) = v20;
    v21 = v3->Read;
    version = 0;
    v21(v3, (unsigned __int8 *)&version, 4);
    this->CurrentLineNumber = version;
  }
}
