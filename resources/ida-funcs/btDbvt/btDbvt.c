btDbvt *__thiscall btDbvt::btDbvt(btDbvt *this)
{
  btDbvt *result; // eax

  result = this;
  this->m_stkStack.m_ownsMemory = 1;
  this->m_stkStack.m_data = 0;
  this->m_stkStack.m_size = 0;
  this->m_stkStack.m_capacity = 0;
  this->m_root = 0;
  this->m_free = 0;
  this->m_lkhd = -1;
  this->m_leaves = 0;
  this->m_opath = 0;
  return result;
}
