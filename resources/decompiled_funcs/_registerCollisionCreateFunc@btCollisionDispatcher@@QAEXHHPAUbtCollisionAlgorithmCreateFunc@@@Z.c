void __userpurge btCollisionDispatcher::registerCollisionCreateFunc(
        int proxyType0@<eax>,
        int proxyType1@<ecx>,
        btCollisionDispatcher *this,
        btCollisionAlgorithmCreateFunc *createFunc)
{
  this->m_doubleDispatch[proxyType0][proxyType1] = &s_gimpact_cf;
}
