Scaleform::StringDataPtr *__thiscall Scaleform::GFx::AS3::Abc::Multiname::GetName(
        Scaleform::GFx::AS3::Abc::Multiname *this,
        Scaleform::StringDataPtr *result,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp)
{
  Scaleform::StringDataPtr *v3; // eax
  unsigned int Size; // edx
  Scaleform::StringDataPtr v5; // [esp+0h] [ebp-8h] BYREF

  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&cp->ConstStr.Data.Data[this->NameIndex], &v5);
  v3 = result;
  Size = v5.Size;
  result->pStr = v5.pStr;
  result->Size = Size;
  return v3;
}
