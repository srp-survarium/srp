btTriangleShapeEx *__usercall btTriangleShapeEx::btTriangleShapeEx@<eax>(
        btTriangleShapeEx *this@<ecx>,
        btTriangleShapeEx *a2@<edi>)
{
  btTriangleShape::btTriangleShape(a2);
  a2->__vftable = (btTriangleShapeEx_vtbl *)&btTriangleShapeEx::`vftable';
  return a2;
}
