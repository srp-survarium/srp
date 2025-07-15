Scaleform::MemItem *__thiscall Scaleform::MemItem::SearchForName(Scaleform::MemItem *this, char *name)
{
  Scaleform::MemItem *result; // eax
  int v4; // esi

  if ( !strcmp((const char *)((this->Name.HeapTypeBits & 0xFFFFFFFC) + 8), name) )
    return this;
  v4 = 0;
  if ( !this->Children.Data.Size )
    return 0;
  while ( 1 )
  {
    result = Scaleform::MemItem::SearchForName(this->Children.Data.Data[v4].pObject, name);
    if ( result )
      break;
    if ( ++v4 >= this->Children.Data.Size )
      return 0;
  }
  return result;
}
