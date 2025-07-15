double __thiscall vostok::physics::bt_closest_convex_not_me_result_callback::addSingleResult(
        vostok::physics::bt_closest_convex_not_me_result_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  if ( convexResult->m_hitCollisionObject == this->m_self )
    return 1.0;
  else
    return btCollisionWorld::ClosestConvexResultCallback::addSingleResult(this, convexResult, normalInWorldSpace);
}
