void __usercall btPoolAllocator::btPoolAllocator(
        btPoolAllocator *this@<esi>,
        int elemSize@<eax>,
        int maxElements@<ecx>)
{
  unsigned __int8 *v3; // ecx
  int m_maxElements; // eax
  int v5; // edx
  int m_elemSize; // eax

  this->m_elemSize = elemSize;
  this->m_maxElements = maxElements;
  v3 = (unsigned __int8 *)btAlignedAllocInternal(maxElements * elemSize);
  this->m_pool = v3;
  m_maxElements = this->m_maxElements;
  v5 = m_maxElements - 1;
  this->m_firstFree = v3;
  this->m_freeCount = m_maxElements;
  if ( m_maxElements != 1 )
  {
    m_elemSize = this->m_elemSize;
    do
    {
      *(_DWORD *)v3 = &v3[m_elemSize];
      m_elemSize = this->m_elemSize;
      v3 += this->m_elemSize;
      --v5;
    }
    while ( v5 );
  }
  *(_DWORD *)v3 = 0;
}
