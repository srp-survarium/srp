void __thiscall Scaleform::GFx::AMP::ServerState::ServerState(Scaleform::GFx::AMP::ServerState *this)
{
  this->__vftable = (Scaleform::GFx::AMP::ServerState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::ServerState_vtbl *)&Scaleform::GFx::AMP::ServerState::`vftable';
  this->StateFlags = 0;
  this->ProfileLevel = 0;
  Scaleform::StringLH::StringLH(&this->ConnectedApp);
  Scaleform::StringLH::StringLH(&this->ConnectedFile);
  Scaleform::StringLH::StringLH(&this->AaMode);
  Scaleform::StringLH::StringLH(&this->StrokeType);
  Scaleform::StringLH::StringLH(&this->CurrentLocale);
  this->Locales.Data.Data = 0;
  this->Locales.Data.Size = 0;
  this->Locales.Data.Policy.Capacity = 0;
  this->CurveTolerance = 0.0;
  this->CurveToleranceMin = 0.0;
  this->CurrentFileId = 0;
  this->CurveToleranceMax = 0.0;
  this->CurrentLineNumber = 0;
  this->CurveToleranceStep = 0.0;
}
