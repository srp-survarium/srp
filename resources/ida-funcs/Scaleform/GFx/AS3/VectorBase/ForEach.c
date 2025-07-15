void __thiscall Scaleform::GFx::AS3::VectorBase<double>::ForEach(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc *f)
{
  unsigned int Size; // ebp
  unsigned int i; // esi

  Size = this->ValueA.Data.Size;
  for ( i = 0; i < Size; ++i )
    f->operator()(f, i, &this->ValueA.Data.Data[i]);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEach(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ArrayFunc *f)
{
  unsigned int v3; // esi
  int v4; // edi
  unsigned int size; // [esp+8h] [ebp-4h]

  v3 = 0;
  size = this->ValueA.Data.Size;
  if ( size )
  {
    v4 = 0;
    do
      f->operator()(f, v3++, &this->ValueA.Data.Data[v4++]);
    while ( v3 < size );
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::ForEach(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc *f)
{
  unsigned int Size; // ebp
  unsigned int i; // esi

  Size = this->ValueA.Data.Size;
  for ( i = 0; i < Size; ++i )
    f->operator()(f, i, &this->ValueA.Data.Data[i]);
}
