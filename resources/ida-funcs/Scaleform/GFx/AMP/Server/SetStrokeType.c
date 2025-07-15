void __thiscall Scaleform::GFx::AMP::Server::SetStrokeType(
        Scaleform::GFx::AMP::Server *this,
        const __m128i *strokeType)
{
  unsigned int *p_CurrentLineNumber; // edi

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  if ( strcmp((const char *)((this->CurrentState.ConnectedFile.HeapTypeBits & 0xFFFFFFFC) + 8), strokeType->m128i_i8) )
  {
    Scaleform::String::operator=(&this->CurrentState.ConnectedFile, strokeType);
    this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[34].~Scaleform::GFx::AMP::Server(this);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
}
