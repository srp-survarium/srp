void __thiscall Scaleform::GFx::AMP::Server::SetCurveTolerance(Scaleform::GFx::AMP::Server *this, float tolerance)
{
  unsigned int *p_CurrentLineNumber; // edi
  double v4; // st7
  double v5; // st6
  Scaleform::GFx::AMP::Server_vtbl *v6; // eax
  float v7; // [esp+Ch] [ebp+4h]
  float v8; // [esp+Ch] [ebp+4h]

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  v4 = tolerance;
  v7 = tolerance - *(float *)&this->CurrentState.Locales.Data.Size;
  v5 = v7;
  if ( v7 < 0.0 )
    v5 = -v5;
  v8 = v5;
  if ( v8 > 0.001 )
  {
    v6 = this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
    *(float *)&this->CurrentState.Locales.Data.Size = v4;
    v6[34].~Scaleform::GFx::AMP::Server(this);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
}
