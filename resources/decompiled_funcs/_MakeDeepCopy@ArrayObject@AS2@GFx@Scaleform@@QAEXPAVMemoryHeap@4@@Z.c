void __thiscall Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::MemoryHeap *pheap)
{
  unsigned int Size; // eax
  unsigned int v4; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  unsigned int n; // [esp+8h] [ebp-4h]

  Size = this->Elements.Data.Size;
  v4 = 0;
  for ( n = Size; v4 < Size; ++v4 )
  {
    if ( this->Elements.Data.Data[v4] )
    {
      v5 = (Scaleform::GFx::AS2::Value *)pheap->Alloc(pheap, 16, 0);
      if ( v5 )
        Scaleform::GFx::AS2::Value::Value(v5, this->Elements.Data.Data[v4]);
      else
        v6 = 0;
      this->Elements.Data.Data[v4] = v6;
      Size = n;
    }
  }
}
