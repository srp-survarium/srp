bool __thiscall SpeedTree::CInstance::operator==(float *this, int a2)
{
  bool v4; // [esp+4h] [ebp-8h]

  v4 = *(float *)a2 == *this && *(float *)(a2 + 4) == this[1] && *(float *)(a2 + 8) == this[2];
  return v4 && *(float *)(a2 + 12) == this[3] && *((unsigned __int8 *)this + 34) == *(unsigned __int8 *)(a2 + 34);
}
