void __thiscall Scaleform::GFx::MovieImpl::GetIMECandidateListStyle(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::IMECandidateListStyle *pst)
{
  Scaleform::GFx::IMECandidateListStyle *pIMECandidateListStyle; // esi
  char v3; // [esp+8h] [ebp-2Ch] BYREF
  __int16 v4; // [esp+30h] [ebp-4h]

  pIMECandidateListStyle = this->pIMECandidateListStyle;
  if ( !pIMECandidateListStyle )
  {
    v4 = 0;
    pIMECandidateListStyle = (Scaleform::GFx::IMECandidateListStyle *)&v3;
  }
  qmemcpy((void *)pst, pIMECandidateListStyle, sizeof(Scaleform::GFx::IMECandidateListStyle));
}
