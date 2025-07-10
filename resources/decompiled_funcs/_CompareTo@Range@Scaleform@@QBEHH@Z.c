unsigned int __thiscall Scaleform::Range::CompareTo(Scaleform::Range *this, int index)
{
  int v2; // eax

  v2 = this->Index;
  if ( index < this->Index )
    return v2 - index;
  if ( index <= (signed int)(this->Length + v2 - 1) )
    return 0;
  if ( index >= v2 )
    return this->Length - index + v2 - 1;
  else
    return v2 - index;
}
