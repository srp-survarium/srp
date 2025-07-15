void __thiscall SpeedTree::CView::ComputeFrustumValues(SpeedTree::CView *this)
{
  ComputeFrustumPoints(this, this->m_avFrustumPoints);
  ExtractPlanes(&this->m_mComposite, this->m_avFrustumPlanes);
  ComputeFrustumAABB(this->m_avFrustumPoints, &this->m_cFrustumExtents);
}
