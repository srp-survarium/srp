btQuantizedBvh *__usercall btQuantizedBvh::btQuantizedBvh@<eax>(
        btQuantizedBvh *this@<ecx>,
        btQuantizedBvh *result@<eax>)
{
  result->__vftable = (btQuantizedBvh_vtbl *)&btQuantizedBvh::`vftable';
  result->m_bulletVersion = 279;
  result->m_useQuantization = 0;
  result->m_leafNodes.m_ownsMemory = 1;
  result->m_leafNodes.m_data = 0;
  result->m_leafNodes.m_size = 0;
  result->m_leafNodes.m_capacity = 0;
  result->m_contiguousNodes.m_ownsMemory = 1;
  result->m_contiguousNodes.m_data = 0;
  result->m_contiguousNodes.m_size = 0;
  result->m_contiguousNodes.m_capacity = 0;
  result->m_quantizedLeafNodes.m_ownsMemory = 1;
  result->m_quantizedLeafNodes.m_data = 0;
  result->m_quantizedLeafNodes.m_size = 0;
  result->m_quantizedLeafNodes.m_capacity = 0;
  result->m_quantizedContiguousNodes.m_ownsMemory = 1;
  result->m_quantizedContiguousNodes.m_data = 0;
  result->m_quantizedContiguousNodes.m_size = 0;
  result->m_quantizedContiguousNodes.m_capacity = 0;
  result->m_traversalMode = TRAVERSAL_STACKLESS;
  result->m_SubtreeHeaders.m_ownsMemory = 1;
  result->m_SubtreeHeaders.m_data = 0;
  result->m_SubtreeHeaders.m_size = 0;
  result->m_SubtreeHeaders.m_capacity = 0;
  result->m_subtreeHeaderCount = 0;
  result->m_bvhAabbMin.mVec128.m128_f32[0] = FLOAT_N3_4028235e38;
  result->m_bvhAabbMin.mVec128.m128_f32[1] = FLOAT_N3_4028235e38;
  result->m_bvhAabbMin.mVec128.m128_f32[2] = FLOAT_N3_4028235e38;
  result->m_bvhAabbMin.mVec128.m128_i32[3] = 0;
  result->m_bvhAabbMax.mVec128.m128_f32[0] = FLOAT_3_4028235e38;
  result->m_bvhAabbMax.mVec128.m128_f32[1] = FLOAT_3_4028235e38;
  result->m_bvhAabbMax.mVec128.m128_f32[2] = FLOAT_3_4028235e38;
  result->m_bvhAabbMax.mVec128.m128_i32[3] = 0;
  return result;
}
