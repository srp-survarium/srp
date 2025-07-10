void __thiscall Scaleform::GFx::MovieImpl::SetIMECandidateListStyle(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::IMECandidateListStyle *st)
{
  Scaleform::GFx::IMECandidateListStyle *pIMECandidateListStyle; // edi
  Scaleform::GFx::IMECandidateListStyle *v4; // eax

  pIMECandidateListStyle = this->pIMECandidateListStyle;
  if ( pIMECandidateListStyle )
  {
    qmemcpy((void *)pIMECandidateListStyle, st, sizeof(Scaleform::GFx::IMECandidateListStyle));
  }
  else
  {
    v4 = (Scaleform::GFx::IMECandidateListStyle *)this->pHeap->Alloc(this->pHeap, 44, 0);
    if ( v4 )
    {
      qmemcpy((void *)v4, st, sizeof(Scaleform::GFx::IMECandidateListStyle));
      this->pIMECandidateListStyle = v4;
    }
    else
    {
      this->pIMECandidateListStyle = 0;
    }
  }
}
