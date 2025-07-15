void __thiscall Scaleform::GFx::AS3::IMEManager::OnOpenCandidateList(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::GFx::TextField *pTextField; // esi
  Scaleform::GFx::Sprite *CandidateListSprite; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> pfocusedCh; // [esp+4h] [ebp-4h] BYREF

  pMovie = (Scaleform::GFx::MovieImpl *)this->pMovie;
  if ( pMovie )
  {
    pTextField = this->pTextField;
    if ( !pTextField )
    {
      Scaleform::GFx::MovieImpl::GetFocusedCharacter(pMovie, &pfocusedCh, 0);
      pTextField = (Scaleform::GFx::TextField *)pfocusedCh.pObject;
      if ( !pfocusedCh.pObject )
        return;
      if ( pfocusedCh.pObject->GetType(pfocusedCh.pObject) != MouseWheel )
      {
        Scaleform::RefCountNTSImpl::Release(pTextField);
        return;
      }
      Scaleform::RefCountNTSImpl::Release(pTextField);
    }
    CandidateListSprite = Scaleform::GFx::AS3::IMEManager::GetCandidateListSprite(this);
    if ( CandidateListSprite )
      Scaleform::GFx::TextField::SetCandidateListFont(pTextField, CandidateListSprite);
  }
}
