void __thiscall Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::GFx::CharPosInfo *pos,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObjectBase **newChar)
{
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+Ch] [ebp-Ch] BYREF

  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
    this->pDefImpl.pObject,
    (Scaleform::GFx::ResourceBinding *)&ccinfo,
    pos->CharacterId);
  if ( ccinfo.pCharDef )
  {
    v5 = (Scaleform::GFx::InteractiveObject *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::DisplayObjContainer *, unsigned int, _DWORD))this->pASRoot->pASSupport.pObject->CreateCharacterInstance)(
                                                this->pASRoot->pASSupport.pObject,
                                                this->pASRoot->pMovieImpl,
                                                &ccinfo,
                                                this,
                                                pos->CharacterId.Id,
                                                0);
    Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(this, pos, v5, name);
    if ( newChar )
      *newChar = v5->RefCount <= 1 ? 0 : v5;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "DisplayObjContainer::ReplaceDisplayObject() - unknown cid = %d",
      LOWORD(pos->CharacterId.Id));
  }
}
