void __thiscall Scaleform::GFx::DrawTextManager::CheckFontStatesChange(Scaleform::GFx::DrawTextManager *this)
{
  Scaleform::GFx::StateBag *v2; // esi
  Scaleform::GFx::FontProvider *v3; // ebp
  Scaleform::GFx::FontMap *v4; // ebx
  Scaleform::GFx::FontLib *v5; // esi
  Scaleform::GFx::Translator *ptranslator; // [esp+10h] [ebp-4h]

  v2 = &this->Scaleform::GFx::StateBag;
  ptranslator = (Scaleform::GFx::Translator *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 1);
  v3 = (Scaleform::GFx::FontProvider *)v2->GetStateAddRef(v2, State_FontProvider);
  v4 = (Scaleform::GFx::FontMap *)v2->GetStateAddRef(v2, State_FontMap);
  v5 = (Scaleform::GFx::FontLib *)v2->GetStateAddRef(v2, State_FontLib);
  Scaleform::GFx::FontManagerStates::CheckStateChange(this->pImpl->pFontStates.pObject, v5, v4, v3, ptranslator);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
  if ( ptranslator )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ptranslator);
}
