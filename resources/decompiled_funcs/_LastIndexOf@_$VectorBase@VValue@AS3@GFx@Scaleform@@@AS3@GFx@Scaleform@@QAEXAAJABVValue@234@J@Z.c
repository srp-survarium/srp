void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::LastIndexOf(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        int *result,
        const Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  signed int v5; // esi
  signed int v6; // edi

  v5 = fromIndex;
  if ( fromIndex >= (signed int)(this->ValueA.Data.Size - 1) )
    v5 = this->ValueA.Data.Size - 1;
  if ( v5 < 0 )
  {
LABEL_7:
    *result = -1;
  }
  else
  {
    v6 = v5;
    while ( !Scaleform::GFx::AS3::StrictEqual(&this->ValueA.Data.Data[v6], searchElement) )
    {
      --v5;
      --v6;
      if ( v5 < 0 )
        goto LABEL_7;
    }
    *result = v5;
  }
}
