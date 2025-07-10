unsigned int __cdecl SpeedTree::EndianSwap(SpeedTree *this)
{
  return ((unsigned __int8)this << 24)
       | (((unsigned __int16)this & 0xFF00) << 8)
       | ((unsigned int)this >> 8) & 0xFF00
       | ((unsigned int)this >> 24);
}
