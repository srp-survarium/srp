void __userpurge vostok::render::speedtree_forest::cull_and_compute_lod(
        vostok::render::renderer_context *context@<eax>,
        const vostok::math::float3 *lod_reference_point@<edi>,
        vostok::render::speedtree_forest *this,
        bool sort_result)
{
  unsigned __int8 *fixed; // ebp
  struct SpeedTree::Vec3 v6; // [esp+14h] [ebp-D4h] BYREF
  float x; // [esp+20h] [ebp-C8h]
  float y; // [esp+24h] [ebp-C4h]
  struct SpeedTree::Mat4x4 dst; // [esp+28h] [ebp-C0h] BYREF
  struct SpeedTree::Mat4x4 lhs; // [esp+68h] [ebp-80h] BYREF
  _BYTE v11[64]; // [esp+A8h] [ebp-40h] BYREF

  y = context->m_near_far_invn_invf.y;
  x = context->m_near_far_invn_invf.x;
  fixed = (unsigned __int8 *)vostok::render::fix_view_matrix(&context->m_v, (int)v11);
  memset((int)&dst, 0, sizeof(dst));
  LODWORD(dst.m_afSingle[15]) = clear_value;
  LODWORD(dst.m_afSingle[10]) = clear_value;
  LODWORD(dst.m_afSingle[5]) = clear_value;
  LODWORD(dst.m_afSingle[0]) = clear_value;
  memcpy((unsigned __int8 *)&dst, fixed, sizeof(dst));
  memcpy((unsigned __int8 *)&lhs, (unsigned __int8 *)&context->m_p, sizeof(lhs));
  v6.x = context->m_v_inverted.c.x;
  v6.y = context->m_v_inverted.c.y;
  v6.z = context->m_v_inverted.c.z;
  SpeedTree::CView::Set(&this->m_view, &v6, &lhs, &dst, x, y);
  v6 = (struct SpeedTree::Vec3)*lod_reference_point;
  SpeedTree::CView::SetLodRefPoint(&this->m_view, &v6);
  this->m_forest->CullAndComputeLOD(this->m_forest, &this->m_view, &this->m_visible_trees, 1);
}
