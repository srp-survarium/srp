Scaleform::GFx::AMP::ServerState *__thiscall Scaleform::GFx::AMP::ServerState::operator=(
        Scaleform::GFx::AMP::ServerState *this,
        const Scaleform::GFx::AMP::ServerState *rhs)
{
  unsigned int Size; // ebx
  Scaleform::ArrayLH<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *p_Locales; // ebp
  unsigned int v6; // ebx
  Scaleform::String *v7; // ecx
  unsigned int j; // ebx
  unsigned int v10; // [esp+14h] [ebp+4h]
  Scaleform::String *i; // [esp+14h] [ebp+4h]

  this->StateFlags = rhs->StateFlags;
  this->ProfileLevel = rhs->ProfileLevel;
  Scaleform::String::operator=(&this->ConnectedApp, &rhs->ConnectedApp);
  Scaleform::String::operator=(&this->ConnectedFile, &rhs->ConnectedFile);
  Scaleform::String::operator=(&this->AaMode, &rhs->AaMode);
  Scaleform::String::operator=(&this->StrokeType, &rhs->StrokeType);
  Scaleform::String::operator=(&this->CurrentLocale, &rhs->CurrentLocale);
  Size = rhs->Locales.Data.Size;
  p_Locales = &this->Locales;
  v10 = this->Locales.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorLH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Locales.Data,
    &this->Locales,
    Size);
  if ( Size > v10 )
  {
    v6 = Size - v10;
    v7 = &p_Locales->Data.Data[v10];
    for ( i = v7; v6; i = v7 )
    {
      if ( v7 )
      {
        Scaleform::String::String(v7);
        v7 = i;
      }
      ++v7;
      --v6;
    }
  }
  for ( j = 0; j < this->Locales.Data.Size; ++j )
    Scaleform::String::operator=(&p_Locales->Data.Data[j], &rhs->Locales.Data.Data[j]);
  this->CurveTolerance = rhs->CurveTolerance;
  this->CurveToleranceMin = rhs->CurveToleranceMin;
  this->CurveToleranceMax = rhs->CurveToleranceMax;
  this->CurveToleranceStep = rhs->CurveToleranceStep;
  LODWORD(this->CurrentFileId) = rhs->CurrentFileId;
  HIDWORD(this->CurrentFileId) = HIDWORD(rhs->CurrentFileId);
  this->CurrentLineNumber = rhs->CurrentLineNumber;
  return this;
}


bool __thiscall Scaleform::GFx::AMP::ServerState::operator!=(
        Scaleform::GFx::AMP::ServerState *this,
        const Scaleform::GFx::AMP::ServerState *rhs)
{
  unsigned int Size; // eax
  unsigned int v6; // ebp
  Scaleform::String *Data; // edi
  char *v8; // eax
  double v9; // st6
  double v10; // st5
  double v11; // st5
  double v12; // st6
  char *v13; // [esp+Ch] [ebp+4h]
  float v14; // [esp+Ch] [ebp+4h]
  float v15; // [esp+Ch] [ebp+4h]
  float v16; // [esp+Ch] [ebp+4h]
  float v17; // [esp+Ch] [ebp+4h]
  float v18; // [esp+Ch] [ebp+4h]
  float v19; // [esp+Ch] [ebp+4h]
  float v20; // [esp+Ch] [ebp+4h]
  float v21; // [esp+Ch] [ebp+4h]

  if ( this->StateFlags != rhs->StateFlags )
    return 1;
  if ( this->ProfileLevel != rhs->ProfileLevel )
    return 1;
  if ( Scaleform::String::operator!=(&this->ConnectedApp, &rhs->ConnectedApp) )
    return 1;
  if ( Scaleform::String::operator!=(&this->ConnectedFile, &rhs->ConnectedFile) )
    return 1;
  if ( Scaleform::String::operator!=(&this->AaMode, &rhs->AaMode) )
    return 1;
  if ( Scaleform::String::operator!=(&this->StrokeType, &rhs->StrokeType) )
    return 1;
  if ( Scaleform::String::operator!=(&this->CurrentLocale, &rhs->CurrentLocale) )
    return 1;
  Size = this->Locales.Data.Size;
  if ( Size != rhs->Locales.Data.Size )
    return 1;
  v6 = 0;
  if ( Size )
  {
    Data = this->Locales.Data.Data;
    v8 = (char *)((char *)rhs->Locales.Data.Data - (char *)Data);
    v13 = v8;
    while ( !Scaleform::String::operator!=(Data, (const Scaleform::String *)&v8[(_DWORD)Data]) )
    {
      ++v6;
      ++Data;
      if ( v6 >= this->Locales.Data.Size )
        goto LABEL_15;
      v8 = v13;
    }
    return 1;
  }
LABEL_15:
  v14 = this->CurveTolerance - rhs->CurveTolerance;
  v9 = v14;
  if ( v14 < 0.0 )
    v9 = -v9;
  v15 = v9;
  if ( v15 > 0.0001 )
    return 1;
  v16 = this->CurveToleranceMin - rhs->CurveToleranceMin;
  v10 = v16;
  if ( v16 < 0.0 )
    v10 = -v10;
  v17 = v10;
  if ( v17 > 0.0001 )
    return 1;
  v18 = this->CurveToleranceMax - rhs->CurveToleranceMax;
  v11 = v18;
  if ( v18 < 0.0 )
    v11 = -v11;
  v19 = v11;
  if ( v19 > 0.0001 )
    return 1;
  v20 = this->CurveToleranceStep - rhs->CurveToleranceStep;
  v12 = v20;
  if ( v20 < 0.0 )
    v12 = -v12;
  v21 = v12;
  if ( v21 > 0.0001
    || LODWORD(this->CurrentFileId) != LODWORD(rhs->CurrentFileId)
    || HIDWORD(this->CurrentFileId) != HIDWORD(rhs->CurrentFileId) )
  {
    return 1;
  }
  return this->CurrentLineNumber != rhs->CurrentLineNumber;
}
