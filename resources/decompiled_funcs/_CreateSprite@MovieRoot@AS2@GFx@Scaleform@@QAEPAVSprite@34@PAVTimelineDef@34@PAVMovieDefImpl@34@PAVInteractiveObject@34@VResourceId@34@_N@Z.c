Scaleform::GFx::Sprite *__userpurge Scaleform::GFx::AS2::MovieRoot::CreateSprite@<eax>(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Scaleform::GFx::TimelineDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::GFx::ResourceId id,
        bool loadedSeparately)
{
  Scaleform::GFx::ASSupport *pObject; // ecx
  Scaleform::GFx::Sprite *v10; // esi
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+4h] [ebp-Ch] BYREF

  ccinfo.pCharDef = pdef;
  pObject = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  ccinfo.pBindDefImpl = pdefImpl;
  ccinfo.pResource = 0;
  v10 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, unsigned int, int))pObject->CreateCharacterInstance)(
                                    pObject,
                                    this->pMovieImpl,
                                    &ccinfo,
                                    parent,
                                    id.Id,
                                    3);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v10, a2, a3, loadedSeparately);
  return v10;
}
