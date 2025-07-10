void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::LastIndexOf(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        int *result,
        const unsigned int *searchElement,
        int fromIndex)
{
  int v4; // edx
  signed int v5; // eax
  unsigned int *v6; // ecx

  v4 = fromIndex;
  if ( fromIndex < 0 )
    v4 = this->ValueA.Data.Size + fromIndex;
  v5 = this->ValueA.Data.Size - 1;
  if ( v4 < v5 )
    v5 = v4;
  if ( v5 < 0 )
  {
LABEL_9:
    *result = -1;
  }
  else
  {
    v6 = &this->ValueA.Data.Data[v5];
    while ( *v6 != *searchElement )
    {
      --v5;
      --v6;
      if ( v5 < 0 )
        goto LABEL_9;
    }
    *result = v5;
  }
}
