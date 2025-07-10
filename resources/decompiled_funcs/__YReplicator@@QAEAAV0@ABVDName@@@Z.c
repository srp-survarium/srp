Replicator *__thiscall Replicator::operator+=(Replicator *this, const DName *rd)
{
  DName *Memory; // eax

  if ( this->index != 9 && rd->node )
  {
    Memory = (DName *)HeapManager::getMemory(&heap, 8u, 0);
    if ( Memory )
      *Memory = *rd;
    else
      Memory = 0;
    if ( Memory )
      this->dNameBuffer[++this->index] = Memory;
  }
  return this;
}
