void __userpurge btAlignedObjectArray<btCompoundShapeChild>::swap(
        int index0@<eax>,
        int index1@<ecx>,
        btAlignedObjectArray<btCompoundShapeChild> *this)
{
  const btCompoundShapeChild *v4; // [esp+50h] [ebp-60h]
  const btCompoundShapeChild *v5; // [esp+50h] [ebp-60h]
  const btCompoundShapeChild *v6; // [esp+50h] [ebp-60h]
  btCompoundShapeChild v7; // [esp+60h] [ebp-50h] BYREF

  btCompoundShapeChild::btCompoundShapeChild(&this->m_data[index0], v4);
  btCompoundShapeChild::btCompoundShapeChild(&this->m_data[index1], v5);
  btCompoundShapeChild::btCompoundShapeChild(&v7, v6);
}
