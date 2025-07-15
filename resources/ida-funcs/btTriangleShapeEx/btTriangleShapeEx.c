btTriangleShapeEx *__usercall btTriangleShapeEx::btTriangleShapeEx@<eax>(
        btTriangleShapeEx *this@<ecx>,
        btTriangleShapeEx *a2@<esi>)
{
  btVector3 v3; // [esp+0h] [ebp-30h] BYREF
  btVector3 v4; // [esp+10h] [ebp-20h] BYREF
  _DWORD v5[4]; // [esp+20h] [ebp-10h] BYREF

  memset(&v3.m_floats[1], 0, 12);
  memset(&v4, 0, sizeof(v4));
  memset(v5, 0, sizeof(v5));
  btTriangleShape::btTriangleShape((btTriangleShape *)v5, a2, &v4, &v3, 0);
  a2->__vftable = (btTriangleShapeEx_vtbl *)&btTriangleShapeEx::`vftable';
  return a2;
}
