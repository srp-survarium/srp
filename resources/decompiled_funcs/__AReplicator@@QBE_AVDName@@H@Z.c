DName *__thiscall Replicator::operator[](Replicator *this, DName *result, unsigned int x)
{
  DName *v3; // eax

  if ( x > 9 )
  {
    DName::DName(result, DN_error);
  }
  else
  {
    if ( this->index != -1 && (signed int)x <= this->index )
    {
      v3 = result;
      *result = *this->dNameBuffer[x];
      return v3;
    }
    DName::DName(result, DN_invalid);
  }
  return result;
}
