void __thiscall btCollisionWorld::objectQuerySingle_::_46_::LocalInfoAdder::addSingleResult(
        btCollisionWorld::objectQuerySingle::__l46::LocalInfoAdder *this,
        btCollisionWorld::LocalConvexResult *r,
        BOOL b)
{
  bool v4; // zf
  _DWORD v5[2]; // [esp+4h] [ebp-Ch] BYREF
  char v6; // [esp+Ch] [ebp-4h]

  v5[0] = -1;
  v5[1] = this->m_i;
  v4 = r->m_localShapeInfo == 0;
  v6 = 1;
  if ( v4 )
    r->m_localShapeInfo = (btCollisionWorld::LocalShapeInfo *)v5;
  this->m_userCallback->addSingleResult(this->m_userCallback, r, b);
  this->m_closestHitFraction = this->m_userCallback->m_closestHitFraction;
}
