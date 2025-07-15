void __usercall btConvexInternalShape::setSafeMargin(btConvexInternalShape *this@<ecx>, int a2@<esi>)
{
  int m_shapeType; // xmm1_4
  int v3; // eax
  float v4; // [esp+4h] [ebp-4h]

  m_shapeType = this->m_shapeType;
  if ( *(float *)&m_shapeType <= *(float *)&this->__vftable )
  {
    v3 = 1;
    if ( *(float *)&this->m_userPointer > *(float *)&m_shapeType )
      goto LABEL_6;
  }
  else if ( *(float *)&this->m_userPointer > *(float *)&this->__vftable )
  {
    v3 = 0;
    goto LABEL_6;
  }
  v3 = 2;
LABEL_6:
  v4 = *((float *)&this->__vftable + v3) * 0.1;
  if ( ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)a2 + 40))(a2) > v4 )
    (*(void (__thiscall **)(int, float))(*(_DWORD *)a2 + 36))(a2, COERCE_FLOAT(LODWORD(v4)));
}
