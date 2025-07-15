void __thiscall Scaleform::GFx::AS2::IMEManager::OnOpenCandidateList(Scaleform::GFx::AS2::IMEManager *this)
{
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::GFx::TextField *pTextField; // esi
  Scaleform::GFx::FontResource *FontResource; // esi
  Scaleform::GFx::Movie *v5; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // ecx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> pfocusedCh; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::Value v; // [esp+8h] [ebp-18h] BYREF

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
    FontResource = Scaleform::GFx::TextField::GetFontResource(pTextField);
    if ( FontResource )
    {
      v5 = this->pMovie;
      v.pObjectInterface = 0;
      v.Type = VT_Undefined;
      if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(v5, &v, "_global.gfx_ime_candidate_list_state") )
      {
        if ( (v.Type & 0x40) != 0 )
        {
          v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
          v.pObjectInterface = 0;
        }
        v.Type = VT_Number;
        v.mValue.NValue = 0.0;
      }
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
                     (Scaleform::GFx::AS2::MovieRoot *)this->pMovie->pASMovieRoot.pObject,
                     9999);
      if ( LevelMovie && 2.0 == v.mValue.NValue )
      {
        Scaleform::GFx::Sprite::SetIMECandidateListFont(LevelMovie, FontResource);
        Scaleform::GFx::Value::~Value(&v);
      }
      else if ( (v.Type & 0x40) != 0 )
      {
        v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      }
    }
  }
}
