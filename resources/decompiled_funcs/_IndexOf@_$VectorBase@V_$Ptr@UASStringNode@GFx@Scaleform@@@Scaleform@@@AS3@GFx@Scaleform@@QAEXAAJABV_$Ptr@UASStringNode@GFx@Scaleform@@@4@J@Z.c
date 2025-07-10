void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::IndexOf(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        int *result,
        const unsigned int *searchElement,
        int fromIndex)
{
  unsigned int v4; // eax
  unsigned int Size; // edx
  unsigned int *v6; // ecx

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
    while ( *v6 != *searchElement )
    {
      ++v4;
      ++v6;
      if ( v4 >= Size )
        goto LABEL_7;
    }
    *result = v4;
  }
}
