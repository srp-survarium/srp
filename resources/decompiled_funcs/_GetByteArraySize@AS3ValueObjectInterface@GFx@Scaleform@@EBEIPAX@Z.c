int __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetByteArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::ASMovieRootBase_vtbl *v2; // esi
  Scaleform::GFx::ASString *v3; // edi
  _DWORD *v4; // esi
  int v5; // esi
  Scaleform::StringDataPtr qname; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+14h] [ebp-18h] BYREF

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
    v5 = pdata[10];
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return v5;
  }
  else
  {
LABEL_6:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 0;
  }
}
