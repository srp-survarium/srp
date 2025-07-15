int __thiscall Wm4::Query2<float>::ToTriangle(
        Wm4::Query2<float> *this,
        const Wm4::Vector2<float> *rkP,
        int iV0,
        int iV1,
        int iV2)
{
  int v6; // ebx
  int v8; // edi
  int v9; // eax

  v6 = this->ToLine(this, rkP, iV1, iV2);
  if ( v6 > 0 )
    return 1;
  v8 = this->ToLine(this, rkP, iV0, iV2);
  if ( v8 < 0 )
    return 1;
  v9 = this->ToLine(this, rkP, iV0, iV1);
  if ( v9 > 0 )
    return 1;
  if ( v6 && v8 && v9 )
    return -1;
  return 0;
}


int __thiscall Wm4::Query2<float>::ToTriangle(Wm4::Query2<float> *this, int i, int iV0, int iV1, int iV2)
{
  return ((int (__stdcall *)(const Wm4::Vector2<float> *, int, int, int))this->ToTriangle)(
           &this->m_akVertex[i],
           iV0,
           iV1,
           iV2);
}
