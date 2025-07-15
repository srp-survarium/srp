btAxisSweep3Internal<unsigned short> *__thiscall btAxisSweep3Internal<unsigned short>::`scalar deleting destructor'(
        btAxisSweep3Internal<unsigned short> *this,
        char a2)
{
  btAxisSweep3Internal<unsigned short>::~btAxisSweep3Internal<unsigned short>(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
