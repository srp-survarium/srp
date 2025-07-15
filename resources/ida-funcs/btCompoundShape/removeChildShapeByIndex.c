void __thiscall btCompoundShape::removeChildShapeByIndex(btCompoundShape *this, _DWORD *childShapeIndex, int a3)
{
  btDbvt *v3; // esi
  int v4; // edi
  btCompoundShapeChild v5; // [esp+10h] [ebp-50h] BYREF

  ++childShapeIndex[17];
  v3 = (btDbvt *)childShapeIndex[16];
  if ( v3 )
    btDbvt::remove(v3, *(btDbvtNode **)(80 * a3 + childShapeIndex[6] + 76));
  v4 = childShapeIndex[4] - 1;
  btCompoundShapeChild::btCompoundShapeChild((btCompoundShapeChild *)(80 * a3 + childShapeIndex[6]), &v5);
  v4 *= 80;
  btCompoundShapeChild::btCompoundShapeChild(
    (btCompoundShapeChild *)(childShapeIndex[6] + v4),
    (btCompoundShapeChild *)(80 * a3 + childShapeIndex[6]));
  btCompoundShapeChild::btCompoundShapeChild(&v5, (btCompoundShapeChild *)(v4 + childShapeIndex[6]));
  if ( childShapeIndex[16] )
    *(_DWORD *)(*(_DWORD *)(childShapeIndex[6] + 80 * a3 + 76) + 36) = a3;
  --childShapeIndex[4];
}
