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
