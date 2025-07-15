unsigned int __thiscall Scaleform::MemItem::GetMaxId(Scaleform::MemItem *this)
{
  unsigned int ID; // ebx
  unsigned int i; // edi
  unsigned int MaxId; // eax

  ID = this->ID;
  for ( i = 0; i < this->Children.Data.Size; ++i )
  {
    MaxId = Scaleform::MemItem::GetMaxId(this->Children.Data.Data[i].pObject);
    if ( MaxId >= ID )
      ID = MaxId;
  }
  return ID;
}
