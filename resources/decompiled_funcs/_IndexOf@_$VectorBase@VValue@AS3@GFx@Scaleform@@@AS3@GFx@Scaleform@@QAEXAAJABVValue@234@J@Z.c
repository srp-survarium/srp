void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::IndexOf(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        int *result,
        const Scaleform::GFx::AS3::Value *searchElement,
        unsigned int fromIndex)
{
  unsigned int v5; // ebx
  unsigned int v6; // edi

  v5 = fromIndex;
  if ( fromIndex >= this->ValueA.Data.Size )
  {
LABEL_5:
    *result = -1;
  }
  else
  {
    v6 = fromIndex;
    while ( !Scaleform::GFx::AS3::StrictEqual(&this->ValueA.Data.Data[v6], searchElement) )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->ValueA.Data.Size )
        goto LABEL_5;
    }
    *result = v5;
  }
}
