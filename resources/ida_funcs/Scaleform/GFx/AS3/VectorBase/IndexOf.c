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
