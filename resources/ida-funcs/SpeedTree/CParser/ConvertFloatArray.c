void __thiscall SpeedTree::CParser::ConvertFloatArray(SpeedTree::CParser *this, float *a2, int a3)
{
  struct SpeedTree::Vec3 v4; // [esp+34h] [ebp-14h] BYREF
  int i; // [esp+40h] [ebp-8h]
  float *v6; // [esp+44h] [ebp-4h]

  v6 = a2;
  for ( i = 0; i < a3; ++i )
  {
    SpeedTree::CParser::ConvertCoord(this, &v4, *v6, v6[1], v6[2]);
    *(struct SpeedTree::Vec3 *)v6 = v4;
    v6 += 3;
  }
}
