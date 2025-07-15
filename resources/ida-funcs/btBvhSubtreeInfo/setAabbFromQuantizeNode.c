void __usercall btBvhSubtreeInfo::setAabbFromQuantizeNode(
        btBvhSubtreeInfo *this@<ecx>,
        const btQuantizedBvhNode *quantizedNode@<eax>)
{
  this->m_quantizedAabbMin[0] = quantizedNode->m_quantizedAabbMin[0];
  this->m_quantizedAabbMin[1] = quantizedNode->m_quantizedAabbMin[1];
  this->m_quantizedAabbMin[2] = quantizedNode->m_quantizedAabbMin[2];
  this->m_quantizedAabbMax[0] = quantizedNode->m_quantizedAabbMax[0];
  this->m_quantizedAabbMax[1] = quantizedNode->m_quantizedAabbMax[1];
  this->m_quantizedAabbMax[2] = quantizedNode->m_quantizedAabbMax[2];
}
