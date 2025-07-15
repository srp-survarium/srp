void __thiscall SpeedTree::CView::SetLodRefPoint(SpeedTree::CView *this, const struct SpeedTree::Vec3 *a2)
{
  this->m_vLodRefPoint = *a2;
  this->m_bLodRefPointSet = 1;
}
