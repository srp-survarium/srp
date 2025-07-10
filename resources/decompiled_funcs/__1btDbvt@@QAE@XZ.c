void __thiscall btDbvt::~btDbvt(btDbvt *this)
{
  btDbvt::sStkNN *m_data; // eax

  btDbvt::clear(this, this);
  m_data = this->m_stkStack.m_data;
  if ( m_data )
  {
    if ( this->m_stkStack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_stkStack.m_data = 0;
  }
  this->m_stkStack.m_data = 0;
  this->m_stkStack.m_size = 0;
  this->m_stkStack.m_capacity = 0;
  this->m_stkStack.m_ownsMemory = 1;
}
