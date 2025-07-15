Scaleform::GFx::StateBag_vtbl *__thiscall Scaleform::GFx::FontManagerStates::GetStateAddRef(
        Scaleform::GFx::FontManagerStates *this,
        Scaleform::GFx::State::StateType state)
{
  Scaleform::GFx::Resource *RefCount; // ecx
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v7; // ecx

  switch ( state )
  {
    case State_FontLib:
      RefCount = (Scaleform::GFx::Resource *)this->RefCount;
      if ( RefCount )
        Scaleform::RefCountImpl::AddRef(RefCount);
      return (Scaleform::GFx::StateBag_vtbl *)this->RefCount;
    case State_FontMap:
      v5 = (Scaleform::GFx::Resource *)this->Scaleform::GFx::StateBag::__vftable;
      if ( v5 )
        Scaleform::RefCountImpl::AddRef(v5);
      return this->Scaleform::GFx::StateBag::__vftable;
    case State_FontProvider:
      pObject = (Scaleform::GFx::Resource *)this->pFontLib.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::AddRef(pObject);
      return (Scaleform::GFx::StateBag_vtbl *)this->pFontLib.pObject;
    case State_Translator:
      v7 = (Scaleform::GFx::Resource *)this->pFontMap.pObject;
      if ( v7 )
        Scaleform::RefCountImpl::AddRef(v7);
      return (Scaleform::GFx::StateBag_vtbl *)this->pFontMap.pObject;
    default:
      return (Scaleform::GFx::StateBag_vtbl *)((int (__thiscall *)(Scaleform::GFx::FontProvider *, Scaleform::GFx::State::StateType))this->pFontProvider.pObject->__vftable[1].~Scaleform::GFx::FontProvider)(
                                                this->pFontProvider.pObject,
                                                state);
  }
}
