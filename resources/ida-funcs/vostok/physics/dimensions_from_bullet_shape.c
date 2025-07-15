vostok::math::float3 *__usercall vostok::physics::dimensions_from_bullet_shape@<eax>(
        const btCollisionShape *bullet_shape@<ecx>,
        int a2@<esi>)
{
  float v2; // xmm0_4
  vostok::math::float3 *result; // eax
  float v4; // edx
  int m_shapeType; // eax
  __int64 dimensions; // [esp+0h] [ebp-Ch]

  switch ( byte_6BCC18[bullet_shape->m_shapeType] )
  {
    case 0:
      dimensions = *(_QWORD *)&bullet_shape[2].m_userPointer;
      v2 = -*(float *)&bullet_shape[3].m_shapeType;
      goto LABEL_6;
    case 1:
      *(_QWORD *)a2 = COERCE_UNSIGNED_INT(*(float *)&bullet_shape[2].m_userPointer * *(float *)&bullet_shape[1].m_shapeType);
      *(_DWORD *)(a2 + 8) = 0;
      result = (vostok::math::float3 *)a2;
      break;
    case 2:
      m_shapeType = bullet_shape[5].m_shapeType;
      LODWORD(dimensions) = *((_DWORD *)&bullet_shape[2].m_userPointer + m_shapeType);
      HIDWORD(dimensions) = *((_DWORD *)&bullet_shape[2].m_userPointer + (m_shapeType + 2) % 3);
      v2 = 0.0;
LABEL_6:
      *(_QWORD *)a2 = dimensions;
      *(float *)(a2 + 8) = v2;
      result = (vostok::math::float3 *)a2;
      break;
    case 3:
      v4 = -*(float *)&bullet_shape[3].m_shapeType;
      *(_QWORD *)a2 = *(_QWORD *)&bullet_shape[2].m_userPointer;
      *(float *)(a2 + 8) = v4;
      result = (vostok::math::float3 *)a2;
      break;
  }
  return result;
}
