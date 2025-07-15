unsigned int __thiscall Scaleform::MemItem::SumValues(Scaleform::MemItem *this, char *name)
{
  int v4; // ebx
  unsigned int i; // esi
  unsigned int v6; // eax

  if ( !strcmp((const char *)((this->Name.HeapTypeBits & 0xFFFFFFFC) + 8), name) )
    return this->Value;
  v4 = 0;
  for ( i = 0; i < this->Children.Data.Size; v4 += v6 )
    v6 = Scaleform::MemItem::SumValues(this->Children.Data.Data[i++].pObject, name);
  return v4;
}
