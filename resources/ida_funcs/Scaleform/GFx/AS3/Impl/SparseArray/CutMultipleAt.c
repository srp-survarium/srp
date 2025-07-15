void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int pos,
        unsigned int count,
        Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  unsigned int v4; // esi
  unsigned int Size; // eax
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // ebp
  unsigned int ValueHHighInd; // eax
  unsigned int count_a; // [esp+Ch] [ebp+4h]

  v4 = count;
  if ( count )
  {
    Size = this->ValueA.Data.Size;
    if ( pos < Size )
    {
      v8 = Size - pos;
      count_a = count;
      if ( count >= v8 )
        count_a = v8;
      if ( deleted && pos < pos + count_a )
      {
        v9 = pos;
        v10 = count_a;
        do
        {
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(deleted, &this->ValueA.Data.Data[v9++]);
          --v10;
        }
        while ( v10 );
        v4 = count;
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
        &this->ValueA,
        pos,
        count_a);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::CutHash(this, pos, v4, deleted);
    ValueHHighInd = this->ValueHHighInd;
    if ( ValueHHighInd )
      this->Length = ValueHHighInd + 1;
    else
      this->Length = this->ValueA.Data.Size;
  }
}
