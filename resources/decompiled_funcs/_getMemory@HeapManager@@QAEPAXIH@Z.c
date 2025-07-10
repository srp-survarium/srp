char *__thiscall HeapManager::getMemory(HeapManager *this, unsigned int sz, int noBuffer)
{
  unsigned int v3; // edi
  unsigned int blockLeft; // eax
  HeapManager::Block *Memory; // eax
  HeapManager::Block *tail; // ecx

  v3 = (sz + 7) & 0xFFFFFFF8;
  if ( noBuffer )
    return (char *)this->pOpNew((sz + 7) & 0xFFFFFFF8);
  if ( !v3 )
    v3 = 8;
  blockLeft = this->blockLeft;
  if ( blockLeft >= v3 )
  {
    this->blockLeft = blockLeft - v3;
  }
  else
  {
    if ( v3 > 0x1000 )
      return 0;
    Memory = (HeapManager::Block *)HeapManager::getMemory(&heap, 0x1004u, 1);
    if ( Memory )
      Memory->next = 0;
    else
      Memory = 0;
    if ( !Memory )
      return 0;
    tail = this->tail;
    if ( tail )
      tail->next = Memory;
    else
      this->head = Memory;
    this->tail = Memory;
    this->blockLeft = 4096 - v3;
  }
  return &this->tail->memBlock[this->blockLeft];
}
