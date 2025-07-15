char __thiscall btSingleSweepCallback::process(btSingleSweepCallback *this, const btBroadphaseProxy *proxy)
{
  _DWORD *m_clientObject; // edi
  unsigned __int64 v5; // [esp-18h] [ebp-28h]
  unsigned __int64 v6; // [esp-10h] [ebp-20h]
  unsigned __int64 v7; // [esp-8h] [ebp-18h]
  unsigned __int64 v8; // [esp+0h] [ebp-10h]

  if ( this->m_resultCallback->m_closestHitFraction == 0.0 )
    return 0;
  m_clientObject = proxy->m_clientObject;
  if ( this->m_resultCallback->needsCollision(
         this->m_resultCallback,
         (btBroadphaseProxy *)*((_DWORD *)proxy->m_clientObject + 50)) )
  {
    *((float *)&v8 + 1) = this->m_allowedCcdPenetration;
    LODWORD(v8) = this->m_resultCallback;
    HIDWORD(v7) = m_clientObject + 4;
    LODWORD(v7) = m_clientObject[51];
    HIDWORD(v6) = m_clientObject;
    LODWORD(v6) = &this->m_convexToTrans;
    HIDWORD(v5) = &this->m_convexFromTrans;
    LODWORD(v5) = this->m_castShape;
    btCollisionWorld::objectQuerySingle(v5, v6, v7, v8);
  }
  return 1;
}
