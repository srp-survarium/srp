char __thiscall Scaleform::GFx::AS3ValueObjectInterface::ReadFromByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pdata,
        unsigned __int8 *destBuff,
        unsigned int destBuffSz)
{
  Scaleform::GFx::ASMovieRootBase_vtbl *v4; // esi
  Scaleform::GFx::ASString *v5; // edi
  _DWORD *v6; // esi
  Scaleform::StringDataPtr qname; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+14h] [ebp-18h] BYREF

  v4 = this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  qname.pStr = "flash.utils.ByteArray";
  qname.Size = 21;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    (const Scaleform::GFx::AS3::VM *)v4,
    (Scaleform::GFx::ASStringNode *)&qname);
  v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         (Scaleform::GFx::AS3::VM *)v4,
         &mn,
         (Scaleform::GFx::ASStringNode *)v4[1].ChangeMouseCursorType);
  if ( !v5 )
    goto LABEL_6;
  v6 = &pdata->pTraits.pObject->Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::__vftable;
  if ( !v6[17] )
    (*(void (__thiscall **)(Scaleform::GFx::AS3::Traits *))(*v6 + 44))(pdata->pTraits.pObject);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v5,
         *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v6[17] + 20)) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(pdata, destBuff, destBuffSz);
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
