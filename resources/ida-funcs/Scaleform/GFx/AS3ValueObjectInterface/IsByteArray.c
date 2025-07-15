char __thiscall Scaleform::GFx::AS3ValueObjectInterface::IsByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::ASMovieRootBase_vtbl *v2; // esi
  Scaleform::GFx::ASString *v3; // esi
  _DWORD *v4; // edi
  Scaleform::StringDataPtr qname; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+Ch] [ebp-18h] BYREF

  v2 = this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  qname.pStr = "flash.utils.ByteArray";
  qname.Size = 21;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    (const Scaleform::GFx::AS3::VM *)v2,
    (Scaleform::GFx::ASStringNode *)&qname);
  v3 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         (Scaleform::GFx::AS3::VM *)v2,
         &mn,
         (Scaleform::GFx::ASStringNode *)v2[1].ChangeMouseCursorType);
  if ( !v3 )
    goto LABEL_6;
  v4 = (_DWORD *)pdata[5];
  if ( !v4[17] )
    (*(void (__thiscall **)(_DWORD))(*v4 + 44))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v3,
         *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v4[17] + 20)) )
  {
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 1;
  }
  else
  {
LABEL_6:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 0;
  }
}
