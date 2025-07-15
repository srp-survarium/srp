void __thiscall HeapManager::Destructor(HeapManager *this)
{
  HeapManager::Block *head; // eax
  HeapManager::Block *tail; // [esp-4h] [ebp-8h]

  if ( this->pOpDelete )
  {
    while ( 1 )
    {
      head = this->head;
      this->tail = head;
      if ( !head )
        break;
      tail = this->tail;
      this->head = tail->next;
      this->pOpDelete(tail);
    }
  }
}
