int __thiscall Wm4::Query2<float>::ToTriangle(
        Wm4::Query2<float> *this,
        const Wm4::Vector2<float> *rkP,
        int iV0,
        int iV1,
        int iV2)
{
  int v8; // ebp
  int v9; // eax
  int iSign0; // [esp+24h] [ebp+10h]

  iSign0 = this->ToLine(this, rkP, iV1, iV2);
  if ( iSign0 > 0 )
    return 1;
  v8 = this->ToLine(this, rkP, iV0, iV2);
  if ( v8 < 0 )
    return 1;
  v9 = this->ToLine(this, rkP, iV0, iV1);
  if ( v9 > 0 )
    return 1;
  if ( iSign0 && v8 && v9 )
    return -1;
  return 0;
}
