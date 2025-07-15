Scaleform::StringDataPtr *__thiscall Scaleform::GFx::AS3::Abc::ConstPool::GetString(
        Scaleform::GFx::AS3::Abc::ConstPool *this,
        Scaleform::StringDataPtr *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::StringDataPtr *v3; // eax
  unsigned int Size; // edx
  Scaleform::StringDataPtr v5; // [esp+0h] [ebp-8h] BYREF

  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&this->ConstStr.Data.Data[ind.Index], &v5);
  v3 = result;
  Size = v5.Size;
  result->pStr = v5.pStr;
  result->Size = Size;
  return v3;
}
