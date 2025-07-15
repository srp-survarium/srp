void __thiscall Scaleform::GFx::AS2::IMEManager::OnOpenCandidateList(Scaleform::GFx::AS2::IMEManager *this)
{
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::GFx::TextField *pTextField; // esi
  Scaleform::GFx::FontResource *FontResource; // esi
  Scaleform::GFx::Movie *v5; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // ecx
  Scaleform::RefCountNTSImpl *v7; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::Value pval; // [esp+8h] [ebp-18h] BYREF

  pMovie = (Scaleform::GFx::MovieImpl *)this->pMovie;
  if ( pMovie )
  {
    pTextField = this->pTextField;
    if ( !pTextField )
    {
      Scaleform::GFx::MovieImpl::GetFocusedCharacter(
        pMovie,
        (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&v7,
        0);
      pTextField = (Scaleform::GFx::TextField *)v7;
      if ( !v7 )
        return;
      if ( ((int (__thiscall *)(Scaleform::RefCountNTSImpl *))v7->__vftable[79].~Scaleform::RefCountNTSImpl)(v7) != 4 )
      {
        Scaleform::RefCountNTSImpl::Release(pTextField);
        return;
      }
      Scaleform::RefCountNTSImpl::Release(pTextField);
    }
    FontResource = Scaleform::GFx::TextField::GetFontResource(pTextField);
    if ( FontResource )
    {
      v5 = this->pMovie;
      pval.pObjectInterface = 0;
      pval.Type = VT_Undefined;
      if ( !Scaleform::GFx::Movie::GetVariable(v5, &pval, "_global.gfx_ime_candidate_list_state") )
      {
        if ( (pval.Type & 0x40) != 0 )
        {
          pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
          pval.pObjectInterface = 0;
        }
        pval.Type = VT_Number;
        pval.mValue.NValue = 0.0;
      }
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
                     (Scaleform::GFx::AS2::MovieRoot *)this->pMovie->pASMovieRoot.pObject,
                     9999);
      if ( LevelMovie && 2.0 == pval.mValue.NValue )
      {
        Scaleform::GFx::Sprite::SetIMECandidateListFont(LevelMovie, FontResource);
        Scaleform::GFx::Value::~Value(&pval);
      }
      else if ( (pval.Type & 0x40) != 0 )
      {
        pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
      }
    }
  }
}
