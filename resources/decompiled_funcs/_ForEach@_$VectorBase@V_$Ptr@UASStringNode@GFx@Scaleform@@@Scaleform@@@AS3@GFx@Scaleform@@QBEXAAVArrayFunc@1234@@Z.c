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
