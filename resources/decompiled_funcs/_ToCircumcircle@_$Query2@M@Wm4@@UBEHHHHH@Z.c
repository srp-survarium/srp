int __thiscall Wm4::Query2<float>::ToCircumcircle(Wm4::Query2<float> *this, int i, int iV0, int iV1, int iV2)
{
  return ((int (__stdcall *)(const Wm4::Vector2<float> *, int, int, int))this->ToCircumcircle)(
           &this->m_akVertex[i],
           iV0,
           iV1,
           iV2);
}
