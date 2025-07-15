void __thiscall btCompoundShape::addChildShape(
        btCompoundShape *this,
        const btTransform *localTransform,
        const btTransform *shape,
        btCollisionShape *a4)
{
  btCollisionShape_vtbl *v4; // eax
  double v5; // st7
  btCollisionShape_vtbl *v6; // eax
  btVector3 *p_m_origin; // eax
  int i; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  btDbvt *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  btCompoundShapeChild *v15; // esi
  btCompoundShapeChild *v16; // eax
  int v17; // [esp-4h] [ebp-B4h]
  int v18; // [esp+14h] [ebp-9Ch]
  btCompoundShapeChild *v19; // [esp+18h] [ebp-98h]
  int v20; // [esp+1Ch] [ebp-94h]
  btVector3 v21; // [esp+20h] [ebp-90h] BYREF
  btVector3 v22; // [esp+30h] [ebp-80h] BYREF
  btCompoundShapeChild v23; // [esp+40h] [ebp-70h] BYREF
  btVector3 data[2]; // [esp+90h] [ebp-20h] BYREF

  v23.m_node = 0;
  ++localTransform[1].m_basis.m_el[0].mVec128.m128_i32[1];
  v23.m_transform = *shape;
  v23.m_childShapeType = a4->m_shapeType;
  v4 = a4->__vftable;
  v23.m_childShape = a4;
  v5 = ((double (__thiscall *)(btCollisionShape *))v4->getMargin)(a4);
  v6 = a4->__vftable;
  v23.m_childMargin = v5;
  v6->getAabb(a4, shape, &v21, &v22);
  p_m_origin = &localTransform->m_origin;
  for ( i = 0; i < 3; ++i )
  {
    v9 = v21.mVec128.m128_f32[i];
    if ( p_m_origin[-1].mVec128.m128_f32[0] > v9 )
      p_m_origin[-1].mVec128.m128_f32[0] = v9;
    v10 = v22.mVec128.m128_f32[i];
    if ( v10 > p_m_origin->mVec128.m128_f32[0] )
      p_m_origin->mVec128.m128_f32[0] = v10;
    p_m_origin = (btVector3 *)((char *)p_m_origin + 4);
  }
  v11 = (btDbvt *)localTransform[1].m_basis.m_el[0].mVec128.m128_i32[0];
  if ( v11 )
  {
    v17 = localTransform->m_basis.m_el[1].mVec128.m128_i32[0];
    data[0] = (btVector3)v21.mVec128;
    data[1] = (btVector3)v22.mVec128;
    v23.m_node = btDbvt::insert((btDbvt *)data, v11, data, v17);
  }
  v12 = localTransform->m_basis.m_el[1].mVec128.m128_i32[1];
  v13 = localTransform->m_basis.m_el[1].mVec128.m128_i32[0];
  if ( v13 == v12 )
  {
    v14 = 0;
    v18 = v13 ? 2 * v13 : 1;
    if ( v12 < v18 )
    {
      if ( v18 )
        v19 = (btCompoundShapeChild *)btAlignedAllocInternal(80 * v18);
      else
        v19 = 0;
      if ( localTransform->m_basis.m_el[1].mVec128.m128_i32[0] > 0 )
      {
        v15 = v19;
        v20 = localTransform->m_basis.m_el[1].mVec128.m128_i32[0];
        do
        {
          if ( v15 )
            btCompoundShapeChild::btCompoundShapeChild(
              (btCompoundShapeChild *)(v14 + localTransform->m_basis.m_el[1].mVec128.m128_i32[2]),
              v15);
          v14 += 80;
          ++v15;
          --v20;
        }
        while ( v20 );
      }
      if ( localTransform->m_basis.m_el[1].mVec128.m128_i32[2] )
      {
        if ( localTransform->m_basis.m_el[1].mVec128.m128_i8[12] )
          btAlignedFreeInternal((void *)localTransform->m_basis.m_el[1].mVec128.m128_i32[2]);
        localTransform->m_basis.m_el[1].mVec128.m128_i32[2] = 0;
      }
      localTransform->m_basis.m_el[1].mVec128.m128_i32[2] = (int)v19;
      localTransform->m_basis.m_el[1].mVec128.m128_i8[12] = 1;
      localTransform->m_basis.m_el[1].mVec128.m128_i32[1] = v18;
    }
  }
  v16 = (btCompoundShapeChild *)(localTransform->m_basis.m_el[1].mVec128.m128_i32[2]
                               + 80 * localTransform->m_basis.m_el[1].mVec128.m128_i32[0]);
  if ( v16 )
    btCompoundShapeChild::btCompoundShapeChild(&v23, v16);
  ++localTransform->m_basis.m_el[1].mVec128.m128_i32[0];
}
