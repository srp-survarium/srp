unsigned int __thiscall Scaleform::MemItem::GetValue(Scaleform::MemItem *this, char *name)
{
  unsigned int result; // eax
  int v4; // esi

  if ( !strcmp((const char *)((this->Name.HeapTypeBits & 0xFFFFFFFC) + 8), name) )
    return this->Value;
  v4 = 0;
  if ( !this->Children.Data.Size )
    return 0;
  while ( 1 )
  {
    result = Scaleform::MemItem::GetValue(this->Children.Data.Data[v4].pObject, name);
    if ( result )
      break;
    if ( ++v4 >= this->Children.Data.Size )
      return 0;
  }
  return result;
}
