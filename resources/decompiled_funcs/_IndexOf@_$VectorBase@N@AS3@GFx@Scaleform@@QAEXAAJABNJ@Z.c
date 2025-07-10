void __thiscall Scaleform::GFx::AS3::VectorBase<double>::IndexOf(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        int *result,
        const long double *searchElement,
        int fromIndex)
{
  unsigned int v4; // edx
  unsigned int Size; // esi
  double *v6; // ecx

  v4 = fromIndex;
  if ( fromIndex < 0 )
    v4 = this->ValueA.Data.Size + fromIndex;
  Size = this->ValueA.Data.Size;
  if ( v4 >= Size )
  {
LABEL_7:
    *result = -1;
  }
  else
  {
    v6 = &this->ValueA.Data.Data[v4];
    while ( *(double *)searchElement != *v6 )
    {
      ++v4;
      ++v6;
      if ( v4 >= Size )
        goto LABEL_7;
    }
    *result = v4;
  }
}
