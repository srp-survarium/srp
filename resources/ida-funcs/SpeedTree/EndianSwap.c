unsigned int __cdecl SpeedTree::EndianSwap(SpeedTree *this)
{
  return ((unsigned __int8)this << 24)
       | (((unsigned __int16)this & 0xFF00) << 8)
       | ((unsigned int)this >> 8) & 0xFF00
       | ((unsigned int)this >> 24);
}


struct SpeedTree::Vec4 *__cdecl SpeedTree::EndianSwap(SpeedTree *this, struct SpeedTree::Vec4 *__return_ptr retstr)
{
  float v3; // [esp+14h] [ebp-1Ch]
  float v4; // [esp+20h] [ebp-10h]
  float v5; // [esp+2Ch] [ebp-4h]

  v5 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(retstr->w)));
  v4 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(retstr->z)));
  v3 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(retstr->y)));
  *(float *)this = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(retstr->x)));
  *((float *)this + 1) = v3;
  *((float *)this + 2) = v4;
  *((float *)this + 3) = v5;
  return (struct SpeedTree::Vec4 *)this;
}
