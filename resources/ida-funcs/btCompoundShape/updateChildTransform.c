void __fastcall btCompoundShape::updateChildTransform(
        int childIndex,
        const btTransform *newChildTransform,
        btCompoundShape *this,
        bool shouldRecalculateLocalAabb)
{
  int v4; // ecx
  btCompoundShapeChild *v5; // eax
  btCollisionShape *m_childShape; // ecx
  btDbvt *m_dynamicAabbTree; // [esp-Ch] [ebp-5Ch]
  btDbvtNode *v8; // [esp-8h] [ebp-58h]
  int v9; // [esp+Ch] [ebp-44h]
  btVector3 v10; // [esp+10h] [ebp-40h] BYREF
  btVector3 v11; // [esp+20h] [ebp-30h] BYREF
  btVector3 v12; // [esp+30h] [ebp-20h] BYREF
  int v13; // [esp+40h] [ebp-10h]
  int v14; // [esp+44h] [ebp-Ch]
  int v15; // [esp+48h] [ebp-8h]
  int v16; // [esp+4Ch] [ebp-4h]

  v4 = childIndex;
  v5 = &this->m_children.m_data[v4];
  v5->m_transform = *newChildTransform;
  v9 = v4 * 80;
  if ( this->m_dynamicAabbTree )
  {
    m_childShape = this->m_children.m_data[v4].m_childShape;
    m_childShape->getAabb(m_childShape, newChildTransform, &v10, &v11);
    v12.mVec128 = v10.mVec128;
    v13 = v11.mVec128.m128_i32[0];
    v14 = v11.mVec128.m128_i32[1];
    v8 = *(btDbvtNode **)((char *)&this->m_children.m_data->m_node + v9);
    v15 = v11.mVec128.m128_i32[2];
    m_dynamicAabbTree = this->m_dynamicAabbTree;
    v16 = v11.mVec128.m128_i32[3];
    btDbvt::update((btDbvt *)v9, m_dynamicAabbTree, v8, &v12);
  }
  if ( shouldRecalculateLocalAabb )
    this->recalculateLocalAabb(this);
}
