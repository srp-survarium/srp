char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::StringDataPtr *obj,
        const Scaleform::StringDataPtr *zero_val)
{
  int v4; // eax
  unsigned int Size; // ecx
  Scaleform::StringDataPtr result; // [esp+0h] [ebp-8h] BYREF

  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&cp->ConstStr.Data.Data[v4], &result);
    Size = result.Size;
    obj->pStr = result.pStr;
    obj->Size = Size;
  }
  else
  {
    *obj = *zero_val;
  }
  return 1;
}
