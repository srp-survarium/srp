void __thiscall Scaleform::GFx::AS3::VectorBase<double>::LastIndexOf(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        int *result,
        const long double *searchElement,
        int fromIndex)
{
  signed int v4; // edx
  double *v5; // ecx

  v4 = fromIndex;
  if ( fromIndex < 0 )
    v4 = this->ValueA.Data.Size + fromIndex;
  if ( v4 >= (signed int)(this->ValueA.Data.Size - 1) )
    v4 = this->ValueA.Data.Size - 1;
  if ( v4 < 0 )
  {
LABEL_9:
    *result = -1;
  }
  else
  {
    v5 = &this->ValueA.Data.Data[v4];
    while ( *(double *)searchElement != *v5 )
    {
      --v4;
      --v5;
      if ( v4 < 0 )
        goto LABEL_9;
    }
    *result = v4;
  }
}
