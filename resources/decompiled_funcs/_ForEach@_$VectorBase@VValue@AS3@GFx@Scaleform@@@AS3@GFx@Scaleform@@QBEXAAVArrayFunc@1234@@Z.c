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
