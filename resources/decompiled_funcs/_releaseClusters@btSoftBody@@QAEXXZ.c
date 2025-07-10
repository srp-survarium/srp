void __usercall btSoftBody::releaseClusters(btSoftBody *this@<ecx>, btSoftBody::Cluster *a2@<esi>)
{
  while ( a2[2].m_com.mVec128.m128_i32[0] > 0 )
    btSoftBody::releaseCluster(this, a2);
}
