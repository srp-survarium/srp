DName *__thiscall Replicator::operator[](Replicator *this, DName *result, int x)
{
  DName *v3; // eax

  if ( (unsigned int)x > 9 )
  {
    DName::DName(result, DN_error);
  }
  else
  {
    if ( this->index != -1 && x <= this->index )
    {
      v3 = result;
      *result = *this->dNameBuffer[x];
      return v3;
    }
    DName::DName(result, DN_invalid);
  }
  return result;
}


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
