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
